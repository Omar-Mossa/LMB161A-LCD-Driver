/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/9/2020	****************************************************/
/*********	SWC		:	LCD			****************************************************/
/*********	Version	:	V2.0		****************************************************/
/***************************************************************************************/


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*****************************************************************/
/**** Options For Copy_u8Y argument in LCD_u8GoToXY Function ****/
/*****************************************************************/

#define LCD_LINE1		0		
#define LCD_LINE2		1		

/********************************************************************************************/
/************ Options For Copy_u8CGRamAddress in LCD_u8DrawSpecialChar Function *************/
/**************************				    	&				*****************************/
/*** Options To Display Special Characters in DDRAM in LCD_u8DisplaySpecialChar Function ****/ 
/********************************************************************************************/
#define LCD_SP_CHAR_1	0x40
#define LCD_SP_CHAR_2	0x48
#define LCD_SP_CHAR_3	0x50
#define LCD_SP_CHAR_4	0x58
#define LCD_SP_CHAR_5	0x60
#define LCD_SP_CHAR_6	0x68
#define LCD_SP_CHAR_7	0x70
#define LCD_SP_CHAR_8	0x78	
/********************************************************************************/


void LCD_voidInit(void);

u8 LCD_u8SendCmnd(u8 Copy_u8Cmnd) ;

u8 LCD_u8SendData(u8 Copy_u8Data) ;

u8 LCD_u8GoToXY( u8 Copy_u8Line , u8 Copy_u8X ) ;

u8 LCD_u8SendString(s8 * Copy_Ps8String) ;

u8 LCD_u8SendNumber(u32 Copy_u32Num) ;

void LCD_voidClear(void) ;

void LCD_voidReturnHome(void) ;

void LCD_voidShiftCursorRight(void) ;

void LCD_voidShiftCursorLeft(void) ;

void LCD_voidShiftDisplayLeft(void) ; // Cursor follows the display

void LCD_voidShiftDisplayRight(void) ; // Cursor follows the display

u8 LCD_u8DrawSpecialChar( u8 Copy_u8CGRamAddress , u8 Copy_u8DDRamLine , u8 Copy_u8DDRamX, u8 Copy_Au8SpecialChar[8] ); // Use Macros 

u8 LCD_u8DisplaySpecialChar(u8 Copy_u8SpecialCharNum) ;



#endif