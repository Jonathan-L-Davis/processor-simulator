#include <iostream>

#include "processor.h"
#include "test/processor_tests.h"


bool is_big_endian(void)
{//thx stack overflow
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304};

    return bint.c[0] == 1;
}

//std::cout << std::hex << std::setw(16) << std::setfill('0')
//             << (uint64_t)temp_val << "\n";

void processor::print_registers(){
    for( int i = 0; i < 16; i++ )
        std::cout << std::hex << i << ": 0x" << std::setw(16) << std::setfill('0')
            << (uint64_t) registers[i] << "\n";
}

int main( int argc, char** argv ){

    bool test_success = true;
    test_success &= test_memory_setting();
    test_success &= test_memory_getting();
    test_success &= test_get_PC_bytes();
    test_success &= test_move_instructions();
    test_success &= test_swap_instructions();
    test_success &= test_load_instructions();
    test_success &= test_store_instructions();
    test_success &= test_bitwise_instructions();

    if(test_success)
        std::cout << "All tests passed! :)\n";
    else
        std::cout << "Tests failed! :(\n";


    {//*
    processor test_me;

    test_me.registers[0] = 5;
    test_me.registers[1] = 52;
    test_me.registers[2] = 0;

    test_me.program_counter = 0;
    test_me.main_mem[0] = 0x01;
    test_me.main_mem[1] = 0x22;
    test_me.main_mem[4] = 0x00;
    test_me.main_mem[5] = 0x00;
    test_me.main_mem[6] = 0x80;
    test_me.main_mem[7] = 0x00;
    test_me.multiply();

    std::cout << std::dec << test_me.registers[2] << "\n";
    std::cout << std::hex << test_me.registers[2] << "\n";//*/
    std::cout << std::dec << 5*52 << "\n";
    }

    return 0;
}
