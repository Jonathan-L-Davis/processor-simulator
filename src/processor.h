#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>

struct processor{

    uint64_t program_counter;
    uint64_t registers[16];

    unsigned char main_mem[1024*1024];

    void cycle();
    uint8_t get_program_byte();

    uint8_t get_byte(uint64_t address);
    uint16_t get_2_bytes(uint64_t address);
    uint32_t get_4_bytes(uint64_t address);
    uint64_t get_8_bytes(uint64_t address);

    void set_byte(uint64_t address, uint8_t value);
    void set_2_bytes(uint64_t address, uint16_t value);
    void set_4_bytes(uint64_t address, uint32_t value);
    void set_8_bytes(uint64_t address, uint64_t value);

    /**-------------------------- INSTRUCTIONS ---------------------------------**/
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

    /**-------------------------- MISCELLANEOUS ---------------------------------**/
    void print_registers();

};

#endif//PROCESSOR_H
