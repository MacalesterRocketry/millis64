#include "millis64.h"

static uint64_t g_micros_now64 = 0;
static bool g_micros_flag = false;
static uint64_t g_millis_now64 = 0;
static bool g_millis_flag = false;

inline uint64_t handle_overflow(const uint32_t now, uint64_t& now64, bool& flag) {
  if ((now & 0x80000000) == 0) {
    if (flag) {
      flag = false;
      now64 += 0x100000000; //  1 << 32;
    }
  } else {
    flag = true;
  }
  return now64 | now;
}

//  call once per 20 days
inline uint64_t millis64() {
  return handle_overflow(millis(), g_millis_now64, g_millis_flag);
}


/////////////////////////////////////////////////////
//
//  64 bits MICROS
//

//  call once per 30 minutes.
inline uint64_t micros64() {
  return handle_overflow(micros(), g_micros_now64, g_micros_flag);
}

/////////////////////////////////////////////////////
//
//  32 bits functions
//
inline uint32_t millis32() {
  return millis();
}

inline uint32_t micros32() {
  return micros();
}
