#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

#include "led.h"


void led_light_off(int value, int ledn)
{
    char tmp[64];

    sprintf(tmp,"echo %d > /sys/class/leds/myd_0%d/brightness",value, ledn);
    printf("status led%d  = % d\n",ledn, value);
    system(tmp);
}

