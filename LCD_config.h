/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/9/2020	****************************************************/
/*********	SWC		:	LCD			****************************************************/
/*********	Version	:	V2.0		****************************************************/
/***************************************************************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/************************************************/
/************  Initialization mode  *************/
/************************************************/


#define FOUR_BIT_INIT_MODE		0
#define EIGHT_BIT_INIT_MODE 	1

/*** choose from previous 4-bit(default) or 8-bit initialization mode ***/

#define INIT_MODE	FOUR_BIT_INIT_MODE



/***

OPTIONS : 

For Ports :

1- DIO_PORTA_ID
2- DIO_PORTB_ID
3- DIO_PORTC_ID
4- DIO_PORTD_ID

For Pins :

1- PIN0
2- PIN1
3- PIN2
4- PIN3
5- PIN4
6- PIN5
7- PIN6
8- PIN7


****/

#define LCD_DATA_PORT		DIO_PORTA_ID
/*** For 4 Bit Initialization Mode ***/
#define LCD_DATA_PIN4		PIN0
#define LCD_DATA_PIN5		PIN1
#define LCD_DATA_PIN6		PIN2
#define LCD_DATA_PIN7		PIN3
/*************************************/

#define LCD_CONTROL_PORT	DIO_PORTB_ID
#define LCD_RS_PIN			PIN0
#define LCD_RW_PIN			PIN1
#define LCD_E_PIN			PIN2


/********************************************************************/
/********** The Templates Of The Special Character Array ************/
/********************************************************************/

/****

Local_Au8SpecialChar[][] is array of characters which is used by passing it after initializing it 
to the LCD_u8DrawSpecialChar function.

x ----> Represent The Valid Bits Which
		0 is Pixel LED OFF
		1 is Pixel LED ON
		****** Use In APP Layer ******

u8 Local_Au8SpecialChar{X}[8] =	{
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX	,
									0b000XXXXX
								}

***/


#endif