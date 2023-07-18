#include "nbrlen_test.h"

uint64_t getUptimeInMilliseconds(void) {
	static mach_timebase_info_data_t s_timebase_info;

	static dispatch_once_t           onceToken;
	dispatch_once(&onceToken, ^{ (void)mach_timebase_info(&s_timebase_info); });

	// mach_absolute_time() returns billionth of seconds,
	return (uint64_t)((mach_absolute_time() * s_timebase_info.numer));
}

size_t random_clamp(size_t min, size_t max) {
	return ((rand() * rand()) % (max - min) + min);
}
