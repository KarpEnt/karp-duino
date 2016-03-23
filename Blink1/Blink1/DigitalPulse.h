// DigitalPulse.h

#ifndef _DIGITALPULSE_h
#define _DIGITALPULSE_h

#include "eLedDigitalOutput.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class DigitalPulseClass
{
 private:
	 eLedDigitalOutput digitalPinNumber = internal;

 protected:
	 const int period = 1000;
	 int pulseLen = period/2;

 public:
	void init(eLedDigitalOutput pinNumber);

	boolean SetPulseDuration(float percentage);

	void Blink();

	// Properties
	eLedDigitalOutput getCurrentLED() const { return digitalPinNumber; }
	void setCurrentLED(eLedDigitalOutput num) { digitalPinNumber = num; }

};

extern DigitalPulseClass DigitalPulse;

#endif

