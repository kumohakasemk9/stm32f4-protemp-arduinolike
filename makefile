#	STM32F4XX Arduino-like Project Template
#	Makefile
#	(C) 2023 Kumohakase
#	You are free to destribute, modify without modifying this section.
#	Please consider support me on kofi.com https://ko-fi.com/kumohakase


CXX = arm-none-eabi-g++
CPPFLAGS = -fno-exceptions -mcpu=cortex-m4 -mfpu=vfpv4-d16 -g3 -I /home/owner/harddisk_home/programs/CMSIS_5-5.7.0/CMSIS/Core/Include -I /home/owner/harddisk_home/programs/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include #You need to make CMSIS path and STM32 header dir pointing correct one.
OBJS = main.o start.o
TARGET = output

all: $(OBJS)
	$(CXX) -mcpu=cortex-m4 -mfpu=vfpv4-d16 -T flash.ld -nostartfiles $^ -o $(TARGET)
	arm-none-eabi-objcopy -O srec $(TARGET) $(TARGET).srec
	arm-none-eabi-objdump $(TARGET) -hdS > report
	arm-none-eabi-objdump $(TARGET) -h

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).srec
