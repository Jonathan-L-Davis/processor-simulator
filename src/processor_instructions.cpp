#include "processor.h"

#include <iostream>
#include <iomanip>

void processor::move_1(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t src_reg = (reg >> 4)&0xF;
    uint8_t dst_reg = reg&0xF;

    uint8_t src_pos = (pos >> 4)&0x7;
    uint8_t dst_pos = pos&0x7;

    /// erase bits in the destination position
    uint64_t temp_val = (registers[dst_reg]&~( uint64_t(0xFF)<<(8*dst_pos)) );

    /// triple shift avoids branching - other wise negative shifts are occaisonally needed,
    /// this gets the src byte, shifts it back to 0 pos, then shifts it to destination position.
    /// this method avoids integer arithmetic and branching to handle relative left or right moves
    temp_val |= (registers[src_reg]&( uint64_t(0xFF)<<(8*src_pos)) )>>(8*src_pos) <<(8*dst_pos);

    registers[dst_reg] = temp_val;

}

void processor::move_2(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t src_reg = (reg >> 4)&0xF;
    uint8_t dst_reg = reg&0xF;

    uint8_t src_pos = (pos >> 4)&0x3;
    uint8_t dst_pos = pos&0x3;

    /// erase bits in the destination position
    uint64_t temp_val = (registers[dst_reg]&~( uint64_t(0xFFFF)<<(16*dst_pos)) );

    /// triple shift avoids branching - other wise negative shifts are occaisonally needed,
    /// this gets the src byte, shifts it back to 0 pos, then shifts it to destination position.
    /// this method avoids integer arithmetic and branching to handle relative left or right moves
    temp_val |= (registers[src_reg]&( uint64_t(0xFFFF)<<(16*src_pos)) )>>(16*src_pos) <<(16*dst_pos);

    registers[dst_reg] = temp_val;

}

