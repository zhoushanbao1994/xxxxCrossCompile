TARGET = $(notdir $(CURDIR))
#CC=$(CROSS_COMPILE)gcc
CC=/opt/am4372/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi-gcc
objs := $(patsubst %c, %o, $(shell ls *.c))
$(TARGET)_test:$(objs)
	$(CC) -o $@ $^ -lpthread 
%.o:%.c
	$(CC) -c -o $@ $<
clean:
	rm -f  $(TARGET)_test *.all *.o
