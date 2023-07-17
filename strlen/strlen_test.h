#pragma once

#include "strlen_functions.h"
#include <CoreServices/CoreServices.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TESTS   100
#define NUM_STRINGS 750
#define MAX_POWER2  17
// #define NUM_STRINGS   250
#define ITERATIONS    50
#define ITERATIONS_F  50.0
#define SHOW_PROGRESS 1

#define OUTPUT_CSV    1

typedef struct s_tests {
		const char *name;
		size_t (*func)(const char *);
		uint64_t times[NUM_STRINGS];
		uint64_t averages[NUM_STRINGS];
		// old
		uint64_t mix_result[ITERATIONS];
		uint64_t mix_average_i[ITERATIONS];
		uint64_t mix_average;
		uint64_t long_result[ITERATIONS];
		uint64_t long_average_i[ITERATIONS];
		uint64_t long_average;
		uint64_t medium_result[ITERATIONS];
		uint64_t medium_average_i[ITERATIONS];
		uint64_t medium_average;
		uint64_t short_result[ITERATIONS];
		uint64_t short_average_i[ITERATIONS];
		uint64_t short_average;
} t_tests;

typedef struct s_strings {
		char  *string;
		size_t length;
} t_strings;

uint64_t getUptimeInMilliseconds(void);
void     fill_random_strings(
		t_strings *strings_short[NUM_STRINGS], t_strings *strings_medium[NUM_STRINGS],
		t_strings *strings_long[NUM_STRINGS], t_strings *strings_mix[NUM_STRINGS]
	);
void fill_strings(t_strings **strings, int max);
int *determine_run_order(int max);