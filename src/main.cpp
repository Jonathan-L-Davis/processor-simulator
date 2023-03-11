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
    test_success &= test_bitwise();

    if(test_success)
        std::cout << "All tests passed! :)\n";
    else
        std::cout << "Tests failed! :(\n";


    return 0;
}
