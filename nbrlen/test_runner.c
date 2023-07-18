#include "nbrlen_test.h"

void run_test_1(t_functions *test, int iteration,
				uint64_t data[MAX_NBR_LENGTH + 1][NUMBER_PER_LENGTH]) {
	uint64_t begin = 0, end = 0;

	for (int len = 0; len < MAX_NBR_LENGTH; ++len) {
		for (int nbr = 0; nbr < NUMBER_PER_LENGTH; ++nbr) {
			begin = getUptimeInMilliseconds();
			test->func_1(data[len][nbr]);
			end = getUptimeInMilliseconds();
			test->times[len] += end - begin;
		}
	}
}

int main(void) {
	srand(time(NULL));

	t_functions functions_base10[] = {
		{.name = "nbrlen base 10 loop", .func_1 = nbrlen_base10_loop},
		{.name = "nbrlen base 10 if", .func_1 = nbrlen_base10_if},
	};

	t_functions functions_baseN[] = {
		{.name = "nbrlen base N loop", .func_2 = nbrlen_baseN_loop},
		{.name = "nbrlen base N if 1", .func_2 = nbrlen_baseN_if_1},
		{.name = "nbrlen base N if 2", .func_2 = nbrlen_baseN_if_2},
	};

	uint64_t data[MAX_NBR_LENGTH + 1][NUMBER_PER_LENGTH];

	uint64_t min = 0;
	uint64_t max = 9;
	for (int len = 0; len < MAX_NBR_LENGTH; ++len) {
		functions_base10[0].times[len] = 0;
		functions_base10[0].mean[len]  = 0;
		functions_base10[1].times[len] = 0;
		functions_base10[1].mean[len]  = 0;

		functions_baseN[0].times[len]  = 0;
		functions_baseN[0].mean[len]   = 0;
		functions_baseN[1].times[len]  = 0;
		functions_baseN[1].mean[len]   = 0;
		functions_baseN[2].times[len]  = 0;
		functions_baseN[2].mean[len]   = 0;

		for (int nbr = 0; nbr < NUMBER_PER_LENGTH; ++nbr) {
			data[len][nbr] = random_clamp(min, max);
		}
		if (min == 0) {
			min = 10;
		} else {
			min *= 10;
		}
		max *= 10;
		max += 9;
		if (min == 10000000000000000000ULL) {
			max = ULONG_MAX;
		}
	}

	// run tests
	for (int i = 0; i < ITERATIONS; ++i) {
		run_test_1(&functions_base10[0], i, data);
		run_test_1(&functions_base10[1], i, data);
	}

	// calculate mean
	for (int len = 0; len < MAX_NBR_LENGTH; ++len) {
		functions_base10[0].mean[len] = functions_base10[0].times[len] / ITERATIONS;
		functions_base10[1].mean[len] = functions_base10[1].times[len] / ITERATIONS;
	}

	printf(
		"name, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20\n");
	for (int i = 0; i < 2; ++i) {
		printf("%s,", functions_base10[i].name);
		for (int n = 0; n < MAX_NBR_LENGTH; ++n) {
			printf("%llu%.*s", functions_base10[i].mean[n], !(n == MAX_NBR_LENGTH - 1),
				   ",");
		}
		printf("\n");
	}


	return 0;
}
