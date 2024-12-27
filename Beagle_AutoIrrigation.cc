
#include "Beagle_GPIO.hh"

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

Beagle_GPIO	gpio;

int main()
{
	GPIO_PRINT( "====================" );
	GPIO_PRINT( " Wite based on read " );
	GPIO_PRINT( "====================" );

	GPIO_PRINT( "Configuring Pin P8_46 as Output" );
	gpio.configurePin( Beagle_GPIO::P8_46, Beagle_GPIO::kOUTPUT );
	gpio.enablePinInterrupts( Beagle_GPIO::P8_46, false );

    while(1)
	{
		if(gpio.readPin(Beagle_GPIO::P8_44))
		{
		GPIO_PRINT( "Writing 1" );
		gpio.writePin( Beagle_GPIO::P8_46, 1 );
		GPIO_PRINT( "Waiting 500ms" );
		usleep(500000);
		}
		else
		{
		GPIO_PRINT( "Writing 0" );
		gpio.writePin( Beagle_GPIO::P8_46, 0 );
		GPIO_PRINT( "Waiting 500ms" );
		usleep(500000);
		}
	}
	return 0;
}
