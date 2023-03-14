#include "test/processor_tests.h"

bool test_move_instructions(){
    bool test_success = true;

    test_success &= test_move_1();
    test_success &= test_move_2();
    test_success &= test_move_4();
    test_success &= test_move_8();


    return test_success;
}

bool test_swap_instructions(){
    bool test_success = true;

    test_success &= test_swap_1();
    test_success &= test_swap_2();
    test_success &= test_swap_4();
    test_success &= test_swap_8();


    return test_success;
}

bool test_load_instructions(){
    bool test_success = true;

    test_success &= test_load_1();
    test_success &= test_load_2();
    test_success &= test_load_4();
    test_success &= test_load_8();


    return test_success;
}

bool test_store_instructions(){
    bool test_success = true;

    test_success &= test_store_1();
    test_success &= test_store_2();
    test_success &= test_store_4();
    test_success &= test_store_8();


    return test_success;
}

bool test_move_1(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t src_reg = (i>>12)&0xF;
        uint8_t dst_reg = (i>>8)&0xF;

        uint8_t src_pos = (i>>4)&0x7;
        uint8_t dst_pos = (i>>0)&0x7;

        test_me.registers[dst_reg] = 0;
        test_me.registers[src_reg] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        test_me.move_1();

        if( uint8_t( test_me.registers[dst_reg] >> (8*dst_pos) ) != uint8_t( test_me.registers[src_reg] >> (8*src_pos) ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "move_1 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_move_2(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t src_reg = (i>>12)&0xF;
        uint8_t dst_reg = (i>>8)&0xF;

        uint8_t src_pos = (i>>4)&0x3;
        uint8_t dst_pos = (i>>0)&0x3;

        test_me.registers[dst_reg] = 0;
        test_me.registers[src_reg] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        test_me.move_2();

        if( uint16_t( test_me.registers[dst_reg] >> (16*dst_pos) ) != uint16_t( test_me.registers[src_reg] >> (16*src_pos) ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "move_2 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_move_4(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t src_reg = (i>>12)&0xF;
        uint8_t dst_reg = (i>>8)&0xF;

        uint8_t src_pos = (i>>4)&0x1;
        uint8_t dst_pos = (i>>0)&0x1;

        test_me.registers[dst_reg] = 0;
        test_me.registers[src_reg] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        test_me.move_4();

        if( uint32_t( test_me.registers[dst_reg] >> (32*dst_pos) ) != uint32_t( test_me.registers[src_reg] >> (32*src_pos) ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "move_4 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_move_8(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t src_reg = (i>>12)&0xF;
        uint8_t dst_reg = (i>>8)&0xF;

        test_me.registers[dst_reg] = 0;
        test_me.registers[src_reg] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        test_me.move_4();

        if( test_me.registers[dst_reg] != test_me.registers[src_reg] ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "move_8 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_swap_1(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg_1 = (i>>12)&0xF;
        uint8_t reg_2 = (i>>8)&0xF;

        uint8_t pos_1 = (i>>4)&0x7;
        uint8_t pos_2 = (i>>0)&0x7;

        test_me.registers[reg_2] = 0x100F'0E0D'0C0B'0A09;
        test_me.registers[reg_1] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        uint8_t reg_1_result = test_me.registers[reg_2]>>(8*pos_2);
        uint8_t reg_2_result = test_me.registers[reg_1]>>(8*pos_1);

        test_me.swap_1();

        if( ( uint8_t( test_me.registers[reg_1] >> (8*pos_1) ) != reg_1_result ) || ( uint8_t( test_me.registers[reg_2] >> (8*pos_2) ) != reg_2_result ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "swap_1 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_swap_2(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg_1 = (i>>12)&0xF;
        uint8_t reg_2 = (i>>8)&0xF;

        uint8_t pos_1 = (i>>4)&0x3;
        uint8_t pos_2 = (i>>0)&0x3;

        test_me.registers[reg_2] = 0x100F'0E0D'0C0B'0A09;
        test_me.registers[reg_1] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        uint16_t reg_1_result = test_me.registers[reg_2]>>(16*pos_2);
        uint16_t reg_2_result = test_me.registers[reg_1]>>(16*pos_1);

        test_me.swap_2();

        if( ( uint16_t( test_me.registers[reg_1] >> (16*pos_1) ) != reg_1_result ) || ( uint16_t( test_me.registers[reg_2] >> (16*pos_2) ) != reg_2_result ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "swap_2 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_swap_4(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFFFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg_1 = (i>>12)&0xF;
        uint8_t reg_2 = (i>>8)&0xF;

        uint8_t pos_1 = (i>>4)&0x1;
        uint8_t pos_2 = (i>>0)&0x1;

        test_me.registers[reg_2] = 0x100F'0E0D'0C0B'0A09;
        test_me.registers[reg_1] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);
        test_me.main_mem[1] = uint8_t(i);

        uint32_t reg_1_result = test_me.registers[reg_2]>>(32*pos_2);
        uint32_t reg_2_result = test_me.registers[reg_1]>>(32*pos_1);

        test_me.swap_4();

        if( ( uint32_t( test_me.registers[reg_1] >> (32*pos_1) ) != reg_1_result ) || ( uint32_t( test_me.registers[reg_2] >> (32*pos_2) ) != reg_2_result ) ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "swap_4 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_swap_8(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg_1 = (i>>12)&0xF;
        uint8_t reg_2 = (i>>8)&0xF;

        test_me.registers[reg_2] = 0x100F'0E0D'0C0B'0A09;
        test_me.registers[reg_1] = 0x0807'0605'0403'0201;

        test_me.main_mem[0] = uint8_t(i>>8);

        uint64_t reg_1_result = test_me.registers[reg_2];
        uint64_t reg_2_result = test_me.registers[reg_1];

        test_me.swap_8();

        if( test_me.registers[reg_1] != reg_1_result || test_me.registers[reg_2] != reg_2_result ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "swap_8 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_load_1(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg = (i>>4)&0xF;
        uint8_t pos = (i)&0x7;

        test_me.main_mem[0] = uint8_t(i);

        for( uint32_t addr = 8; addr < 15; addr++)
            test_me.main_mem[addr] = 0;
        test_me.main_mem[15] = 16;

        test_me.main_mem[16] = 0xFF;

        test_me.registers[reg] = 0;
        uint64_t reg_result = 0|uint64_t(0xFF)<<(8*pos);

        test_me.load_1();

        if( test_me.registers[reg] != reg_result ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "load_1 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_load_2(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg = (i>>4)&0xF;
        uint8_t pos = (i)&0x3;

        test_me.main_mem[0] = uint8_t(i);

        for( uint32_t addr = 8; addr < 15; addr++)
            test_me.main_mem[addr] = 0;
        test_me.main_mem[15] = 16;

        test_me.main_mem[16] = 0xFF;
        test_me.main_mem[17] = 0xFF;

        test_me.registers[reg] = 0;
        uint64_t reg_result = 0|uint64_t(0xFFFF)<<(16*pos);

        test_me.load_2();

        if( test_me.registers[reg] != reg_result ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "load_2 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_load_4(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg = (i>>4)&0xF;
        uint8_t pos = (i)&0x1;

        test_me.main_mem[0] = uint8_t(i);

        for( uint32_t addr = 8; addr < 15; addr++)
            test_me.main_mem[addr] = 0;
        test_me.main_mem[15] = 16;

        test_me.main_mem[16] = 0xFF;
        test_me.main_mem[17] = 0xFF;
        test_me.main_mem[18] = 0xFF;
        test_me.main_mem[19] = 0xFF;

        test_me.registers[reg] = 0;
        uint64_t reg_result = 0|uint64_t(0xFFFF'FFFF)<<(32*pos);

        test_me.load_4();

        if( test_me.registers[reg] != reg_result ){
            num_test_failures++;
            test_success = false;
        }

    }

    if( !test_success ){
        std::cout << "load_4 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_load_8(){
    bool test_success = true;
    uint32_t num_test_failures = 0;

    for(uint32_t i = 0; i <= 0xFF; i++){
        //set up
        processor test_me;
        test_me.program_counter = 0;

        uint8_t reg = (i>>4)&0xF;
        uint8_t pos = (i)&0x1;

        test_me.main_mem[0] = uint8_t(i);

        for( uint32_t addr = 8; addr < 15; addr++)
            test_me.main_mem[addr] = 0;
        test_me.main_mem[15] = 16;

        test_me.main_mem[16] = 0xFF;
        test_me.main_mem[17] = 0xFF;
        test_me.main_mem[18] = 0xFF;
        test_me.main_mem[19] = 0xFF;
        test_me.main_mem[20] = 0xFF;
        test_me.main_mem[21] = 0xFF;
        test_me.main_mem[22] = 0xFF;
        test_me.main_mem[23] = 0xFF;

        test_me.registers[reg] = 0;
        uint64_t reg_result = 0xFFFF'FFFF'FFFF'FFFF;

        test_me.load_8();

        if( test_me.registers[reg] != reg_result ){
            num_test_failures++;
            test_success = false;

            std::cout << (unsigned int) reg << ": " << (unsigned int) pos << ": " << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[reg] << ":" << std::setw(16) << std::setfill('0') << reg_result << "\n\n";
        }

    }

    if( !test_success ){
        std::cout << "load_4 failed unit testing " << num_test_failures << " times!\n";
    }

    return test_success;
}

bool test_store_1(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x07;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_1();

        if( test_me.get_byte(0) != 0x08 ){
            std::cout << "Store 1 loaded register when it shouldn't!\n";
            std::cout << std::hex << std::setw(2) << std::setfill('0')
             << (uint64_t) test_me.get_byte(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }
    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x08;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_1();

        if( test_me.get_byte(0) != 0x08 ){
            std::cout << "Store 1 stored register when it shouldn't!\n";
            std::cout << std::hex << std::setw(2) << std::setfill('0')
             << (uint64_t) test_me.get_byte(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_store_2(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x03;
        test_me.main_mem[1] = 0x00;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_2();

        if( test_me.get_2_bytes(0) != 0x0807 ){
            std::cout << "Store 2 stored register incorrectly!\n";
            std::cout << std::hex << std::setw(4) << std::setfill('0')
             << (uint64_t) test_me.get_2_bytes(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }
    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x04;
        test_me.main_mem[1] = 0x00;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_2();

        if( test_me.get_2_bytes(0) != 0x0400 ){
            std::cout << "Store 2 stored register when it shouldn't!\n";
            std::cout << std::hex << std::setw(4) << std::setfill('0')
             << (uint64_t) test_me.get_2_bytes(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_store_4(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x00;
        test_me.main_mem[2] = 0x00;
        test_me.main_mem[3] = 0x00;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_4();

        if( test_me.get_4_bytes(0) != 0x0807'0605 ){
            std::cout << "Store 4 stored register incorrectly!\n";
            std::cout << std::hex << std::setw(8) << std::setfill('0')
             << (uint64_t) test_me.get_4_bytes(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }
    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x02;
        test_me.main_mem[1] = 0x00;
        test_me.main_mem[2] = 0x00;
        test_me.main_mem[3] = 0x00;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_4();

        if( test_me.get_4_bytes(0) != 0x0200'0000 ){
            std::cout << "Store 4 stored register when it shouldn't!\n";
            std::cout << std::hex << std::setw(8) << std::setfill('0')
             << (uint64_t) test_me.get_4_bytes(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_store_8(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0807'0605'0403'0201;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x00;
        test_me.main_mem[2] = 0x00;
        test_me.main_mem[3] = 0x00;
        test_me.main_mem[4] = 0x00;
        test_me.main_mem[5] = 0x00;
        test_me.main_mem[6] = 0x00;
        test_me.main_mem[7] = 0x00;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x00;

        test_me.store_8();

        if( test_me.get_8_bytes(0) != 0x0807'0605'0403'0201 ){
            std::cout << "Store 4 stored register incorrectly!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.get_8_bytes(0) << "\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_bitwise(){
    bool test_success = true;

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_and();

        if( test_me.registers[2] != 0xAAAA'AAAA'AAAA'AAAA ){
            std::cout << "bit_and failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_and();

        if( test_me.registers[0] != 0xAAAA'AAAA'AAAA'AAAA ){
            std::cout << "bit_and failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_or();

        if( test_me.registers[2] != 0xFFFF'FFFF'FFFF'FFFF ){
            std::cout << "bit_or failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_or();

        if( test_me.registers[0] != 0xFFFF'FFFF'FFFF'FFFF ){
            std::cout << "bit_or failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_nand();

        if( test_me.registers[2] != 0x5555'5555'5555'5555 ){
            std::cout << "bit_nand failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_nand();

        if( test_me.registers[0] != 0x5555'5555'5555'5555 ){
            std::cout << "bit_nand failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_nor();

        if( test_me.registers[2] != 0 ){
            std::cout << "bit_nor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'FFFF'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_nor();

        if( test_me.registers[0] != 0 ){
            std::cout << "bit_nor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'0000'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_xor();

        if( test_me.registers[2] != 0x5555'5555'AAAA'5555 ){
            std::cout << "bit_xor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'0000'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_xor();

        if( test_me.registers[0] != 0x5555'5555'AAAA'5555 ){
            std::cout << "bit_xor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;

        if(false){
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'0000'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF2;

        test_me.bit_xnor();

        if( test_me.registers[2] != 0xAAAA'AAAA'5555'AAAA ){
            std::cout << "bit_xnor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'FFFF'0000'FFFF;
        test_me.registers[1] = 0xAAAA'AAAA'AAAA'AAAA;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF0;

        test_me.bit_xnor();

        if( test_me.registers[0] != 0xAAAA'AAAA'5555'AAAA ){
            std::cout << "bit_xnor failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;

        test_me.bit_not();

        if( test_me.registers[1] != 0x0000'FFFF'0000'FFFF ){
            std::cout << "bit_not failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x00;

        test_me.bit_not();

        if( test_me.registers[0] != 0x0000'FFFF'0000'FFFF ){
            std::cout << "bit_not failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x08;

        test_me.shift_left();

        if( test_me.registers[1] != 0xFF00'00FF'FF00'0000 ){
            std::cout << "left_shift failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x08;

        test_me.shift_left();

        if( test_me.registers[0] != 0xFF00'00FF'FF00'0000 ){
            std::cout << "left_shift failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x08;

        test_me.shift_right();

        if( test_me.registers[1] != 0x00FF'FF00'00FF'FF00 ){
            std::cout << "right_shift failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xFFFF'0000'FFFF'0000;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x08;

        test_me.shift_right();

        if( test_me.registers[0] != 0x00FF'FF00'00FF'FF00 ){
            std::cout << "right_shift failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xCDEF'0123'4567'89AB;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x08;

        test_me.rotate_left();

        if( test_me.registers[1] != 0xEF01'2345'6789'ABCD ){
            std::cout << "rotate_left failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xCDEF'0123'4567'89AB;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x08;

        test_me.rotate_left();

        if( test_me.registers[0] != 0xEF01'2345'6789'ABCD ){
            std::cout << "rotate_left failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xCDEF'0123'4567'89AB;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x08;

        test_me.rotate_right();

        if( test_me.registers[1] != 0xABCD'EF01'2345'6789 ){
            std::cout << "rotate_right failed\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.registers[0] = 0xCDEF'0123'4567'89AB;

        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x08;

        test_me.rotate_right();

        if( test_me.registers[0] != 0xABCD'EF01'2345'6789 ){
            std::cout << "rotate_right failed\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_memory_setting(){

    bool test_success = true;

    processor test_me;


    //test all 4 sizes
        //test if each size moves to the correct bytes and maintains big-endianness

    test_me.set_byte(0,0x01);
    if( test_me.main_mem[0] != 0x01 ){
        std::cout << "Moved single byte to wrong spot\n";
        std::cout << (int) test_me.main_mem[0] << "\n";
        test_success = false;
    }

    test_me.set_2_bytes(8,0x0102);
    if( test_me.main_mem[8] != 0x01 && test_me.main_mem[9] != 0x02 ){
        std::cout << "Moved 2 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[8] << " " << (int) test_me.main_mem[9] << "\n";
        test_success = false;
    }

    test_me.set_2_bytes(11,0x0102);
    if( test_me.main_mem[10] != 0x01 && test_me.main_mem[11] != 0x02 ){
        std::cout << "Moved 2 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[10] << " " << (int) test_me.main_mem[11] << "\n";
        test_success = false;
    }

    test_me.set_4_bytes(16,0x0102'0304);
    if( test_me.main_mem[16] != 0x01 && test_me.main_mem[17] != 0x02 &&
        test_me.main_mem[18] != 0x03 && test_me.main_mem[19] != 0x04 ){
        std::cout << "Moved 4 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[16] << " " << (int) test_me.main_mem[17] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[18] << " " << (int) test_me.main_mem[19] << "\n";
        test_success = false;
    }

    test_me.set_4_bytes(22,0x0102'0304);
    if( test_me.main_mem[20] != 0x01 && test_me.main_mem[21] != 0x02 &&
        test_me.main_mem[22] != 0x03 && test_me.main_mem[23] != 0x04 ){
        std::cout << "Moved 4 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[20] << " " << (int) test_me.main_mem[21] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[22] << " " << (int) test_me.main_mem[23] << "\n";
        test_success = false;
    }

    test_me.set_8_bytes(24,0x0102'0304'0506'0708);
    if( test_me.main_mem[24] != 0x01 && test_me.main_mem[25] != 0x02 &&
        test_me.main_mem[26] != 0x03 && test_me.main_mem[27] != 0x04 &&
        test_me.main_mem[28] != 0x05 && test_me.main_mem[29] != 0x06 &&
        test_me.main_mem[30] != 0x07 && test_me.main_mem[31] != 0x08  ){
        std::cout << "Moved 8 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[24] << " " << (int) test_me.main_mem[25] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[26] << " " << (int) test_me.main_mem[27] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[28] << " " << (int) test_me.main_mem[29] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[30] << " " << (int) test_me.main_mem[31] << "\n";
        test_success = false;
    }

    test_me.set_8_bytes(39,0x0102'0304'0506'0708);
    if( test_me.main_mem[32] != 0x01 && test_me.main_mem[33] != 0x02 &&
        test_me.main_mem[34] != 0x03 && test_me.main_mem[35] != 0x04 &&
        test_me.main_mem[36] != 0x05 && test_me.main_mem[37] != 0x06 &&
        test_me.main_mem[38] != 0x07 && test_me.main_mem[39] != 0x08  ){
        std::cout << "Moved 8 bytes to wrong spot\n";
        std::cout << std::hex << (int) test_me.main_mem[32] << " " << (int) test_me.main_mem[33] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[34] << " " << (int) test_me.main_mem[35] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[36] << " " << (int) test_me.main_mem[37] << "\n";
        std::cout << std::hex << (int) test_me.main_mem[38] << " " << (int) test_me.main_mem[39] << "\n";
        test_success = false;
    }

    return test_success;

}

bool test_memory_getting(){
    bool test_success = true;

    processor test_me;



    //test all 4 sizes
        //test if each size moves from the correct bytes and maintains big-endianness

        //for each size there are 2 tests, one tests an aligned address, the other tests an unaligned address

        //proper behavior is to ignore bits smaller than the size, so a 4 byte value can only start on a multiple of 4 address, etc.

    //only one test for 1 byte, don't care about alignment for single bytes, may bite us, not likely
    test_me.main_mem[0] = 0x01;
    if( int result = test_me.get_byte(0) != 0x01 ){
        std::cout << "Retrieved 1 byte wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    test_me.main_mem[8] = 0x01;
    test_me.main_mem[9] = 0x02;
    if( uint16_t result = test_me.get_2_bytes(8) != 0x0102 ){
        std::cout << "Retrieved 2 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    test_me.main_mem[10] = 0x01;
    test_me.main_mem[11] = 0x02;
    if( uint16_t result = test_me.get_2_bytes(11) != 0x0102 ){
        std::cout << "Retrieved 2 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }



    test_me.main_mem[16] = 0x01;
    test_me.main_mem[17] = 0x02;
    test_me.main_mem[18] = 0x03;
    test_me.main_mem[19] = 0x04;
    if( uint16_t result = test_me.get_4_bytes(16) != 0x0102'0304 ){
        std::cout << "Retrieved 4 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    test_me.main_mem[20] = 0x01;
    test_me.main_mem[21] = 0x02;
    test_me.main_mem[22] = 0x03;
    test_me.main_mem[23] = 0x04;
    if( uint16_t result = test_me.get_4_bytes(22) != 0x0102'0304 ){
        std::cout << "Retrieved 4 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    test_me.main_mem[24] = 0x01;
    test_me.main_mem[25] = 0x02;
    test_me.main_mem[26] = 0x03;
    test_me.main_mem[27] = 0x04;
    test_me.main_mem[28] = 0x05;
    test_me.main_mem[29] = 0x06;
    test_me.main_mem[30] = 0x07;
    test_me.main_mem[31] = 0x08;
    if( uint16_t result = test_me.get_8_bytes(24) != 0x0102'0304'0506'0708 ){
        std::cout << "Retrieved 8 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    test_me.main_mem[32] = 0x01;
    test_me.main_mem[33] = 0x02;
    test_me.main_mem[34] = 0x03;
    test_me.main_mem[35] = 0x04;
    test_me.main_mem[36] = 0x05;
    test_me.main_mem[37] = 0x06;
    test_me.main_mem[38] = 0x07;
    test_me.main_mem[39] = 0x08;
    if( uint16_t result = test_me.get_8_bytes(29) != 0x0102'0304'0506'0708 ){
        std::cout << "Retrieved 8 bytes wrong\n";
        std::cout << std::hex << (int) result << "\n";
        test_success = false;
    }

    return test_success;
}


bool test_get_PC_bytes(){
    bool test_success = true;

    {
        processor test_me;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint8_t byte = test_me.get_program_byte();

        if( byte != 0x01){
            std::cout << "Function \"get_program_byte()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint16_t dual = test_me.get_2_PC_bytes();

        if( dual != 0x0102){
            std::cout << "Function \"get_2_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 1;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint16_t dual = test_me.get_2_PC_bytes();

        if( dual != 0x0102){
            std::cout << "Function \"get_2_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint32_t quad = test_me.get_4_PC_bytes();

        if( quad != 0x01020304){
            std::cout << "Function \"get_4_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 1;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint32_t quad = test_me.get_4_PC_bytes();

        if( quad != 0x01020304){
            std::cout << "Function \"get_4_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint64_t oct = test_me.get_8_PC_bytes();

        if( oct != 0x0102030405060708){
            std::cout << "Function \"get_8_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    {
        processor test_me;
        test_me.program_counter = 1;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x02;
        test_me.main_mem[2] = 0x03;
        test_me.main_mem[3] = 0x04;
        test_me.main_mem[4] = 0x05;
        test_me.main_mem[5] = 0x06;
        test_me.main_mem[6] = 0x07;
        test_me.main_mem[7] = 0x08;

        uint64_t oct = test_me.get_8_PC_bytes();

        if( oct != 0x0102030405060708){
            std::cout << "Function \"get_8_PC_bytes()\" not working correctly!\n";
            test_success = false;
        }
    }

    return test_success;
}
