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

    test_memory_setting();
    test_memory_getting();
    test_move_instructions();
    test_swap_instructions();
    test_load_instructions();
    test_store_instructions();


    return 0;
}
