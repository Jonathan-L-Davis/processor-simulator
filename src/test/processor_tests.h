#ifndef PROCESSOR_TESTS_H
#define PROCESSOR_TESTS_H

#include "processor.h"
#include <iostream>
#include <iomanip>

bool test_memory_setting();
bool test_memory_getting();
bool test_get_PC_bytes();

bool test_memory_instructions();

bool test_move_instructions();
bool test_swap_instructions();
bool test_load_instructions();
bool test_store_instructions();

bool test_move_1();
bool test_move_2();
bool test_move_4();
bool test_move_8();

bool test_swap_1();
bool test_swap_2();
bool test_swap_4();
bool test_swap_8();

bool test_load_1();
bool test_load_2();
bool test_load_4();
bool test_load_8();

bool test_store_1();
bool test_store_2();
bool test_store_4();
bool test_store_8();

bool test_bitwise_instructions();

bool test_bit_and();
bool test_bit_or();
bool test_bit_nand();
bool test_bit_nor();
bool test_bit_xor();
bool test_bit_xnor();
bool test_bit_not();
bool test_shift_left();
bool test_shift_right();
bool test_rotate_left();
bool test_rotate_right();

#endif//PROCESSOR_TESTS_H
