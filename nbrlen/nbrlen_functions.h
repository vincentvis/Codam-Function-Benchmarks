#pragma once

#include <stdint.h>

int nbrlen_base10_loop(uint64_t number);
int nbrlen_base10_if(uint64_t number);
int nbrlen_baseN_loop(uint64_t number, uint64_t base);
int nbrlen_baseN_if_1(uint64_t number, uint64_t b);
int nbrlen_baseN_if_2(uint64_t number, uint64_t base);