void processor::move_4(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t src_reg = (reg >> 4)&0xF;
    uint8_t dst_reg = reg&0xF;

    uint8_t src_pos = (pos >> 4)&0x1;
    uint8_t dst_pos = pos&0x1;

    /// erase bits in the destination position
    uint64_t temp_val = (registers[dst_reg]&~( uint64_t(0xFFFF'FFFF)<<(32*dst_pos)) );

    /// triple shift avoids branching - other wise negative shifts are occaisonally needed,
    /// this gets the src byte, shifts it back to 0 pos, then shifts it to destination position.
    /// this method avoids integer arithmetic and branching to handle relative left or right moves
    temp_val |= (registers[src_reg]&( uint64_t(0xFFFF'FFFF)<<(32*src_pos)) )>>(32*src_pos) <<(32*dst_pos);

    registers[dst_reg] = temp_val;

}

void processor::move_8(){
    uint8_t reg = get_program_byte();

    uint8_t src_reg = (reg >> 4)&0xF;
    uint8_t dst_reg = reg&0xF;

    registers[dst_reg] = registers[src_reg];

}


void processor::swap_1(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t reg_1 = (reg >> 4)&0xF;
    uint8_t reg_2 = reg&0xF;

    uint8_t pos_1 = (pos >> 4)&0x7;
    uint8_t pos_2 = pos&0x7;

    /// save relevant bytes
    uint8_t val_1 = registers[reg_1]>>(8*pos_1);
    uint8_t val_2 = registers[reg_2]>>(8*pos_2);

    /// erase bits in the destination position
    registers[reg_1] &= ~( uint64_t(0xFF)<<(8*pos_1));
    registers[reg_2] &= ~( uint64_t(0xFF)<<(8*pos_2));



    registers[reg_1] |= uint64_t(val_2)<<(8*pos_1);
    registers[reg_2] |= uint64_t(val_1)<<(8*pos_2);
}

void processor::swap_2(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t reg_1 = (reg >> 4)&0xF;
    uint8_t reg_2 = reg&0xF;

    uint8_t pos_1 = (pos >> 4)&0x3;
    uint8_t pos_2 = pos&0x3;

    /// save relevant bytes
    uint16_t val_1 = registers[reg_1]>>(16*pos_1);
    uint16_t val_2 = registers[reg_2]>>(16*pos_2);

    /// erase bits in the destination position
    registers[reg_1] &= ~( uint64_t(0xFFFF)<<(16*pos_1));
    registers[reg_2] &= ~( uint64_t(0xFFFF)<<(16*pos_2));



    registers[reg_1] |= uint64_t(val_2)<<(16*pos_1);
    registers[reg_2] |= uint64_t(val_1)<<(16*pos_2);
}

void processor::swap_4(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t reg_1 = (reg >> 4)&0xF;
    uint8_t reg_2 = reg&0xF;

    uint8_t pos_1 = (pos >> 4)&0x1;
    uint8_t pos_2 = pos&0x1;

    /// save relevant bytes
    uint32_t val_1 = registers[reg_1]>>(32*pos_1);
    uint32_t val_2 = registers[reg_2]>>(32*pos_2);

    /// erase bits in the destination position
    registers[reg_1] &= ~( uint64_t(0xFFFF'FFFF)<<(32*pos_1));
    registers[reg_2] &= ~( uint64_t(0xFFFF'FFFF)<<(32*pos_2));



    registers[reg_1] |= uint64_t(val_2)<<(32*pos_1);
    registers[reg_2] |= uint64_t(val_1)<<(32*pos_2);
}

void processor::swap_8(){
    uint8_t reg = get_program_byte();

    uint8_t reg_1 = (reg >> 4)&0xF;
    uint8_t reg_2 = reg&0xF;

    uint64_t val_1 = registers[reg_1];
    uint64_t val_2 = registers[reg_2];

    registers[reg_1] = val_2;//only NEED 1 extra copy, but 2 is closer to other swap methods
    registers[reg_2] = val_1;
}

void processor::load_1(){
    uint8_t reg_pos = get_program_byte();

    program_counter += 8;
    uint64_t address = get_8_PC_bytes();

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x7;

    uint8_t value = get_byte(address);
    registers[reg] &= ~( uint64_t(0xFF)<<(8*pos));

    registers[reg] |= uint64_t(value)<<(8*pos);
}

void processor::load_2(){
    uint8_t reg_pos = get_program_byte();

    program_counter += 8;
    uint64_t address = get_8_PC_bytes();

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x3;

    uint16_t value = get_2_bytes(address);
    registers[reg] &= ~( uint64_t(0xFFFF)<<(16*pos));

    registers[reg] |= uint64_t(value)<<(16*pos);
}

void processor::load_4(){
    uint8_t reg_pos = get_program_byte();

    program_counter += 8;
    uint64_t address = get_8_PC_bytes();

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x1;

    uint32_t value = get_4_bytes(address);
    registers[reg] &= ~( uint64_t(0xFFFF'FFFF)<<(32*pos));

    registers[reg] |= uint64_t(value)<<(32*pos);
}

void processor::load_8(){
    uint8_t reg_pos = get_program_byte();

    program_counter += 8;
    uint64_t address = get_8_PC_bytes();

    uint8_t reg = (reg_pos >> 4)&0xF;

    registers[reg] = get_8_bytes(address);
}

void processor::store_1(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x7;

    uint8_t value = ( registers[reg]&(uint64_t(0xFF)<<8*sizeof(value)*pos) )>>8*sizeof(value)*pos;
    set_byte(address, value);

}

void processor::store_2(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x3;

    uint16_t value = ( registers[reg]&(uint64_t(0xFFFF)<<8*sizeof(value)*pos) )>>8*sizeof(value)*pos;
    set_2_bytes(address, value);
}

void processor::store_4(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0x1;

    uint32_t value = ( registers[reg]&(uint64_t(0xFFFF'FFFF)<<8*sizeof(value)*pos ) )>>8*sizeof(value)*pos;
    set_4_bytes(address, value);
}

void processor::store_8(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;

    uint64_t value = registers[reg];
    set_8_bytes(address, value);
}

/** Control Flow **/
void processor::jump(){
    uint8_t meta_byte = get_program_byte();
    //types of jump to allow
    /**
        1-bit
        relative to current instruction location
        absolute (relative to prog start, 0x0 until OS-like behavior is implemented

        1-bit
        direct (pre-computed, lays in source <machine> code)
        indirect (based on register value) if indirect must take in extra byte for reg & position

        4-bit
            wasted

        2-bit
            indicates jump address/distance size
            0b00 == 1 byte
            0b01 == 2 byte
            0b10 == 4 byte
            0b11 == 8 byte

        Indirect only byte

        3-bit
            reg-pos
            used for indirect jumps,
            3 bits for size 1 byte
            2 bits for size 2 byte
            1 bits for size 4 byte

        4-bit
            register

    **/

    uint8_t is_relative = (meta_byte>>7)&0x1;
    uint8_t is_indirect = (meta_byte>>6)&0x1;
    uint8_t offset_size = 1<<( (meta_byte>>0)&0x3 );

    int64_t jump_offset = 0;

    if( !is_indirect ){
        switch( offset_size ){
            case 1:{
                offset_size = get_program_byte();
            }break;
            case 2:{
                program_counter += 1;
                offset_size = get_2_PC_bytes();
            }break;
            case 4:{
                program_counter += 3;
                offset_size = get_4_PC_bytes();
            }break;
            case 8:{
                program_counter += 7;
                offset_size = get_8_PC_bytes();
            }break;
        }
    }
    else{
        uint8_t indirect_byte = get_program_byte();
        uint8_t position = (indirect_byte>>4)&0x7;//grab offset from register at position
        uint8_t reg = (indirect_byte>>0)&0xF;

        switch( offset_size ){
            case 1:{
                position &= 0x7;
                offset_size = uint8_t(registers[reg]>>position);
            }break;
            case 2:{
                position &= 0x3;
                offset_size = uint8_t(registers[reg]>>position);
            }break;
            case 4:{
                position &= 0x1;
                offset_size = uint8_t(registers[reg]>>position);
            }break;
            case 8:{
                position &= 0x0;
                offset_size = uint8_t(registers[reg]>>position);
            }break;
        }
    }

    if( is_relative ){
        program_counter += offset_size;
    }
    else{

    }

}

void processor::conditional_jump(){

}

/** Arithmetic **/
void processor::add(){

    uint8_t src_regs = get_program_byte();
    uint8_t dst_regs = get_program_byte();

    uint8_t src_reg_1 = (src_regs>>4)&0xF;
    uint8_t src_reg_2 = src_regs&0xF;

    uint8_t dst_reg = dst_regs&0xF;
    uint8_t is_vector = (dst_regs>>6)&0x1;
    uint8_t size = (dst_regs>>4)&0x3;

    if( is_vector ){

        switch( size ){
            case 0:{
                uint64_t answer = 0;
                for( int i = 0; i < 8; i++){
                    answer |= (uint64_t)uint8_t(
                            uint8_t(registers[src_reg_1]>>(8*i)) +
                            uint8_t(registers[src_reg_2]>>(8*i))
                        ) << (8*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 1:{
                uint64_t answer = 0;
                for( int i = 0; i < 4; i++){
                    answer |= (uint64_t)uint16_t(
                            uint16_t(registers[src_reg_1]>>(16*i)) +
                            uint16_t(registers[src_reg_2]>>(16*i))
                        ) << (16*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 2:{
                uint64_t answer = 0;
                for( int i = 0; i < 2; i++){
                    answer |= (uint64_t)uint32_t(
                            uint32_t(registers[src_reg_1]>>(32*i)) +
                            uint32_t(registers[src_reg_2]>>(32*i))
                        ) << (32*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 3:{
                registers[dst_reg] = registers[src_reg_1]+registers[src_reg_2];
            }break;
        }
        return;
    }

    registers[dst_reg] = registers[src_reg_1]+registers[src_reg_2];
}

void processor::subtract(){

    uint8_t src_regs = get_program_byte();
    uint8_t dst_regs = get_program_byte();

    uint8_t src_reg_1 = (src_regs>>4)&0xF;
    uint8_t src_reg_2 = src_regs&0xF;

    uint8_t dst_reg = dst_regs&0xF;
    uint8_t is_vector = (dst_regs>>6)&0x1;
    uint8_t size = (dst_regs>>4)&0x3;

    if( is_vector ){

        switch( size ){
            case 0:{
                uint64_t answer = 0;
                for( int i = 0; i < 8; i++){
                    answer |= (uint64_t)uint8_t(
                            uint8_t(registers[src_reg_1]>>(8*i)) +
                           ~uint8_t(registers[src_reg_2]>>(8*i)) + 1
                        ) << (8*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 1:{
                uint64_t answer = 0;
                for( int i = 0; i < 4; i++){
                    answer |= (uint64_t)uint16_t(
                            uint16_t(registers[src_reg_1]>>(16*i)) +
                           ~uint16_t(registers[src_reg_2]>>(16*i)) + 1
                        ) << (16*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 2:{
                uint64_t answer = 0;
                for( int i = 0; i < 2; i++){
                    answer |= (uint64_t)uint32_t(
                            uint32_t(registers[src_reg_1]>>(32*i)) +
                           ~uint32_t(registers[src_reg_2]>>(32*i)) + 1
                        ) << (32*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 3:{
                registers[dst_reg] = registers[src_reg_1]+~registers[src_reg_2]+1;
            }break;
        }
        return;
    }

    registers[dst_reg] = registers[src_reg_1]+~registers[src_reg_2]+1;
}

void processor::increment(){

    uint8_t src_regs = get_program_byte();
    uint8_t dst_regs = get_program_byte();

    uint8_t src_reg_1 = (src_regs>>4)&0xF;

    uint8_t dst_reg = dst_regs&0xF;
    uint8_t is_vector = (dst_regs>>6)&0x1;
    uint8_t size = (dst_regs>>4)&0x3;

    if( is_vector ){

        switch( size ){
            case 0:{
                uint64_t answer = 0;
                for( int i = 0; i < 8; i++){
                    answer |= (uint64_t)uint8_t(
                            uint8_t(registers[src_reg_1]>>(8*i)) +
                            uint8_t(1)
                        ) << (8*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 1:{
                uint64_t answer = 0;
                for( int i = 0; i < 4; i++){
                    answer |= (uint64_t)uint16_t(
                            uint16_t(registers[src_reg_1]>>(16*i)) +
                            uint16_t(1)
                        ) << (16*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 2:{
                uint64_t answer = 0;
                for( int i = 0; i < 2; i++){
                    answer |= (uint64_t)uint32_t(
                            uint32_t(registers[src_reg_1]>>(32*i)) +
                            uint32_t(1)
                        ) << (32*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 3:{
                registers[dst_reg] = registers[src_reg_1]+uint64_t(1);
            }break;
        }
        return;
    }

    registers[dst_reg] = registers[src_reg_1]+uint64_t(1);
}

void processor::decrement(){

    uint8_t src_regs = get_program_byte();
    uint8_t dst_regs = get_program_byte();

    uint8_t src_reg_1 = (src_regs>>4)&0xF;

    uint8_t dst_reg = dst_regs&0xF;
    uint8_t is_vector = (dst_regs>>6)&0x1;
    uint8_t size = (dst_regs>>4)&0x3;

    if( is_vector ){

        switch( size ){
            case 0:{
                uint64_t answer = 0;
                for( int i = 0; i < 8; i++){
                    answer |= (uint64_t)uint8_t(
                            uint8_t(registers[src_reg_1]>>(8*i)) +
                           ~uint8_t(1) + 1
                        ) << (8*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 1:{
                uint64_t answer = 0;
                for( int i = 0; i < 4; i++){
                    answer |= (uint64_t)uint16_t(
                            uint16_t(registers[src_reg_1]>>(16*i)) +
                           ~uint16_t(1) + 1
                        ) << (16*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 2:{
                uint64_t answer = 0;
                for( int i = 0; i < 2; i++){
                    answer |= (uint64_t)uint32_t(
                            uint32_t(registers[src_reg_1]>>(32*i)) +
                           ~uint32_t(1) + 1
                        ) << (32*i);
                }
                registers[dst_reg] = answer;
            }break;
            case 3:{
                registers[dst_reg] = registers[src_reg_1]+~uint64_t(1)+uint64_t(1);
            }break;
        }
        return;
    }

    registers[dst_reg] = registers[src_reg_1]+~uint64_t(1)+uint64_t(1);
}

void processor::negate(){

}

void processor::multiply(){

}

void processor::divide(){

}

/** Bit-Wise **/
void processor::bit_and(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = registers[A]&registers[B];
}

void processor::bit_or(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = registers[A]|registers[B];
}

void processor::bit_nand(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = ~(registers[A]&registers[B]);
}

void processor::bit_nor(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = ~(registers[A]|registers[B]);
}

void processor::bit_xor(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = registers[A]^registers[B];
}

void processor::bit_xnor(){
    uint8_t src_regs = get_program_byte();
    uint8_t A = (src_regs >> 4)&0xF;
    uint8_t B = src_regs&0xF;

    uint8_t C = get_program_byte()&0xF;

    registers[C] = ~(registers[A]^registers[B]);
}

void processor::bit_not(){
    uint8_t reg = get_program_byte();
    uint8_t A = (reg >> 4)&0xF;
    uint8_t B = reg&0xF;

    registers[B] = ~registers[A];
}

void processor::shift_left(){
    uint8_t reg = get_program_byte();
    uint8_t shift_bits = get_program_byte();

    uint8_t A = (reg >> 4)&0xF;
    uint8_t B = reg&0xF;

    if( shift_bits >= sizeof(uint64_t)*8 ){
        registers[B] = 0;
        return;
    }

    registers[B] = registers[A]<<(shift_bits&0x3F);
}

void processor::shift_right(){
    uint8_t reg = get_program_byte();
    uint8_t shift_bits = get_program_byte();

    uint8_t A = (reg >> 4)&0xF;
    uint8_t B = reg&0xF;

    if( shift_bits >= sizeof(uint64_t)*8 ){
        registers[B] = 0;
        return;
    }

    registers[B] = registers[A]>>(shift_bits&0x3F);
}

void processor::rotate_left(){
    uint8_t reg = get_program_byte();
    uint8_t shift_bits = get_program_byte();

    uint8_t A = (reg >> 4)&0xF;
    uint8_t B = reg&0xF;

    registers[B] = ( registers[A] << (shift_bits) ) | ( registers[A] >> ( (64-shift_bits)&0x3F) );
}

void processor::rotate_right(){
    uint8_t reg = get_program_byte();
    uint8_t shift_bits = get_program_byte()&0x3F;

    uint8_t A = (reg >> 4)&0xF;
    uint8_t B = reg&0xF;

    registers[B] = ( registers[A] >> (shift_bits) ) | ( registers[A] << ( (64-shift_bits)&0x3F) );
}
