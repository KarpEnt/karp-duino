#ifndef _RESOURCES_h
#define _RESOURCES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Resources
const String promptMsg = "> ";

#ifdef LANG_POLISH
const String timeMsg = "Czas: ";
const String errorMsg = "Podaj jasnoœæ w procentach <0..100>.";
const String infoMsg = "Wypelnienie impulsu ustawione na ";
#else
const String timeMsg = "Time period: ";
const String errorMsg = "Enter the brightness percentage <0..100>.";
const String infoMsg = "Pulse duty factor set to ";
#endif // LANG_POLISH

#endif
