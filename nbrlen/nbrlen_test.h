#pragma once

#include "nbrlen_functions.h"
#include <CoreServices/CoreServices.h>
#include <limits.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_NBR_LENGTH    20
#define NUMBER_PER_LENGTH 1000
#define ITERATIONS        1000

typedef struct s_functions {
		char *name;
		int (*func_1)(uint64_t);
		int (*func_2)(uint64_t, uint64_t);
		uint64_t times[MAX_NBR_LENGTH];
		uint64_t mean[MAX_NBR_LENGTH];
} t_functions;

typedef struct s_nbrdata {
		uint64_t number;
		int      length;
} t_nbrdata;

size_t   random_clamp(size_t min, size_t max);
uint64_t getUptimeInMilliseconds(void);
