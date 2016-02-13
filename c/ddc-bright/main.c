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
#include <fcntl.h>
#include <string.h>

const char* myfifo = "/tmp/myfifo-bright";

int main(int argc, char** argv)
{


    if (argc == 2)  // if called with parameter => write to fifo
    {
        printf("Writing brightness %s", argv[1]);
        int fd = open(myfifo, O_WRONLY);
        write(fd, "Hi", sizeof("Hi"));
        close(fd);
        exit(EXIT_SUCCESS);
    }
    else
    {
        fprintf(stdout, "Running daemon mode\n");
    }

    // create the FIFO (named pipe)
    mkfifo(myfifo, 0666);
    int fd = open(myfifo, O_RDONLY);
    char buf[1];

    while (read(fd, buf, 1) == 1) // while there is character
    {
        printf("%x\n", buf[0]);
    }

    printf("Exiting\n");
    unlink(myfifo);
    exit(0);



    int ret;

    // filedescriptor and name of device
    struct monitor mon;
    char* fn;

    char* datadir = NULL;

    int verbosity = 0;

    // Setting brightness register
    int ctrl  = 0x10;
    int value = atoi(argv[1]);

    printf("Setting %d to %d value\n", ctrl, value);

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

        /*FILE* stream;
        int c;
        stream = fdopen(file, "r");

        while ((value = fgetc(stream)) != EOF)
        {
            if (value >= 0)
            {
                // no delay!
                ddcci_writectrl(&mon, ctrl, value, -1);
            }
        }*/
    }

    // free FIFO
    unlink(myfifo);

    ddcci_close(&mon);
    ddcci_release();

    exit(EXIT_SUCCESS);
}
