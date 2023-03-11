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

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x57;

        test_me.move_1();

        if( test_me.registers[1] != 0x030A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_1 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF7;

        test_me.move_1();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x77;

        test_me.move_1();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x76;

        test_me.move_1();

        if( test_me.registers[0] != 0x0101'0304'0506'0708 ){

            std::cout << "Move 1 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_move_2(){
    bool test_success = true;

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x13;

        test_me.move_2();

        if( test_me.registers[1] != 0x0506'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_2 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x34;

        test_me.move_2();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x33;

        test_me.move_2();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 2 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x32;

        test_me.move_2();

        if( test_me.registers[0] != 0x0102'0102'0506'0708 ){

            std::cout << "Move 2 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_move_4(){
    bool test_success = true;

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x01;

        test_me.move_4();

        if( test_me.registers[1] != 0x0506'0708'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_1 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x12;

        test_me.move_4();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 1 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x11;

        test_me.move_1();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 4 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x10;

        test_me.move_4();

        if( test_me.registers[0] != 0x0102'0304'0102'0304 ){

            std::cout << "Move 1 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_move_8(){
    bool test_success = true;
    // this test is a little simpler because move8 has no positions, it's just a full register
    // this eliminates 2 of 4 test cases, test for invalid position, and test for mov into same position

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;

        test_me.move_8();

        if( test_me.registers[1] != 0x0102'0304'0506'0708 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 8 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;

        test_me.move_8();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Move 8 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_swap_1(){
    bool test_success = true;

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x57;

        test_me.swap_1();

        if( test_me.registers[1] != 0x030A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0904'0506'0708 ){

            std::cout << "Swap 1 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_1 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF7;

        test_me.swap_1();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 1 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x77;

        test_me.swap_1();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 1 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x76;

        test_me.swap_1();

        if( test_me.registers[0] != 0x0201'0304'0506'0708 ){

            std::cout << "Swap 1 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_swap_2(){
    bool test_success = true;

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x23;

        test_me.swap_2();

        if( test_me.registers[1] != 0x0304'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'090A'0506'0708 ){

            std::cout << "Swap 2 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_1 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF7;

        test_me.swap_2();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 2 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x33;

        test_me.swap_2();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 2 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x32;

        test_me.swap_2();

        if( test_me.registers[0] != 0x0304'0102'0506'0708 ){

            std::cout << "Swap 2 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_swap_4(){
    bool test_success = true;

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0x01;

        test_me.swap_4();

        if( test_me.registers[0] != 0x0102'0304'090A'0B0C || test_me.registers[1] != 0x0506'0708'0D0E'0F10 ){

            std::cout << "Swap 4 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//move_1 should silently fail with bad pos, all possible registers are valid, don't need to check them
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;
        test_me.main_mem[1] = 0xF7;

        test_me.swap_4();

        if( test_me.registers[1] != 0x090A'0B0C'0D0E'0F10 || test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 4 not failing on bad input!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself in the same pos - effectively no op
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x33;

        test_me.swap_4();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 4 moving incorrectly within same register and position!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a swap from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;
        test_me.main_mem[1] = 0x10;

        test_me.swap_4();

        if( test_me.registers[0] != 0x0506'0708'0102'0304 ){

            std::cout << "Swap 4 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_swap_8(){
    bool test_success = true;
    // this test is a little simpler because move8 has no positions, it's just a full register
    // this eliminates 2 of 4 test cases, test for invalid position, and test for mov into same position

    //set up involves non-trivial state, every case is a separate block.
    {//test should succeed with a move from one reg to another
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.registers[1] = 0x090A'0B0C'0D0E'0F10;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x01;

        test_me.swap_8();

        if( test_me.registers[1] != 0x0102'0304'0506'0708 || test_me.registers[0] != 0x090A'0B0C'0D0E'0F10 ){

            std::cout << "Swap 8 moving incorrectly between registers!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[1] << "\n";

            test_success = false;
        }
    }

    {//test should succeed with a move from a reg to itself
        processor test_me;

        test_me.registers[0] = 0x0102'0304'0506'0708;
        test_me.program_counter = 0;
        test_me.main_mem[0] = 0x00;

        test_me.swap_8();

        if( test_me.registers[0] != 0x0102'0304'0506'0708 ){

            std::cout << "Swap 8 moving incorrectly within same register!\n";

            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";

            test_success = false;
        }
    }

    return test_success;
}

bool test_load_1(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x05;

        for( int i = 7; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x07;

        test_me.main_mem[7] = 0xFF;

        test_me.load_1();

        if( test_me.registers[0] != 0x0000'FF00'0000'0000 ){
            std::cout << "Load 1 failed!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x08;

        for( int i = 1; i < 9; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[8] = 0x09;
        test_me.main_mem[9] = 0xFF;

        test_me.load_1();

        if( test_me.registers[0] != 0x0000'0000'0000'0000 ){
            std::cout << "Load 1 loaded register when it shouldn't!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_load_2(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x02;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x06;

        test_me.main_mem[6] = 0xFF;
        test_me.main_mem[7] = 0xFF;

        test_me.load_2();

        if( test_me.registers[0] != 0x0000'FFFF'0000'0000 ){
            std::cout << "Load 2 failed!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x04;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x06;

        test_me.main_mem[6] = 0xFF;
        test_me.main_mem[7] = 0xFF;

        test_me.load_2();

        if( test_me.registers[0] != 0x0000'0000'0000'0000 ){
            std::cout << "Load 1 loaded register when it shouldn't!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_load_4(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x04;
        test_me.main_mem[4] = 0xFF;
        test_me.main_mem[5] = 0xFF;
        test_me.main_mem[6] = 0xFF;
        test_me.main_mem[7] = 0xFF;

        test_me.load_4();

        if( test_me.registers[0] != 0xFFFF'FFFF'0000'0000 ){
            std::cout << "Load 4 loaded register when it shouldn't!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x02;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x04;
        test_me.main_mem[4] = 0xFF;
        test_me.main_mem[5] = 0xFF;
        test_me.main_mem[6] = 0xFF;
        test_me.main_mem[7] = 0xFF;

        test_me.load_4();

        if( test_me.registers[0] != 0x0000'0000'0000'0000 ){
            std::cout << "Load 1 loaded register when it shouldn't!\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
    }

    return test_success;
}

bool test_load_8(){
    bool test_success = true;

    {
        processor test_me;

        test_me.registers[0] = 0x0000'0000'0000'0000;
        test_me.program_counter = 0;

        test_me.main_mem[0] = 0x01;

        for( int i = 8; i < 15; i++ )
            test_me.main_mem[i] = 0;
        test_me.main_mem[15] = 0x10;

        test_me.main_mem[16] = 0xFF;
        test_me.main_mem[17] = 0xFF;
        test_me.main_mem[18] = 0xFF;
        test_me.main_mem[19] = 0xFF;
        test_me.main_mem[20] = 0xFF;
        test_me.main_mem[21] = 0xFF;
        test_me.main_mem[22] = 0xFF;
        test_me.main_mem[23] = 0xFF;

        test_me.load_8();

        if( test_me.registers[0] != 0xFFFF'FFFF'FFFF'FFFF ){
            std::cout << "Load 8 Loaded incorrectly\n";
            std::cout << std::hex << std::setw(16) << std::setfill('0')
             << (uint64_t) test_me.registers[0] << "\n";
            test_success = false;
        }
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
