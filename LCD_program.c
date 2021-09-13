/***************************************************************************************/
/*********	Name	:	Omar Mossa	****************************************************/
/*********  Date	:	22/9/2020	****************************************************/
/*********	SWC		:	LCD			****************************************************/
/*********	Version	:	V2.0		****************************************************/
/***************************************************************************************/

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util\delay.h>

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_voidInit(void)
{
	#if (INIT_MODE == EIGHT_BIT_INIT_MODE )

		_delay_ms(40);					// Wait More Than 30ms After VDD rises to 4.5 V
		LCD_u8SendCmnd(0b00101000);
		_delay_us(45);
		LCD_u8SendCmnd(0b00001111);
		_delay_us(45);
		LCD_u8SendCmnd(0b00000001);
		_delay_ms(3);
		LCD_u8SendCmnd(0b00000110);
	#elif ( INIT_MODE == FOUR_BIT_INIT_MODE )
		
		_delay_ms(40);					// Wait More Than 30ms After VDD rises to 4.5 V
		LCD_u8SendCmnd(0b00100010);
		LCD_u8SendCmnd4Bit(0b00001000);
		_delay_us(45);
		LCD_u8SendCmnd(0b00001111);
		_delay_us(45);
		LCD_u8SendCmnd(0b00000001);
		_delay_ms(3);
		LCD_u8SendCmnd(0b00000110);
	#endif	
}

u8 LCD_u8SendCmnd(u8 Copy_u8Cmnd) 
{
	u8 Local_u8ErrorStatus = OK ;

	#if (INIT_MODE == EIGHT_BIT_INIT_MODE )
	if( Copy_u8Cmnd <= 255 )
	{	
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_LOW );	// Instruction Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Cmnd ) ;					// Send The Command To LCD Pins

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}

	#elif ( INIT_MODE == FOUR_BIT_INIT_MODE )
	if( Copy_u8Cmnd <= 255 )
	{	
		/**** MSB HALF OF COMMAND ****/
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_LOW );	// Instruction Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN4 , (Copy_u8Cmnd >>4 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN5 , (Copy_u8Cmnd >>5 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN6 , (Copy_u8Cmnd >>6 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN7 , (Copy_u8Cmnd >>7 ) & 1 );

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);


		/**** LSB HALF OF COMMAND ****/
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_LOW );	// Instruction Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN4 , (Copy_u8Cmnd >>0 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN5 , (Copy_u8Cmnd >>1 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN6 , (Copy_u8Cmnd >>2 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN7 , (Copy_u8Cmnd >>3 ) & 1 );

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}
	#endif		

	return Local_u8ErrorStatus ;
}

u8 LCD_u8SendCmnd4Bit(u8 Copy_u8Cmnd) 
{
	u8 Local_u8ErrorStatus = OK ;
	if( Copy_u8Cmnd <= 15 )
	{	
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_LOW );	// Instruction Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN4 , (Copy_u8Cmnd >>0 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN5 , (Copy_u8Cmnd >>1 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN6 , (Copy_u8Cmnd >>2 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN7 , (Copy_u8Cmnd >>3 ) & 1 );

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}	
	return Local_u8ErrorStatus ;
}


u8 LCD_u8SendData(u8 Copy_u8Data) 
{
	u8 Local_u8ErrorStatus = OK ;

	#if (INIT_MODE == EIGHT_BIT_INIT_MODE )
	if( Copy_u8Data <= 255 )
	{	
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_HIGH );	// Data Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Data ) ;					// Send The Data To LCD Pins

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}

	#elif ( INIT_MODE == FOUR_BIT_INIT_MODE )
	if( Copy_u8Data <= 255 )
	{	

		/**** MSB HALF OF COMMAND ****/

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_HIGH );	// Data Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		//DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Data ) ;					// Send The Data To LCD Pins
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN4 , (Copy_u8Data >>4 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN5 , (Copy_u8Data >>5 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN6 , (Copy_u8Data >>6 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN7 , (Copy_u8Data >>7 ) & 1 );

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);


		/**** MSB HALF OF COMMAND ****/
		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RS_PIN , OUTPUT_HIGH );	// Data Register selected

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_RW_PIN , OUTPUT_LOW );	// Write Operation

		//DIO_u8SetPortValue( LCD_DATA_PORT , Copy_u8Data ) ;					// Send The Data To LCD Pins
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN4 , (Copy_u8Data >>0 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN5 , (Copy_u8Data >>1 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN6 , (Copy_u8Data >>2 ) & 1 );
		DIO_u8SetPinValue( LCD_DATA_PORT , LCD_DATA_PIN7 , (Copy_u8Data >>3 ) & 1 );

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_HIGH);	// Set Enable pin to HIGH for More than 230 nano second

		_delay_us(1);

		DIO_u8SetPinValue( LCD_CONTROL_PORT , LCD_E_PIN , OUTPUT_LOW);	// Set Enable pin to LOW for More than 230 nano second

		_delay_us(1);

	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}	
	#endif
	return Local_u8ErrorStatus ;
}		

