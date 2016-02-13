/*
 * ddc-brith is a simple ddccontrol powered app to control brightness
 * Copyright © 2016 Eugene Mihailenco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include <ddcci.h>
#include <monitor_db.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <string.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFLEN 1
#define PORT 9930


void diep(const char* s)
{
    perror(s);
    exit(1);
}

int main(int argc, char** argv)
{


    if (argc == 2)  // if called with parameter => write to fifo
    {
        fprintf(stdout, "Writing brightness %s", argv[1]);
        /* TODO: send udp */
        exit(EXIT_SUCCESS);
    }

    // daemon will listen on PORT
    fprintf(stdout, "Running daemon mode...\n");


    int ret;

    // filedescriptor and name of device
    struct monitor mon;
    char* fn;

    char* datadir = NULL;

    int verbosity = 0;

    // Setting brightness register
    int ctrl  = 0x10;

    ddcci_verbosity(verbosity);

    if (!ddcci_init(datadir))
    {
        printf("Unable to initialize ddcci library.\n");
        exit(EXIT_FAILURE);
    }

    fn = "dev:/dev/i2c-6";

    printf("Reading EDID and initializing DDC/CI at bus %s...\n", fn);

    if ((ret = ddcci_open(&mon, fn, 0)) < 0)
    {
        printf("\nDDC/CI at %s is unusable (%d).\n"
               "If your graphics card need it, please check all the "
               "required kernel modules are loaded (i2c-dev, and your "
               "framebuffer driver).\n",
               fn,
               ret);
    }
    else
    {
        printf("\nEDID readings:\n");
        printf("\tPlug and Play ID: %s [%s]\n", mon.pnpid, mon.db ? mon.db->name : NULL);
        printf("\tInput type: %s\n", mon.digital ? "Digital" : "Analog");

        // Starting server
        int s;  // Socket

        // Loop
        if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) != -1)
        {
            struct sockaddr_in si_me, si_other;
            int slen = sizeof(si_other);
            char buf[BUFLEN];

            memset((char*) &si_me, 0, sizeof(si_me));
            si_me.sin_family      = AF_INET;
            si_me.sin_port        = htons(PORT);
            si_me.sin_addr.s_addr = htonl(INADDR_ANY);

            if (bind(s, &si_me, sizeof(si_me)) != -1)
            {
                while (1)
                {
                    if (recvfrom(s, buf, BUFLEN, 0, &si_other, &slen) == -1)
                    {
                        fprintf(stderr, "Failed creating udp socket");
                        break;
                    }
                    else
                    {
                        unsigned char x = buf[0];
                        printf("Received char %x = %c \n", x, x);
                        if (x < 100)
                            ddcci_writectrl(&mon, ctrl, x, -1);
                    }
                }
            }

            close(s);
        }
        else
        {
            fprintf(stderr, "Failed creating udp socket");
        }
    }


    ddcci_close(&mon);
    ddcci_release();

    exit(EXIT_SUCCESS);
}
