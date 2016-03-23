// 
// 
// 

#include "DigitalPulse.h"

void DigitalPulseClass::init(int pinNumber)
{
	digitalPinNumber = 13;

	// initialize digital pin 13 as an output.
	pinMode(digitalPinNumber, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);	

	if (pinNumber == 7 || pinNumber == 8)
		digitalPinNumber = pinNumber;
}

// Sets pulse duration
// Returns true for the correct input 
boolean DigitalPulseClass::SetPulseDuration(float percentage)
{
	if (percentage >= 0 && percentage < 1.0)
	{
		pulseLen = (period * percentage);

		return true;
	}

	return false;
}

void DigitalPulseClass::ChangePinNumber(int pinNumber)
{
	if (pinNumber == 7 || pinNumber == 8 || pinNumber == 13)
	{
		digitalPinNumber = pinNumber;
	}
}

void DigitalPulseClass::Blink()
{
	digitalWrite(digitalPinNumber, HIGH);
	delay(pulseLen);
	digitalWrite(digitalPinNumber, LOW);
	delay(period - pulseLen);
}


DigitalPulseClass DigitalPulse;

