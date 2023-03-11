#include "processor.h"

/**
-   Will add:
-       interrupts
-       control flow
-       bit-wise ops
-       arithmetic ops
**/

void processor::cycle(){

    prefix:;//don't need this label (yet), will use for prefixes
    //read instruction
    uint8_t op_code = get_byte(program_counter);
    program_counter++;

    switch( (op_code&0xF0)>> 4 ){
        case 0x0:{}break;

        case 0x1:{}break;

        case 0x2:{}break;

        case 0x3:{}break;

        case 0x4:{}break;

        case 0x5:{/** MEMORY **/
            switch(op_code&0xF){
                case 0x0:{
                    move_1();
                }break;
                case 0x1:{
                    move_2();
                }break;
                case 0x2:{
                    move_4();
                }break;
                case 0x3:{
                    move_8();
                }break;
                case 0x4:{
                    swap_1();
                }break;
                case 0x5:{
                    swap_2();
                }break;
                case 0x6:{
                    swap_4();
                }break;
                case 0x7:{
                    swap_8();
                }break;
                case 0x8:{
                    load_1();
                }break;
                case 0x9:{
                    load_2();
                }break;
                case 0xA:{
                    load_4();
                }break;
                case 0xB:{
                    load_8();
                }break;
                case 0xC:{
                    store_1();
                }break;
                case 0xD:{
                    store_2();
                }break;
                case 0xE:{
                    store_4();
                }break;
                case 0xF:{
                    store_8();
                }break;
            }

        }break;

        case 0x6:{}break;

        case 0x7:{}break;

        case 0x8:{}break;

        case 0x9:{}break;

        case 0xA:{}break;

        case 0xB:{}break;

        case 0xC:{}break;

        case 0xD:{}break;

        case 0xE:{}break;

        case 0xF:{}break;
    }
}


uint8_t processor::get_program_byte(){
    uint8_t byte = get_byte(program_counter);
    program_counter++;
    return byte;//not always an opcode
}

uint16_t processor::get_2_PC_bytes(){
    uint16_t dual = get_byte(program_counter+sizeof(dual)-1);
    program_counter+=sizeof(dual);
    program_counter &= ~uint64_t(sizeof(dual)-1);
    return dual;//not always an opcode
}

uint32_t processor::get_4_PC_bytes(){
    uint32_t quad = get_byte(program_counter+sizeof(quad)-1);
    program_counter+=sizeof(quad);
    program_counter &= ~uint64_t(sizeof(quad)-1);
    return quad;//not always an opcode
}

uint64_t processor::get_8_PC_bytes(){
    uint64_t oct = get_byte(program_counter+sizeof(oct)-1);
    program_counter+=sizeof(oct);
    program_counter &= ~uint64_t(sizeof(oct)-1);
    return oct;//not always an opcode
}

/// all of the (g/s)et_#X#_byte(s) functions have the same internals
/// meant for easier debugging/maintenance
void processor::set_byte(uint64_t address, uint8_t value){
    uint64_t start_address = address&~(sizeof(value)-1);
    uint64_t size = sizeof(value);

    for( uint64_t i = 0; i < size; i++ ){
        main_mem[start_address+i] = uint8_t( value >> 8*( size-i-1 ) );
    }
}

void processor::set_2_bytes(uint64_t address, uint16_t value){
    uint64_t start_address = address&~(sizeof(value)-1);
    uint64_t size = sizeof(value);

    for( uint64_t i = 0; i < size; i++ ){
        main_mem[start_address+i] = uint8_t( value >> 8*( size-i-1 ) );
    }
}

void processor::set_4_bytes(uint64_t address, uint32_t value){
    uint64_t start_address = address&~(sizeof(value)-1);
    uint64_t size = sizeof(value);

    for( uint64_t i = 0; i < size; i++ ){
        main_mem[start_address+i] = uint8_t( value >> 8*( size-i-1 ) );
    }
}

void processor::set_8_bytes(uint64_t address, uint64_t value){
    uint64_t start_address = address&~(sizeof(value)-1);
    uint64_t size = sizeof(value);

    for( uint64_t i = 0; i < size; i++ ){
        main_mem[start_address+i] = uint8_t( value >> 8*( size-i-1 ) );
    }
}

uint8_t processor::get_byte(uint64_t address){
    uint8_t ret_me = 0;//only unique line, don't touch

    uint64_t start_address = address&~(sizeof(ret_me)-1);
    uint64_t size = sizeof(ret_me);

    for( uint64_t i = 0; i < size; i++ ){
        ret_me |= (decltype(ret_me))( main_mem[start_address+i] ) << 8*(size-i-1) ;
    }

    return ret_me;
}

uint16_t processor::get_2_bytes(uint64_t address){
    uint16_t ret_me = 0;//only unique line, don't touch

    uint64_t start_address = address&~(sizeof(ret_me)-1);
    uint64_t size = sizeof(ret_me);

    for( uint64_t i = 0; i < size; i++ ){
        ret_me |= (decltype(ret_me))( main_mem[start_address+i] ) << 8*(size-i-1) ;
    }

    return ret_me;
}

uint32_t processor::get_4_bytes(uint64_t address){
    uint32_t ret_me = 0;//only unique line, don't touch

    uint64_t start_address = address&~(sizeof(ret_me)-1);
    uint64_t size = sizeof(ret_me);

    for( uint64_t i = 0; i < size; i++ ){
        ret_me |= (decltype(ret_me))( main_mem[start_address+i] ) << 8*(size-i-1) ;
    }

    return ret_me;
}

uint64_t processor::get_8_bytes(uint64_t address){
    uint64_t ret_me = 0;//only unique line, don't touch

    uint64_t start_address = address&~(sizeof(ret_me)-1);
    uint64_t size = sizeof(ret_me);

    for( uint64_t i = 0; i < size; i++ ){
        ret_me |= (decltype(ret_me))( main_mem[start_address+i] ) << 8*(size-i-1) ;
    }

    return ret_me;
}
