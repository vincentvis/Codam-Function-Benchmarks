#include <stddef.h>

/*
	Move one char per iteration
 */
size_t one_char_move_ptr(const char *str) {
	const char *move = str;

	while (*move != '\0') {
		move++;
	}
	return (move - str);
}

size_t one_char_counter(const char *str) {
	size_t length = 0;

	while (str[length] != '\0') {
		length++;
	}
	return (length);
}

size_t one_char_recursive(const char *str) {
	if (*str == '\0')
		return (0);
	return (1 + one_char_recursive(str + 1));
}


/*
	Move 2 chars per iteration
 */
size_t two_char_move_ptr(const char *str) {
	const char *move = str;

	while (*move != '\0') {
		if (*(move + 1) == '\0')
			return ((move + 1) - str);
		move += 2;
	}
	return (move - str);
}

size_t two_char_counter(const char *str) {
	size_t length = 0;

	while (str[length] != '\0') {
		if (str[length + 1] == '\0')
			return (length + 1);
		length += 2;
	}
	return (length);
}

size_t two_char_recursive(const char *str) {
	if (*str == '\0')
		return (0);
	if (*(str + 1) == '\0')
		return (1);
	return (2 + two_char_recursive(str + 2));
}


/*
	Move 4 chars per iteration
 */
size_t four_char_move_ptr(const char *str) {
	const char *move = str;

	while (*move != '\0') {
		if (*(move + 1) == '\0')
			return ((move + 1) - str);
		if (*(move + 2) == '\0')
			return ((move + 2) - str);
		if (*(move + 3) == '\0')
			return ((move + 3) - str);
		move += 4;
	}
	return (move - str);
}

size_t four_char_move_ptr_norm(const char *str) {
	const char *m = str;

	while (*m && *(m + 1)) {
		if (!*(m + 2) || !*(m + 3))
			return ((m + 2 + (!!(*(m + 2)) * 1)) - str);
		m += 4;
	}
	return ((m + (!!*m * 1)) - str);
}

size_t four_char_counter(const char *str) {
	size_t length = 0;

	while (str[length] != '\0') {
		if (str[length + 1] == '\0')
			return (length + 1);
		if (str[length + 2] == '\0')
			return (length + 2);
		if (str[length + 3] == '\0')
			return (length + 3);
		length += 4;
	}
	return (length);
}

size_t four_char_recursive(const char *str) {
	if (*str == '\0')
		return (0);
	if (*(str + 1) == '\0')
		return (1);
	if (*(str + 2) == '\0')
		return (2);
	if (*(str + 3) == '\0')
		return (3);
	return (4 + four_char_recursive(str + 4));
}

size_t four_char_unroll_alt(const char *str) {
	size_t len1;
	size_t len2;
	size_t len3;
	size_t len4;

	len1 = 0;
	len2 = 1;
	len3 = 2;
	len4 = 3;
	while (str[len1] && str[len2] && str[len3] && str[len4]) {
		len1 += 4;
		len2 += 4;
		len3 += 4;
		len4 += 4;
	}
	if (str[len1] == 0)
		return (len1);
	if (str[len2] == 0)
		return (len2);
	if (str[len3] == 0)
		return (len3);
	return (len4);
}

/*
	Move 8 chars per iteration
 */
size_t eight_char_move_ptr(const char *str) {
	const char *move = str;

	while (*move != '\0') {
		if (*(move + 1) == '\0')
			return ((move + 1) - str);
		if (*(move + 2) == '\0')
			return ((move + 2) - str);
		if (*(move + 3) == '\0')
			return ((move + 3) - str);
		if (*(move + 4) == '\0')
			return ((move + 4) - str);
		if (*(move + 5) == '\0')
			return ((move + 5) - str);
		if (*(move + 6) == '\0')
			return ((move + 6) - str);
		if (*(move + 7) == '\0')
			return ((move + 7) - str);
		move += 8;
	}
	return (move - str);
}


size_t eight_char_move_ptr_norm(const char *str) {
	const char *m = str;

	while (*m && *(m + 1)) {
		if (!*(m + 2) || !*(m + 3))
			return ((m + 2 + (!!(*(m + 2)) * 1)) - str);
		if (!*(m + 4) || !*(m + 5))
			return ((m + 4 + (!!(*(m + 4)) * 1)) - str);
		if (!*(m + 6) || !*(m + 7))
			return ((m + 6 + (!!(*(m + 6)) * 1)) - str);
		m += 8;
	}
	return ((m + (!!*m * 1)) - str);
}

