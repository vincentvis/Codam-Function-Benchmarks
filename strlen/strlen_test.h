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

#define MAX_TESTS     100
#define MAX_POWER2    18
#define ITERATIONS    1000
#define ITERATIONS_F  1000.0
#define SHOW_PROGRESS 1

#define OUTPUT_CSV    1

typedef struct s_tests {
		const char *name;
		size_t (*func)(const char *);
		uint64_t times[MAX_POWER2];
		uint64_t mean[MAX_POWER2];
} t_tests;

typedef struct s_strings {
		char  *string;
		size_t length;
} t_strings;

uint64_t    getUptimeInMilliseconds(void);
t_strings **fill_strings(void);
void        free_strings(t_strings **strings);
int        *determine_string_order(void);
int        *determine_run_order(int max);