/*
  BrightnessDemo:
  Turns on an LED with brightness defined by console command.

  Most Arduinos have an on-board LED you can control, usually attached to digital pin 13.
  In addition connect external LED to :
	- digital pin 7 (red one)
	- digital pin 8 (grean one)
  See attached schema for details.
	
  Terminal commands:
	<n> - set the brightness the on-board LED.
	c<n> - set the brightness the red LED
	z<n> - set the brightness the green LED
  when <n> is the brightness percentage value, a number between 0 and 100.

  This example code is in the public domain.
 */

//#define LANG_POLISH

#include "Resources.h"
#include "DigitalPulse.h"

unsigned long nowMs = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	
	DigitalPulse.init(internal);
}

// the loop function runs over and over again forever
void loop() {
	int period = 0;

	if (Serial.available())
	{
		char c = Serial.peek();
		//Serial.println(c);
		switch (c)
		{
		case 'c':
			DigitalPulse.setCurrentLED(red);
			break;
		case 'z':
			DigitalPulse.setCurrentLED(green);
			break;
		default:
			DigitalPulse.setCurrentLED(internal);
			break;
		}

		period = Serial.parseFloat();
		if (period >= 0 && period <= 100)
		{
			DigitalPulse.SetPulseDuration(period / 100.0);
			Serial.println(promptMsg + infoMsg + (String)period + "%");
		}
		else
		{
			Serial.println(errorMsg);
		}
	}

	//Serial.println(">" + timeMsg + (float)(millis() / 1000.0) + " sek.");

	DigitalPulse.Blink();

	//DigitalPulse.SetPulseDuration(0.01);
	//for (int i = 0; i < 5; i++)
	//{
	//	DigitalPulse.Blink();
	//	
	//}

	//DigitalPulse.SetPulseDuration(0.5);
	//for (int i = 0; i < 2; i++)
	//{
	//	DigitalPulse.Blink();
	//}

}



 