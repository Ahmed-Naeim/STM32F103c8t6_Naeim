	/*
		@file	LinkerScript.ld
		@Author	Ahmed Naeim
		@Date 12/10/2023
		@brief	LinkerScript for STM32F10x
	*/
	/*Highest address of the user mode stack*/
	
	_estack = ORIGIN(RAM) + LENGTH (RAM); /* End of "RAM" type memory */
	_Min_Heap_Size = 0x200; /* Required Amount of Heap */
	_Min_Stack_Size = 0x200; /* Required Amount of Stack */



	/*Memories Definition*/	
	MEMORY
	{
		RAM	(xrw)	: ORIGIN = 0x20000000, LENGTH = 20K
		FLASH (rx)	:ORIGIN = 0x08000000, LENGTH = 64K
	}
	
	
	/*Sections Definition*/
	SECTIONS
	{
		/* The startup code ionto "FLASH" ROM data type */
		.isr_vector :
		{
			. = ALIGN (4);
			*(.isr_vector)
			. = ALIGN (4);
		}>FLASH

		/* .text section, The program code and other data into "FLASH" Rom type memory */
		.text :
		{
			. = ALIGN (4);
			*(.text)
			*(.text*)
			. = ALIGN (4);
			_etext = .;

		}> RAM AT > FLASH

		/* .rodata section, Constant data into "FLASH" Rom type memory */
		.rodata :
		{
			. = ALIGN (4);
			*(.rodata)
			*(.rodata*)
			. = ALIGN (4);

		}>FLASH

		/* Used by the startup to Initialize data */
		_sidata = LOADADDR (.data);

		/* .data section, Initialized data sections into "RAM" Ram type memory */
		.data :
		{
			_sdata = . ;
			. = ALIGN (4);
			*(.data)
			*(.data*)
			. = ALIGN (4);
			_edata = . ;
			

		}>RAM

		/* .bss section, Uninitialized data section into "RAM" Ram type memory */
		.bss :
		{
			_sbss = .;
			. = ALIGN (4);
			*(.bss)
			*(.bss*)
			. = ALIGN (4);
			_ebss = .;

		}>RAM

		/* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
		/*.User_heap_stack :
		{
			
		}>RAM*/

	}