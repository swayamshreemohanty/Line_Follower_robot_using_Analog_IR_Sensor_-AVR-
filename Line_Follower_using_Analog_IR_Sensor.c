
#include<avr/io.h>
/*Includes io.h header file where all the Input/Output Registers and its Bits are defined for AVR microcontroller*/

#define	F_CPU	1000000
/*Defines a macro for the delay.h header file. F_CPU is the microcontroller frequency value for the delay.h header file. Default value of F_CPU in delay.h header file is 1000000(1MHz)*/

#include<util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

#include<avr/adc.h>
/*Includes adc.h header file which defines all the functions for Analog to Digital Converter*/


#define Ref 615//ref 3v
/* Defines a macro for the Refference value for the sensors*/


void main()
{
	

	DDRD=0xff;
	/*PC0,PC1,PC2,PC3 pins of PortC are declared output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/

	int left_sensor_value,right_sensor_value;
	/*Variable declarations*/
	adc_init();
	/*ADC initialization*/

	/*Start of infinite loop*/
	while(1)
	{
		left_sensor_value=read_adc_channel(0);
		/*Reading left sensor value*/

		right_sensor_value=read_adc_channel(1);
		/*Reading right sensor value*/
		
		
		if(left_sensor_value < Ref && right_sensor_value < Ref)
		{

			PORTD=0b00001010;
			
		}
		else 
		if(left_sensor_value < Ref && right_sensor_value > Ref)
		{
		

			PORTD=0x08;
 			/*Robot will move towards left*/
		}
		else if(left_sensor_value > Ref && right_sensor_value < Ref)
		{
		

			PORTD=0x02;
			/*Robot will move towards right*/
		}
		else 
		;
		
	}
}