size_t eight_char_counter(const char *str) {
	size_t length = 0;

	while (str[length] != '\0') {
		if (str[length + 1] == '\0')
			return (length + 1);
		if (str[length + 2] == '\0')
			return (length + 2);
		if (str[length + 3] == '\0')
			return (length + 3);
		if (str[length + 4] == '\0')
			return (length + 4);
		if (str[length + 5] == '\0')
			return (length + 5);
		if (str[length + 6] == '\0')
			return (length + 6);
		if (str[length + 7] == '\0')
			return (length + 7);
		length += 8;
	}
	return (length);
}

size_t eight_char_counter_norm(const char *str) {
	size_t len;

	len = 0;
	while (str[len] && str[len + 1]) {
		if (!str[len + 2] || !str[len + 3])
			return (len + 2 + ((!!str[len + 2]) * 1));
		if (!str[len + 4] || !str[len + 5])
			return (len + 4 + ((!!str[len + 4]) * 1));
		if (!str[len + 6] || !str[len + 7])
			return (len + 6 + ((!!str[len + 6]) * 1));
		len += 8;
	}
	return (len + (!!str[len] * 1));
}

size_t eight_char_recursive(const char *str) {
	if (*str == '\0')
		return (0);
	if (*(str + 1) == '\0')
		return (1);
	if (*(str + 2) == '\0')
		return (2);
	if (*(str + 3) == '\0')
		return (3);
	if (*(str + 4) == '\0')
		return (4);
	if (*(str + 5) == '\0')
		return (5);
	if (*(str + 6) == '\0')
		return (6);
	if (*(str + 7) == '\0')
		return (7);
	return (8 + eight_char_recursive(str + 8));
}

size_t eight_count_in_while(const char *str) {
	size_t len = 0;

	while (str[len] && str[len + 1] && str[len + 2] && str[len + 3] && str[len + 4] &&
		   str[len + 5] && str[len + 6] && str[len + 7])
		len += 8;
	while (str[len])
		len++;
	return (len);
}

size_t eight_ptr_in_while(const char *str) {
	const char *m = str;

	while (*m && *(m + 1) && *(m + 2) && *(m + 3) && *(m + 4) && *(m + 5) && *(m + 6) &&
		   *(m + 7))
		m += 8;
	while (*m)
		m++;
	return (m - str);
}


/*
	Move 16 chars per iteration
 */

size_t sixteen_char_move_ptr(const char *str) {
	const char *move = str;

	while (*move != '\0') {
		if (*(move + 1) == '\0')
			return ((move + 1) - str);
		if (*(move + 2) == '\0')
			return ((move + 2) - str);
		if (*(move + 3) == '\0')
			return ((move + 3) - str);
		if (*(move + 4) == '\0')
			return ((move + 4) - str);
		if (*(move + 5) == '\0')
			return ((move + 5) - str);
		if (*(move + 6) == '\0')
			return ((move + 6) - str);
		if (*(move + 7) == '\0')
			return ((move + 7) - str);
		if (*(move + 8) == '\0')
			return ((move + 8) - str);
		if (*(move + 9) == '\0')
			return ((move + 9) - str);
		if (*(move + 10) == '\0')
			return ((move + 10) - str);
		if (*(move + 11) == '\0')
			return ((move + 11) - str);
		if (*(move + 12) == '\0')
			return ((move + 12) - str);
		if (*(move + 13) == '\0')
			return ((move + 13) - str);
		if (*(move + 14) == '\0')
			return ((move + 14) - str);
		if (*(move + 15) == '\0')
			return ((move + 15) - str);
		move += 16;
	}
	return (move - str);
}

size_t sixteen_char_move_ptr_norm(const char *str) {
	const char *m = str;

	while (*m && *(m + 1)) {
		if (!*(m + 2) || !*(m + 3))
			return ((m + 2 + (!!(*(m + 2)) * 1)) - str);
		if (!*(m + 4) || !*(m + 5))
			return ((m + 4 + (!!(*(m + 4)) * 1)) - str);
		if (!*(m + 6) || !*(m + 7))
			return ((m + 6 + (!!(*(m + 6)) * 1)) - str);
		if (!*(m + 8) || !*(m + 9))
			return ((m + 8 + (!!(*(m + 8)) * 1)) - str);
		if (!*(m + 10) || !*(m + 11))
			return ((m + 10 + (!!(*(m + 10)) * 1)) - str);
		if (!*(m + 12) || !*(m + 13))
			return ((m + 12 + (!!(*(m + 12)) * 1)) - str);
		if (!*(m + 14) || !*(m + 15))
			return ((m + 14 + (!!(*(m + 14)) * 1)) - str);
		m += 16;
	}
	return ((m + (!!*m * 1)) - str);
}


