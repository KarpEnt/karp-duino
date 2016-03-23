// 
// 
// 

#include "DigitalPulse.h"

/// <summary>
/// Initializes the specified pin number as a digital output.
/// </summary>
/// <param name="pinNumber">The pin number.</param>
void DigitalPulseClass::init(eLedDigitalOutput pinNumber)
{
	digitalPinNumber = pinNumber;

	// initialize digital pin 13 as an output.
	pinMode(digitalPinNumber, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);	
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


void DigitalPulseClass::Blink()
{
	digitalWrite(digitalPinNumber, HIGH);
	delay(pulseLen);
	digitalWrite(digitalPinNumber, LOW);
	delay(period - pulseLen);
}


DigitalPulseClass DigitalPulse;

