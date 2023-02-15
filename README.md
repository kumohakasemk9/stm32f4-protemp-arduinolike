STM32F4XX Arduino like template project
=====   
This is STM32F4XX project template files to get experience like arduino coding.   

How to use
=====
First you need some missing files. stm32f4xx.h and CMSIS. After downloading,   
Please modify makefile for correct include path.  
You have to make include path pointing correct dir to CMSIS includes and stm32f4xx.h.  
And please modify stm32f4xx.h or add preprocessor (-Dxxx) for   
make stm32f4xx.h know target device type.   
And program in main.c and pls make. You will get   
1. output - final binary output
2. output.srec - Srecord final binary output
3. report - Disassembly and section info
   
You can pass output.srec to your STM32 programmer. This will write your program to target ROM.   
You can also use output, please use arm-none-eabi-gdb to load it to your target board.
report will contain some useful info. You can watch disassembly and see what's going on   
in case of your program not responding.   

License
=====
You are free to destribute, modify without modifying this section.
Please consider support me on kofi.com https://ko-fi.com/kumohakase
Licensed under Creative commons CC-BY https://creativecommons.org/licenses/by/4.0/
