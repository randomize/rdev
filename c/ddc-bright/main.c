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


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage ddc-bright value\n");
        exit(1);
    }

    pid_t pid;

    /* Fork off the parent process */       
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
       we can exit the parent process. */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

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
        exit(1);
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

        if (value >= 0)
        {
            // no delay!
            ddcci_writectrl(&mon, ctrl, value, -1);
        }
    }

    ddcci_close(&mon);
    ddcci_release();

    exit(0);
}
