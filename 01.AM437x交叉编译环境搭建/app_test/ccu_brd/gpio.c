#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>


#include "gpio.h"



void init_gpio(int pin, int offset, int direction)
{
    char str[256];
    int gpio = pin * 32 + offset;

    memset(str, 0, sizeof(str));
    sprintf(str, "echo %d > /sys/class/gpio/export", gpio);
    system(str);
    //printf("%s\n", str);

    memset(str, 0, sizeof(str));

    if (direction == 0)
    {
        sprintf(str, "echo \"in\" > /sys/class/gpio/gpio%d/direction", gpio);
    }
    else
    {
        sprintf(str, "echo \"out\" > /sys/class/gpio/gpio%d/direction", gpio);
    }
    system(str);

    //printf("%s\n", str);
}

void uninit_gpio(int pin, int offset)
{
    char str[256];
    int gpio = pin * 32 + offset;

    memset(str, 0, sizeof(str));
    sprintf(str, "echo %d > /sys/class/gpio/unexport", gpio);
    system(str);

    //printf("%s\n", str);
}


void set_gpio_value(int pin, int offset, int value)
{
    char str[256];
    int gpio = pin * 32 + offset;

    memset(str, 0, sizeof(str));
    sprintf(str, "echo %d > /sys/class/gpio/gpio%d/value", value, gpio);
    system(str);
}


int get_gpio_value(int pin, int offset)
{
    FILE *pf;
    char buffer[20];
    char str[256];
    int gpio = pin * 32 + offset;

    memset(str, 0, sizeof(str));
    sprintf(str, "cat /sys/class/gpio/gpio%d/value", gpio);
    //printf("%s\n", str);

    pf = popen(str, "r");
    fread(buffer, sizeof(buffer), 1, pf);
    //printf("%s\n", buffer);
    pclose(pf);

    if (buffer[0] == '0')
    {
        //printf("return 0\n");
        return 0;
    }
    else
    {
        //printf("return 1\n");
        return 1;
    }
}

/*4路DO全部输出为value,2路干节点输出为value*/
int gpio_out_put_high(int value)
{
	// DO1
	set_gpio_value(4, 5, value);
	printf("DO1 = %d\n", value); 

	// DO2
	set_gpio_value(5, 20, value);
	printf("DO2 = %d\n", value); 

	// DO3
	set_gpio_value(4, 6, value);
	printf("DO3 = %d\n", value); 	

	// DO4
	set_gpio_value(4, 24, value);
	printf("DO4 = %d\n", value); 
	

	// 2路干接点（继电器）输出
	// 继电器1
	set_gpio_value(4, 2, value);
	printf("Relay1 = %d\n", value); 

	// 继电器2
	set_gpio_value(4, 25, value);
	printf("Relay2 = %d\n", value); 
	
	return 0;
}


/*读取4路DI的输入值*/
int gpio_get_input()
{
	int value;
	
	// DI1
	value = get_gpio_value(4, 27);
	printf("DI1 = %d\n", value); 
	
	// DI2
	value = get_gpio_value(4, 0);
	printf("DI2 = %d\n", value); 
	
	// DI3
	value = get_gpio_value(4, 28);
	printf("DI3 = %d\n", value); 
	
	// DI4
	value = get_gpio_value(4, 1);
	printf("DI4 = %d\n", value); 
	
	return 0;
}




int init_all_gpio()
{
	// 4路数字量输出DO
	// DO1
	init_gpio(4, 5, 1);

	// DO2
	init_gpio(5, 20, 1);

	// DO3
	init_gpio(4, 6, 1);

	// DO4
	init_gpio(4, 24, 1);

	// 2路干接点（继电器）输出
	// 继电器1
	init_gpio(4, 2, 1);

	// 继电器1
	init_gpio(4, 25, 1);

	// 四路数字量输入DI
	// DI1
	init_gpio(4, 27, 0);

	// DI2
	init_gpio(4, 0, 0);

	// DI3
	init_gpio(4, 28, 0);

	// DI4
	init_gpio(4, 1, 0);
}


