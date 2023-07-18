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

void run_test(t_tests *test, int iteration, t_strings **strings, int *string_order) {
	int      t     = 0;
	uint64_t begin = 0, end = 0;
	size_t   result;

	while (t < MAX_POWER2) {
		result = 0;
		begin  = getUptimeInMilliseconds();
		result = test->func(strings[string_order[t]]->string);
		end    = getUptimeInMilliseconds();
		if (result != strings[string_order[t]]->length) {
			printf(
				"\n--- WRONG RESULT -- f: %s, res: %zu, exp: %zu\n", test->name, result,
				strings[string_order[t]]->length
			);
		}
		test->times[string_order[t]] += end - begin;
		t++;
	}
}


int main(void) {
	srand(time(NULL));

	t_strings       **strings    = fill_strings();

	const int         num_tests  = (sizeof(tests) / sizeof(t_tests)) - 1;
	static const char progress[] = "XXXXXXXXXXXXXXXXXXXX";

	// set times to zero
	for (int f = 0; f < num_tests; ++f) {
		for (int t = 0; t < MAX_POWER2; ++t) {
			tests[f].times[t] = 0;
			tests[f].mean[t]  = 0;
		}
	}

	for (int i = 0; i < ITERATIONS; ++i) {
		int *test_run_order = determine_run_order(num_tests);
		int *string_order   = determine_string_order();
		int  run_index      = 0;


		for (int t = 0; t < num_tests; ++t) {
#if SHOW_PROGRESS
			printf(
				"\riteration %i [%-19.*s] %-25s", i,
				(int)((float)i / ITERATIONS_F * 20.0), progress,
				tests[test_run_order[t]].name
			);
			fflush(stdout);
#endif
			run_test(&tests[test_run_order[t]], i, strings, string_order);
		}
		free(test_run_order);
	}
#if SHOW_PROGRESS
	printf("\n");
#endif

	// calculate mean:
	for (int f = 0; f < num_tests; ++f) {
		for (int t = 0; t < MAX_POWER2; ++t) {
			tests[f].mean[t] = tests[f].times[t] / ITERATIONS;
		}
	}
	// print results
	printf("name,");
	int num_chars = 1;
	int l         = 0;
	while (l < MAX_POWER2) {
		printf("%ich%*s", num_chars, !(l == (MAX_POWER2 - 1)), ",");
		num_chars *= 2;
		l++;
	}
	printf("\n");

	for (int f = 0; f < num_tests; ++f) {
		printf("%s,", tests[f].name);
		for (int t = 0; t < MAX_POWER2; ++t) {
			printf("%llu%.*s", tests[f].mean[t], !(t == (MAX_POWER2 - 1)), ",");
		}
		printf("\n");
	}


	// print_results();

	free_strings(strings);
	return 0;
}
