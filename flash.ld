/*
	STM32F4XX Arduino-like Project Template
	Linker script
	(C) 2023 Kumohakase
	You are free to destribute, modify without modifying this section.
	Please consider support me on kofi.com https://ko-fi.com/kumohakase
*/


MEMORY {
	/* You need to modify if your target board has different memory map */
	ROM (rx) : ORIGIN = 0x8000000, LENGTH = 1M
	RAM (wx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
	.text : {
		*(.vects)
		*(.text.*)
		*(.ARM.exidx.text*);
		*(.rodata*)
		__sidata = .;
	} >ROM
	.data : {
		__sdata = .;
		*(.data)
		*(.data.*)
		__edata = .;
	} >RAM AT>ROM
	.bss : {
		__sbss = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
		__ebss = .;
	} >RAM
	__stack = ORIGIN(RAM) + LENGTH(RAM);
}
