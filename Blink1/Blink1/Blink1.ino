/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#include "DigitalPulse.h"

unsigned long nowMs = 0;
String timeMsg = "Czas: ";
String errorMsg = "Podaj wypelnienie impulsu w procentach <0..100>.";

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	
	DigitalPulse.init(13);
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
			DigitalPulse.ChangePinNumber(7);
			break;
		case 'z':
			DigitalPulse.ChangePinNumber(8);
			break;
		default:
			DigitalPulse.ChangePinNumber(13);
			break;
		}

		period = Serial.parseFloat();
		if (period >= 0 && period <= 100)
		{
			DigitalPulse.SetPulseDuration(period / 100.0);
			Serial.println("> Wypelnienie impulsu ustawione na " + (String)period + "%");
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



 