size_t sixteen_char_counter(const char *str) {
	size_t length = 0;

	while (str[length] != '\0') {
		if (str[length + 1] == '\0')
			return (length + 1);
		if (str[length + 2] == '\0')
			return (length + 2);
		if (str[length + 3] == '\0')
			return (length + 3);
		if (str[length + 4] == '\0')
			return (length + 4);
		if (str[length + 5] == '\0')
			return (length + 5);
		if (str[length + 6] == '\0')
			return (length + 6);
		if (str[length + 7] == '\0')
			return (length + 7);
		if (str[length + 8] == '\0')
			return (length + 8);
		if (str[length + 9] == '\0')
			return (length + 9);
		if (str[length + 10] == '\0')
			return (length + 10);
		if (str[length + 11] == '\0')
			return (length + 11);
		if (str[length + 12] == '\0')
			return (length + 12);
		if (str[length + 13] == '\0')
			return (length + 13);
		if (str[length + 14] == '\0')
			return (length + 14);
		if (str[length + 15] == '\0')
			return (length + 15);
		length += 16;
	}
	return (length);
}

size_t sixteen_char_counter_norm(const char *str) {
	size_t len;

	len = 0;
	while (str[len] && str[len + 1]) {
		if (!str[len + 2] || !str[len + 3])
			return (len + 2 + ((!!str[len + 2]) * 1));
		if (!str[len + 4] || !str[len + 5])
			return (len + 4 + ((!!str[len + 4]) * 1));
		if (!str[len + 6] || !str[len + 7])
			return (len + 6 + ((!!str[len + 6]) * 1));
		if (!str[len + 8] || !str[len + 9])
			return (len + 8 + ((!!str[len + 8]) * 1));
		if (!str[len + 10] || !str[len + 11])
			return (len + 10 + ((!!str[len + 10]) * 1));
		if (!str[len + 12] || !str[len + 13])
			return (len + 12 + ((!!str[len + 12]) * 1));
		if (!str[len + 14] || !str[len + 15])
			return (len + 14 + ((!!str[len + 14]) * 1));
		len += 16;
	}
	return (len + (!!str[len] * 1));
}

size_t sixteen_char_recursive(const char *str) {
	if (*str == '\0')
		return (0);
	if (*(str + 1) == '\0')
		return (1);
	if (*(str + 2) == '\0')
		return (2);
	if (*(str + 3) == '\0')
		return (3);
	if (*(str + 4) == '\0')
		return (4);
	if (*(str + 5) == '\0')
		return (5);
	if (*(str + 6) == '\0')
		return (6);
	if (*(str + 7) == '\0')
		return (7);
	if (*(str + 8) == '\0')
		return (8);
	if (*(str + 9) == '\0')
		return (9);
	if (*(str + 10) == '\0')
		return (10);
	if (*(str + 11) == '\0')
		return (11);
	if (*(str + 12) == '\0')
		return (12);
	if (*(str + 13) == '\0')
		return (13);
	if (*(str + 14) == '\0')
		return (14);
	if (*(str + 15) == '\0')
		return (15);
	return (16 + eight_char_recursive(str + 16));
}

size_t sixteen_count_in_while(const char *str) {
	size_t len;

	len = 0;
	while (str[len] && str[len + 1] && str[len + 2] && str[len + 3] && str[len + 4] &&
		   str[len + 5] && str[len + 6] && str[len + 7] && str[len + 8] && str[len + 9] &&
		   str[len + 10] && str[len + 11] && str[len + 12] && str[len + 13] &&
		   str[len + 14] && str[len + 15])
		len += 16;
	while (str[len])
		len++;
	return (len);
}

size_t sixteen_ptr_in_while(const char *str) {
	const char *m = str;

	while (*m && *(m + 1) && *(m + 2) && *(m + 3) && *(m + 4) && *(m + 5) && *(m + 6) &&
		   *(m + 7) && *(m + 8) && *(m + 9) && *(m + 10) && *(m + 11) && *(m + 12) &&
		   *(m + 13) && *(m + 14) && *(m + 15))
		m += 16;
	while (*m)
		m++;
	return (m - str);
}