u8 LCD_u8GoToXY( u8 Copy_u8Line , u8 Copy_u8X  )
{
	u8 Local_u8ErrorStatus = OK ;
	if (Copy_u8Line <= 1 && Copy_u8X <= 39 )
	{
		switch(Copy_u8Line)
		{
			case LCD_LINE1 :
			LCD_u8SendCmnd( 0x80 + Copy_u8X );
			break ;

			case LCD_LINE2 :
			LCD_u8SendCmnd(0x80 + 0x40 + Copy_u8X );
			break ;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;
	
}

u8 LCD_u8SendString(s8 * Copy_Ps8String)
{
	u8 Local_u8ErrorStatus = OK ;

	if (Copy_Ps8String != NULL)
	{
		u8 i = 0 ;
		while(*(Copy_Ps8String + i) != '\0')
		{
			LCD_u8SendData(*(Copy_Ps8String + i)) ;
			i++ ;
		}
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;
}

u8 LCD_u8SendNumber(u32 Copy_u32Num)
{
	u8 Local_u8ErrorStatus = OK ;
	u8 Local_Au8DigitsValue[10] = {0} ;
	u8 Local_u8DigitCounter = 9 ;
	if( Copy_u32Num == 0 )
	{
		LCD_u8SendData('0');
	}
	while (Copy_u32Num != 0 )
	{
		Local_Au8DigitsValue[ Local_u8DigitCounter ] = Copy_u32Num % 10 ;	
		Copy_u32Num /=  10;
		Local_u8DigitCounter-- ;
	}
	Local_u8DigitCounter++ ;
	for ( ; Local_u8DigitCounter < 10 ; Local_u8DigitCounter++ )
	{
		switch(Local_Au8DigitsValue[Local_u8DigitCounter])
		{
			case 0 :
			LCD_u8SendData('0');
			break ;

			case 1 :
			LCD_u8SendData('1');
			break ;

			case 2 :
			LCD_u8SendData('2');
			break ;

			case 3 :
			LCD_u8SendData('3');
			break ;

			case 4 :
			LCD_u8SendData('4');
			break ;

			case 5 :
			LCD_u8SendData('5');
			break ;

			case 6 :
			LCD_u8SendData('6');
			break ;

			case 7 :
			LCD_u8SendData('7');
			break ;

			case 8 :
			LCD_u8SendData('8');
			break ;

			case 9 :
			LCD_u8SendData('9');
			break ;
		}
	}
	return Local_u8ErrorStatus ;
}

void LCD_voidClear(void) 
{
	LCD_u8SendCmnd(0b00000001);
	_delay_ms(2);
}

void LCD_voidReturnHome(void)
{
	LCD_u8SendCmnd(0b00000010);
	_delay_ms(2);
}


void LCD_voidShiftCursorRight(void)
{
	LCD_u8SendCmnd(0b00010100);
}

void LCD_voidShiftCursorLeft(void)
{
	LCD_u8SendCmnd(0b00010000);
}


void LCD_voidShiftDisplayLeft(void)
{
	// Cursor follows the display
	LCD_u8SendCmnd(0b00011000);
}

void LCD_voidShiftDisplayRight(void)
{
	// Cursor follows the display
	LCD_u8SendCmnd(0b00011100);
}

u8 LCD_u8DrawSpecialChar( u8 Copy_u8CGRamAddress , u8 Copy_u8DDRamLine , u8 Copy_u8DDRamX, u8 Copy_Au8SpecialChar[8]) // Use Macros
{
	u8 Local_u8ErrorStatus = OK ;

	if ( Copy_u8CGRamAddress >= LCD_SP_CHAR_1 && Copy_u8CGRamAddress <= LCD_SP_CHAR_8 )
	{

		/*	Set CG Ram Address		*/
		LCD_u8SendCmnd(Copy_u8CGRamAddress) ;
	
		/*	Write 7 Bytes Data to CG Ram	*/
		for (int i = 0; i < 8 ; ++i)
		{
			LCD_u8SendData(Copy_Au8SpecialChar[i]);
		}

		/*	Set DD Ram Address		*/
		if(LCD_u8GoToXY( Copy_u8DDRamX , Copy_u8DDRamLine ) == NOK)
		{	
			/*	Invalid DDRam Address 	*/
			Local_u8ErrorStatus = NOK ;
		}
	}
	else
	{
		/*	Invalid CGRam Address 	*/
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus ;

}


u8 LCD_u8DisplaySpecialChar(u8 Copy_u8SpecialCharNum) // Use Macros For Input Arguments
{
	u8 Local_u8ErrorStatus = OK ;

	if ( Copy_u8SpecialCharNum >= LCD_SP_CHAR_1 && Copy_u8SpecialCharNum <= LCD_SP_CHAR_8 )
	{
		/*** Display Special Char ***/
		LCD_u8SendData( ( (Copy_u8SpecialCharNum ) - (0x40) ) / 8 ) ; // To Get 0 --> Char1 // 1 --> Char2 and so ON
	}
	else
	{
		Local_u8ErrorStatus = NOK ;	
	}

	return Local_u8ErrorStatus ;
}
