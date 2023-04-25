#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>

struct processor{

    uint64_t program_counter;
    uint64_t registers[16];

    unsigned char main_mem[1024];

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
    /** impl ✓ : test ✓ **/
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
    /** impl ✓ : test ✗ **/
    void jump();
    void conditional_jump();
    /**--- Arithmetic ---**/
    /** impl ✗ : test ✗ **/
    void add();
    void subtract();
    void increment();
    void decrement();
    void negate();//✗
    void multiply();//✗
    void divide();//✗
    /**--- Bit-Wise ---**/
    /** impl ✓ : test ✓ **/
    void bit_and();
    void bit_or();
    void bit_nand();
    void bit_nor();
    void bit_xor();
    void bit_xnor();
    void bit_not();
    void shift_left();
    void shift_right();
    void rotate_left();
    void rotate_right();

    /**-------------------------- MISCELLANEOUS ---------------------------------**/
    void print_registers();

};

#endif//PROCESSOR_H
