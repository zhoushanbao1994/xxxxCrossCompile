#ifndef _GPIO_H_
#define _GPIO_H_

#define OUT_PUT_HIGH 1
#define OUT_PUT_LOW 0


int init_all_gpio();

/*4路DO全部输出为高,2路干节点输出为value*/
int gpio_out_put_high(int value);


/*读取4路DI的输入值*/
int gpio_get_input();


#endif

