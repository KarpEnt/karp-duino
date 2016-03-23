#ifndef _RESOURCES_h
#define _RESOURCES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Resources
#ifdef LANG_POLISH
const String timeMsg = "Czas: ";
const String errorMsg = "Podaj jasnoœæ w procentach <0..100>.";
#else
const String timeMsg = "Time period: ";
const String errorMsg = "Enter the brightness percentage <0..100>.";
#endif // LANG_POLISH

#endif
