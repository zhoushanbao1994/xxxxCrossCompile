#ifndef _AO_DAC_H_
#define _AO_DAC_H_

#define CCU_BRD_AO_DAC "/sys/devices/platform/44000000.ocp/481a2000.spi/spi_master/spi1/spi1.0/ccu_brd/value"


/**
*设定4路通道的模拟量电流输出
*
* current_value 对应通道输出的模拟量电流，单位为mA
*
*/
int set_ao_out_put(float current_value);



#endif
