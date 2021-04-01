#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <string.h>

#include "ai-adc.h"

static int fd_channel1, fd_channel2, fd_channel3, fd_channel4;

/**
*
*channel 通道Id，通道ID为1~4
*
**/
int init_adc(int channel)
{
	int fd;
	char adc_str[250];
	
	memset(adc_str, 0, sizeof(adc_str));
	sprintf(adc_str,"%s/in%d_input", ADC_PATH, channel + 3);
	fd = open(adc_str, O_RDONLY);

	return fd;
}


int get_adc(int fd)
{
    int ret = -1;
    char adc_str[64]  = {0};
    int adc_value = 0;

    lseek(fd, 0, SEEK_SET);
    ret = read(fd, adc_str, sizeof(adc_str));
	
    if (ret <= 0)
    {
        printf("read adc failed!\n");
        return -1;
    }
    else
    {
        /* remove the ending '\n' charactor */
        strtok(adc_str, "\n\r");
        adc_value = atoi(adc_str);
    }

	//printf("adc_value = %d\n", adc_value);

    return adc_value;
}



/**
*
*初始化所有ADC通道号
*
**/
int init_all_adc_channel()
{
	fd_channel1 = init_adc(1);
	fd_channel2 = init_adc(2);
	fd_channel3 = init_adc(3);
	fd_channel4 = init_adc(4);

	return 0;
}

/**
*
*获取4路AI通道的输入值
*
**/
int get_adc_input()
{
	int value;
	float calc_value;
	
	value = get_adc(fd_channel1);
	calc_value = value  * 8.064;
	printf("AI1 = %d/%.4f\n", value, calc_value); 

	value = get_adc(fd_channel2);
	calc_value = value  * 8.064;
	printf("AI2 = %d/%.4f\n", value, calc_value); 

	value = get_adc(fd_channel3);
	calc_value = value  * 8.064;
	printf("AI3 = %d/%.4f\n", value, calc_value); 

	value = get_adc(fd_channel4);
	calc_value = value  * 8.064;
	printf("AI4 = %d/%.4f\n", value, calc_value); 

	return 0;
}



/**
*
*关闭所有打开的ADC通道
*
**/
int uninit_all_adc_channel()
{
	close(fd_channel1);
	close(fd_channel2);
	close(fd_channel3);
	close(fd_channel4);

	return 0;
}




