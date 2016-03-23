// DigitalPulse.h

#ifndef _DIGITALPULSE_h
#define _DIGITALPULSE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class DigitalPulseClass
{
 protected:
	 int digitalPinNumber = 13;

	 const int period = 1000;
	 int pulseLen = period/2;

 public:
	void init(int pinNumber);

	boolean SetPulseDuration(float percentage);

	void ChangePinNumber(int pinNumber);

	void Blink();

};

extern DigitalPulseClass DigitalPulse;

#endif

