#include <stdio.h>
#include <linux/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

#include "ao-dac.h"

/**
*设定各个通道的模拟量电流输出
*
* channel AO的通道号，值为1——4
* current_value 对应通道输出的模拟量电流，单位为mA
*
**/
unsigned int set_ao_value(unsigned int channel, float current_value)
{
	float value;
    unsigned int attr_value = 0;
	unsigned int data;
	char str[256];

	value = 1000 * (current_value - 4) / 3.907;
	data = (unsigned int)value;

	if (data == 4096)
	{
		data--;
	}
	
	data = data & 0xfff;
		
    memset(str, 0, sizeof(str));

	// A1, A0, Address Select
	attr_value = attr_value | (0 << 23) | (0 << 22);

	// LD1, LD0, Write to buffer with data and load DAC
	attr_value = attr_value | (1 << 21) | (0 << 20);

	// set to 0
	attr_value = attr_value | (0 << 19);

	// DAC Sel1, DAC Sel0, channel select, should be (00, 01, 10, or 11)
	attr_value = attr_value | ((channel - 1) << 17);

	// PD0, power-down command
	attr_value = attr_value | (0 << 16);

	// Data, 12 bit
	attr_value = attr_value | (data << 4);

    sprintf(str, "echo %d > %s", attr_value, CCU_BRD_AO_DAC);
	//printf("%s\n", str);
	
    system(str);

	return data;
}


/**
*设定4路通道的模拟量电流输出
*
* current_value 对应通道输出的模拟量电流，单位为mA
*
*/
int set_ao_out_put(float current_value)
{
	unsigned int data;
	float current_tmp = current_value * 1000.0;

	data = set_ao_value(1, current_value);
	printf("AO1 = %d/%.4f\n", data, current_tmp); 
	
	data = set_ao_value(2, current_value);
	printf("AO2 = %d/%.4f\n", data, current_tmp); 
	
	data = set_ao_value(3, current_value);
	printf("AO3 = %d/%.4f\n", data, current_tmp); 
	
	data = set_ao_value(4, current_value);
	printf("AO4 = %d/%.4f\n", data, current_tmp);
	
	return 0;
}



