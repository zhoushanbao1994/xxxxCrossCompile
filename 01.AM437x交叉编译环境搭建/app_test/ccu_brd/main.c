#include <sys/time.h>
#include <sys/select.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "gpio.h"
#include "ai-adc.h"
#include "ao-dac.h"
#include "led.h"

#define msleep(n) usleep(n*1000)

int main()
{
	time_t now; //实例化time_t结构    
	struct tm *timenow; //实例化tm结构指针  
	struct timeval temp;
	unsigned int count = 0;
	
	temp.tv_sec = 4;
	temp.tv_usec = 0;

	init_all_gpio();
	init_all_adc_channel();

	printf("\n");

	while (1)
	{
		temp.tv_sec = 4;
		temp.tv_usec = 0;
		select(0, NULL, NULL, NULL, &temp);
		printf("timer trigged count = %d\n", count);

		//time函数读取现在的时间(国际标准时间非北京时间)，然后传值给now    
		now = time(NULL);

		//localtime函数把从time取得的时间now换算成你电脑中的时间(就是你设置的地区)  
		timenow =localtime(&now);

		//上句中asctime函数把时间转换成字符，通过printf()函数输出 
		printf("RTC output time: %s",asctime(timenow)); 

		if (count % 2 == 0)
		{
			// red myd_01, light on
			led_light_off(1, 1);

			// green myd_02, light off
			led_light_off(0, 2);
			
			// 4路DO全部输出为高,2路干节点输出为高
			gpio_out_put_high(OUT_PUT_HIGH);

			// 设定4路通道的模拟量电流输出为5mA
			set_ao_out_put(5.0);

			// 等待0.5S
			msleep(500);

			now = time(NULL);
			timenow =localtime(&now);
			printf("\n");
			printf("RTC input time: %s",asctime(timenow)); 
			
			// 读取4路DI的输入值
			gpio_get_input();

			// 获取4路AI通道的输入值
			get_adc_input();

			printf("\n");
			printf("\n");
		}
		else
		{
			// red myd_01, light off
			led_light_off(0, 1);

			// green myd_02, light on
			led_light_off(1, 2);
			
			// 4路DO全部输出为低,2路干节点输出为低
			gpio_out_put_high(OUT_PUT_LOW);

			// 设定4路通道的模拟量电流输出为20mA
			set_ao_out_put(20.0);

			// 等待0.5S
			msleep(500);

			now = time(NULL);
			timenow =localtime(&now);
			printf("\n");
			printf("RTC input time: %s",asctime(timenow)); 
			
			// 读取4路DI的输入值
			gpio_get_input();

			// 获取4路AI通道的输入值
			get_adc_input();

			printf("\n");
			printf("\n");
		}	

		count++;
	}

	uninit_all_adc_channel();

	return 0;
}
