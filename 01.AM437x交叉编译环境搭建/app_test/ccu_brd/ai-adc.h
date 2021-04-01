#ifndef _AI_ADC_H_
#define _AI_ADC_H_

#define  ADC_PATH "/sys/devices/platform/44000000.ocp/4802a000.i2c/i2c-1/1-0048/"


// 初始化所有ADC通道号
int init_all_adc_channel();

// 获取4路AI通道的输入值
int get_adc_input();

// 关闭所有打开的ADC通道
int uninit_all_adc_channel();

#endif

