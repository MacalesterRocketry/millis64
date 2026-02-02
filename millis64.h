#pragma once
//
//    FILE: millis64.h
//  AUTHOR: Forked from Rob Tillaart by Ben Simmons
// VERSION: 0.1.2
//    DATE: 2025-01-17
// PURPOSE: Arduino library for millis64 micros64 millis32 micros32, time counters with optional offset.
//     URL: https://github.com/RobTillaart/millis64
//          https://forum.arduino.cc/t/arduino-millis-looping-after-45-5104-days/1343661/2


#include "Arduino.h"

// call once per 20 days
inline uint64_t millis64();

// call once per 30 minutes.
inline uint64_t micros64();

// just aliases for the standard functions
inline uint32_t millis32();
inline uint32_t micros32();
