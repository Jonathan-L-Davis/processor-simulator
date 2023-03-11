#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>

struct processor{

    uint64_t program_counter;
    uint64_t registers[16];

    unsigned char main_mem[1024*1024];

    void cycle();
    uint8_t get_program_byte();
    uint16_t get_2_PC_bytes();
    uint32_t get_4_PC_bytes();
    uint64_t get_8_PC_bytes();

    uint8_t get_byte(uint64_t address);
    uint16_t get_2_bytes(uint64_t address);
    uint32_t get_4_bytes(uint64_t address);
    uint64_t get_8_bytes(uint64_t address);

    void set_byte(uint64_t address, uint8_t value);
    void set_2_bytes(uint64_t address, uint16_t value);
    void set_4_bytes(uint64_t address, uint32_t value);
    void set_8_bytes(uint64_t address, uint64_t value);

    /**-------------------------- INSTRUCTIONS ---------------------------------**/
    /**--- MEMORY ---**/
    void move_1();
    void move_2();
    void move_4();
    void move_8();
    void swap_1();
    void swap_2();
    void swap_4();
    void swap_8();
    void load_1();
    void load_2();
    void load_4();
    void load_8();
    void store_1();
    void store_2();
    void store_4();
    void store_8();
    /**--- Control Flow ---**/
    /// "Absolute" Jumps
    //relative to program start position
    void absolute_jump();
    void absolute_jump_equal_0();
    void absolute_jump_not_equal_0();
    void absolute_jump_positive();
    void absolute_jump_negative();
    void absolute_jump_not_positive();
    void absolute_jump_not_negative();
    void absolute_jump_equal();
    void absolute_jump_not_equal();
    void absolute_jump_greater();
    void absolute_jump_less();
    void absolute_jump_greater_equal();
    void absolute_jump_less_equal();
    /// Relative Jumps - may just be implemented via a flag for jumps
    // relative to jump instruction
    void relative_jump();
    void relative_jump_equal_0();
    void relative_jump_not_equal_0();
    void relative_jump_positive();
    void relative_jump_negative();
    void relative_jump_not_positive();
    void relative_jump_not_negative();
    void relative_jump_equal();
    void relative_jump_not_equal();
    void relative_jump_greater();
    void relative_jump_less();
    void relative_jump_greater_equal();
    void relative_jump_less_equal();
    /**--- Arithmetic ---**/
    void add();
    void subtract();
    void increment();
    void decrement();
    void negate();
    void multiply();
    void divide();
    /**--- Bit-Wise ---**/
    void bit_and();
    void bit_or();
    void bit_nand();
    void bit_nor();
    void bit_xor();
    void bit_not();
    void shift_left();
    void shift_right();
    void rotate_left();
    void rotate_right();

    /**-------------------------- MISCELLANEOUS ---------------------------------**/
    void print_registers();

};

#endif//PROCESSOR_H
