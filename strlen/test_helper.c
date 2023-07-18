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


t_strings **fill_strings(void) {
	t_strings **strings = malloc(sizeof(strings) * (MAX_POWER2 + 1));
	size_t      length  = 1;
	size_t      index   = 0;

	while (index <= MAX_POWER2) {
		strings[index] = new_string(length);
		index++;
		length *= 2;
	}
	return strings;
}

void free_strings(t_strings **strings) {
	for (int i = 0; i <= MAX_POWER2; ++i) {
		free(strings[i]);
	}
	free(strings);
}

void random_sort(int **run_order, int max) {
	int swap_a;
	int swap_b;
	int tmp;
	int dynamic_max = max * max * 2;
	int i           = 0;

	while (i < dynamic_max) {
		swap_a               = random_clamp(0, max);
		swap_b               = random_clamp(0, max);
		tmp                  = (*run_order)[swap_a];
		(*run_order)[swap_a] = (*run_order)[swap_b];
		(*run_order)[swap_b] = tmp;
		i++;
	}
}

int *determine_string_order() {
	int        n = 0;
	static int string_order[MAX_POWER2 + 1];

	while (n < MAX_POWER2) {
		string_order[n] = n;
		n++;
	}
	n = 0;
	int swap_a, swap_b;
	int tmp;
	while (n < 170) {
		swap_a               = random_clamp(0, MAX_POWER2);
		swap_b               = random_clamp(0, MAX_POWER2);
		tmp                  = string_order[swap_a];
		string_order[swap_a] = string_order[swap_b];
		string_order[swap_b] = tmp;
		n++;
	}
	return string_order;
}

int *determine_run_order(int max) {
	int  n         = 0;
	int *run_order = malloc(max + 1);

	while (n < max) {
		run_order[n] = n;
		n++;
	}
	random_sort(&run_order, max);

	return (run_order);
}
