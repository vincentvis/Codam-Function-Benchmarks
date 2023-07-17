#pragma once

#include <stddef.h>

size_t ft_strlen_asm(const char *str);

size_t one_char_move_ptr(const char *str);
size_t one_char_counter(const char *str);
size_t one_char_recursive(const char *str);

size_t two_char_move_ptr(const char *str);
size_t two_char_counter(const char *str);
size_t two_char_recursive(const char *str);

size_t four_char_move_ptr(const char *str);
size_t four_char_move_ptr_norm(const char *str);
size_t four_char_counter(const char *str);
size_t four_char_unroll_alt(const char *str);
size_t four_char_recursive(const char *str);

size_t eight_char_move_ptr(const char *str);
size_t eight_char_move_ptr_norm(const char *str);
size_t eight_char_counter(const char *str);
size_t eight_char_counter_norm(const char *str);
size_t eight_count_in_while(const char *str);
size_t eight_ptr_in_while(const char *str);
size_t eight_char_recursive(const char *str);

size_t sixteen_char_move_ptr(const char *str);
size_t sixteen_char_move_ptr_norm(const char *str);
size_t sixteen_char_counter(const char *str);
size_t sixteen_char_counter_norm(const char *str);
size_t sixteen_count_in_while(const char *str);
size_t sixteen_ptr_in_while(const char *str);
size_t sixteen_char_recursive(const char *str);
