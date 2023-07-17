#include "strlen_test.h"

uint64_t getUptimeInMilliseconds(void) {
	static mach_timebase_info_data_t s_timebase_info;

	static dispatch_once_t           onceToken;
	dispatch_once(&onceToken, ^{ (void)mach_timebase_info(&s_timebase_info); });

	// mach_absolute_time() returns billionth of seconds,
	return (uint64_t)((mach_absolute_time() * s_timebase_info.numer));
}

size_t random_clamp(size_t min, size_t max) {
	return (rand() % (max - min) + min);
}

t_strings *new_string(size_t length) {
	t_strings *new = malloc(sizeof(new));

	new->length    = length;
	new->string    = malloc((sizeof(new->string) * new->length) + 1);

	size_t i       = 0;
	while (i < new->length) {
		new->string[i] = random_clamp(32, 126);
		i++;
	}
	new->string[i] = '\0';
	return new;
}

t_strings *new_string_length_between(size_t min_length, size_t max_length) {
	return new_string(random_clamp(min_length, max_length));
}

void fill_random_strings(
	t_strings *strings_short[NUM_STRINGS], t_strings *strings_medium[NUM_STRINGS],
	t_strings *strings_long[NUM_STRINGS], t_strings *strings_mix[NUM_STRINGS]
) {
	for (int i = 0; i < NUM_STRINGS; ++i) {
		strings_short[i]  = new_string_length_between(1, 50);
		strings_medium[i] = new_string_length_between(2500, 5000);
		strings_long[i]   = new_string_length_between(45000, 75000);

		switch (random_clamp(0, 3)) {
			case 1:
				strings_mix[i] = strings_short[i];
				break;
			case 2:
				strings_mix[i] = strings_medium[i];
				break;
			default:
				strings_mix[i] = strings_long[i];
				break;
		}
	}
}

void fill_strings(t_strings *strings[NUM_STRINGS + 1], int max) {
	size_t length = 1;
	size_t index  = 0;

	while (index < max) {
		strings[index] = new_string(length);
		index++;
		length *= 2;
	}
}

void random_sort(int **run_order, int max) {
	int swap_a;
	int swap_b;
	int tmp;
	int i;

	i = 0;
	while (i < 100) {
		swap_a               = random_clamp(0, max);
		swap_b               = random_clamp(0, max);
		tmp                  = (*run_order)[swap_a];
		(*run_order)[swap_a] = (*run_order)[swap_b];
		(*run_order)[swap_b] = tmp;
		i++;
	}
}

int *determine_run_order(int max) {
	int  n         = 0;
	int *run_order = malloc(max);

	while (n < max) {
		run_order[n] = n;
		n++;
	}
	random_sort(&run_order, max);

	return (run_order);
}
