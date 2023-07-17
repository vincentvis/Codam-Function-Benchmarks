#include "strlen_test.h"

static t_tests tests[] = {
	{.name = "system", .func = strlen},

	{.name = "assembly pcmpistri", .func = ft_strlen_asm},

	{.name = "1 char move ptr", .func = one_char_move_ptr},
	{.name = "1 char counter", .func = one_char_counter},
	{.name = "1 char recursive", .func = one_char_recursive},

	{.name = "2 char move ptr", .func = two_char_move_ptr},
	{.name = "2 char counter", .func = two_char_counter},
	{.name = "2 char recursive", .func = two_char_recursive},

	{.name = "4 char move ptr", .func = four_char_move_ptr},
	{.name = "4 char move ptr norm", .func = four_char_move_ptr_norm},
	{.name = "4 char counter", .func = four_char_counter},
	{.name = "4 char unroll alt", .func = four_char_unroll_alt},
	{.name = "4 char recursive", .func = four_char_recursive},

	{.name = "8 char move ptr", .func = eight_char_move_ptr},
	{.name = "8 char move ptr norm", .func = eight_char_move_ptr_norm},
	{.name = "8 char counter", .func = eight_char_counter},
	{.name = "8 char counter norm", .func = eight_char_counter_norm},
	{.name = "8 count in while", .func = eight_count_in_while},
	{.name = "8 ptr in while", .func = eight_ptr_in_while},
	{.name = "8 char recursive", .func = eight_char_recursive},

	{.name = "16 char move ptr", .func = sixteen_char_move_ptr},
	{.name = "16 char move ptr norm", .func = sixteen_char_move_ptr_norm},
	{.name = "16 char counter", .func = sixteen_char_counter},
	{.name = "16 char counter norm", .func = sixteen_char_counter_norm},
	{.name = "16 count in while", .func = sixteen_count_in_while},
	{.name = "16 ptr in while", .func = sixteen_ptr_in_while},
	{.name = "16 char recursive", .func = sixteen_char_recursive},
	{.name = NULL},
};


void run_test(
	t_tests *test, int i, t_strings *strings_short[NUM_STRINGS + 1],
	t_strings *strings_medium[NUM_STRINGS + 1], t_strings *strings_long[NUM_STRINGS + 1],
	t_strings *strings_mix[NUM_STRINGS + 1]
) {
	int      t     = 0;
	uint64_t begin = 0, end = 0, diff = 0;
	size_t   result = 0;

	t               = 0;
	while (t < NUM_STRINGS) {
		result = 0;
		begin  = getUptimeInMilliseconds();
		result = test->func(strings_short[t]->string);
		end    = getUptimeInMilliseconds();
		if (result != strings_short[t]->length) {
			printf(
				"\n--- WRONG RESULT -- f: %s, res: %zu, exp: %zu\n", test->name, result,
				strings_short[t]->length
			);
		}
		test->short_result[i] += end - begin;
		t++;
	}
	t = 0;
	while (t < NUM_STRINGS) {
		result = 0;
		begin  = getUptimeInMilliseconds();
		result = test->func(strings_medium[t]->string);
		end    = getUptimeInMilliseconds();
		if (result != strings_medium[t]->length) {
			printf(
				"\n--- WRONG RESULT -- f: %s, res: %zu, exp: %zu\n", test->name, result,
				strings_medium[t]->length
			);
		}
		test->medium_result[i] += end - begin;
		t++;
	}
	t = 0;
	while (t < NUM_STRINGS) {
		result = 0;
		begin  = getUptimeInMilliseconds();
		result = test->func(strings_long[t]->string);
		end    = getUptimeInMilliseconds();
		if (result != strings_long[t]->length) {
			printf(
				"\n--- WRONG RESULT -- f: %s, res: %zu, exp: %zu\n", test->name, result,
				strings_long[t]->length
			);
		}
		test->long_result[i] += end - begin;
		t++;
	}
	t = 0;
	while (t < NUM_STRINGS) {
		result = 0;
		begin  = getUptimeInMilliseconds();
		result = test->func(strings_mix[t]->string);
		end    = getUptimeInMilliseconds();
		if (result != strings_mix[t]->length) {
			printf(
				"\n--- WRONG RESULT -- f: %s, res: %zu, exp: %zu\n", test->name, result,
				strings_mix[t]->length
			);
		}
		test->mix_result[i] += end - begin;
		t++;
	}

	test->short_average_i[i]  = test->short_result[i] / NUM_STRINGS;
	test->medium_average_i[i] = test->medium_result[i] / NUM_STRINGS;
	test->long_average_i[i]   = test->long_result[i] / NUM_STRINGS;
	test->mix_average_i[i]    = test->mix_result[i] / NUM_STRINGS;

	test->short_average += test->short_average_i[i];
	test->medium_average += test->medium_average_i[i];
	test->long_average += test->long_average_i[i];
	test->mix_average += test->mix_average_i[i];
}

void run_test2(t_tests *test, int iteration, t_strings **strings_short) {
}

void print_results(void) {
	t_tests *t = &tests[0];

#ifdef OUTPUT_CSV
	printf("%s, %s, %s, %s, %s\n", "name", "short", "medium", "long", "mix");
	while (t->name) {
		printf(
			"%s, %llu, %llu, %llu, %llu\n", t->name, t->short_average, t->medium_average,
			t->long_average, t->mix_average
		);
		t++;
	}
#else
	printf("%24s, %10s, %10s, %10s, %10s\n", "name", "short", "medium", "long", "mix");

	while (t->name) {
		printf(
			"%24s, %10llu, %10llu, %10llu, %10llu\n", t->name, t->short_average,
			t->medium_average, t->long_average, t->mix_average
		);
		t++;
	}
#endif
}

int main(void) {
	srand(time(NULL));

	t_strings strings[NUM_STRINGS + 1];
	fill_strings((t_strings **)&strings, MAX_POWER2);

	// t_strings *strings_short[NUM_STRINGS + 1];
	// t_strings *strings_medium[NUM_STRINGS + 1];
	// t_strings *strings_long[NUM_STRINGS + 1];
	// t_strings *strings_mix[NUM_STRINGS + 1];
	// fill_random_strings(strings_short, strings_medium, strings_long, strings_mix);

	const int         run_max    = (sizeof(tests) / sizeof(t_tests)) - 1;
	static const char progress[] = "XXXXXXXXXXXXXXXXXXXX";

	for (int i = 0; i < ITERATIONS; ++i) {
		int *run_order = determine_run_order(run_max);
		int  run_index = 0;

		for (int t = 0; t < run_max; ++t) {
#if SHOW_PROGRESS
			printf(
				"\riteration %i [%-19.*s] %-25s", i,
				(int)((float)i / ITERATIONS_F * 20.0), progress, tests[run_order[t]].name
			);
			fflush(stdout);
#endif

			// run_test(
			// 	&tests[run_order[t]], i, strings_short, strings_medium, strings_long,
			// 	strings_mix
			// );
			run_test2(&tests[run_order[t]], i, strings);
		}
	}
#if SHOW_PROGRESS
	printf("\n");
#endif

	for (int i = 0; i < run_max; ++i) {
		tests[i].short_average /= ITERATIONS;
		tests[i].medium_average /= ITERATIONS;
		tests[i].long_average /= ITERATIONS;
		tests[i].mix_average /= ITERATIONS;
	}

	print_results();

	return 0;
}
