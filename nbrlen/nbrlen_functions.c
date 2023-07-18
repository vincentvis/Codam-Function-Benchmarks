#include <stdint.h>

int nbrlen_base10_loop(uint64_t number) {
	int length = (number == 0) ? 1 : 0;

	while (number != 0) {
		number /= 10;
		length++;
	}
	return (length);
}

// max amount of characters in unsigned long long = 20 (18446744073709551615)
int nbrlen_base10_if(uint64_t number) {
	if (number < 10ULL)
		return (1);
	if (number < 100ULL)
		return (2);
	if (number < 1000ULL)
		return (3);
	if (number < 10000ULL)
		return (4);
	if (number < 100000ULL)
		return (5);
	if (number < 1000000ULL)
		return (6);
	if (number < 10000000ULL)
		return (7);
	if (number < 100000000ULL)
		return (8);
	if (number < 1000000000ULL)
		return (9);
	if (number < 10000000000ULL)
		return (10);
	if (number < 100000000000ULL)
		return (11);
	if (number < 1000000000000ULL)
		return (12);
	if (number < 10000000000000ULL)
		return (13);
	if (number < 100000000000000ULL)
		return (14);
	if (number < 1000000000000000ULL)
		return (15);
	if (number < 10000000000000000ULL)
		return (16);
	if (number < 100000000000000000ULL)
		return (17);
	if (number < 1000000000000000000ULL)
		return (18);
	if (number < 10000000000000000000ULL)
		return (19);
	return (20);
}

int nbrlen_baseN_loop(uint64_t number, uint64_t base) {
	int length = (number == 0) ? 1 : 0;

	while (number != 0) {
		number /= base;
		length++;
	}
	return (length);
}

int nbrlen_baseN_if_1(uint64_t number, uint64_t b) {
	if (number < b)
		return (1);
	if (number < b * b)
		return (2);
	if (number < b * b * b)
		return (3);
	if (number < b * b * b * b)
		return (4);
	if (number < b * b * b * b * b)
		return (5);
	if (number < b * b * b * b * b * b)
		return (6);
	if (number < b * b * b * b * b * b * b)
		return (7);
	if (number < b * b * b * b * b * b * b * b)
		return (8);
	if (number < b * b * b * b * b * b * b * b * b)
		return (9);
	if (number < b * b * b * b * b * b * b * b * b * b)
		return (10);
	if (number < b * b * b * b * b * b * b * b * b * b * b)
		return (11);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b)
		return (12);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (13);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (14);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (15);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (16);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (17);
	if (number < b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (18);
	if (number <
		b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b * b)
		return (19);
	return (20);
}

int nbrlen_baseN_if_2(uint64_t number, uint64_t base) {
	if (number < base)
		return (1);
	base *= base;
	if (number < base)
		return (2);
	base *= base;
	if (number < base)
		return (3);
	base *= base;
	if (number < base)
		return (4);
	base *= base;
	if (number < base)
		return (5);
	base *= base;
	if (number < base)
		return (6);
	base *= base;
	if (number < base)
		return (7);
	base *= base;
	if (number < base)
		return (8);
	base *= base;
	if (number < base)
		return (9);
	base *= base;
	if (number < base)
		return (10);
	base *= base;
	if (number < base)
		return (11);
	base *= base;
	if (number < base)
		return (12);
	base *= base;
	if (number < base)
		return (13);
	base *= base;
	if (number < base)
		return (14);
	base *= base;
	if (number < base)
		return (15);
	base *= base;
	if (number < base)
		return (16);
	base *= base;
	if (number < base)
		return (17);
	base *= base;
	if (number < base)
		return (18);
	base *= base;
	if (number < base)
		return (19);
	return (20);
}
