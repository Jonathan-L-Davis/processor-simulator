#include "processor.h"

#include <iostream>
#include <iomanip>

void processor::move_1(){
    uint8_t reg = get_program_byte();
    uint8_t pos = get_program_byte();

    uint8_t src_reg = (reg >> 4)&0xF;
    uint8_t dst_reg = reg&0xF;

    uint8_t src_pos = (pos >> 4)&0xF;
    uint8_t dst_pos = pos&0xF;

    if( src_pos < 0 || src_pos > 7 )
        return;
    if( dst_pos < 0 || dst_pos > 7 )
        return;

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

    uint8_t src_pos = (pos >> 4)&0xF;
    uint8_t dst_pos = pos&0xF;

    if( src_pos < 0 || src_pos > 3 )
        return;
    if( dst_pos < 0 || dst_pos > 3 )
        return;

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

    uint8_t src_pos = (pos >> 4)&0xF;
    uint8_t dst_pos = pos&0xF;

    if( src_pos < 0 || src_pos > 1 )
        return;
    if( dst_pos < 0 || dst_pos > 1 )
        return;

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

    uint8_t pos_1 = (pos >> 4)&0xF;
    uint8_t pos_2 = pos&0xF;

    if( pos_1 < 0 || pos_1 > 7 )
        return;
    if( pos_2 < 0 || pos_2 > 7 )
        return;

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

    uint8_t pos_1 = (pos >> 4)&0xF;
    uint8_t pos_2 = pos&0xF;

    if( pos_1 < 0 || pos_1 > 3 )
        return;
    if( pos_2 < 0 || pos_2 > 3 )
        return;

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

    uint8_t pos_1 = (pos >> 4)&0xF;
    uint8_t pos_2 = pos&0xF;

    if( pos_1 < 0 || pos_1 > 1 )
        return;
    if( pos_2 < 0 || pos_2 > 1 )
        return;

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

    program_counter = (program_counter+8)&~7;// +7 shifts the alignment rounding. &7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 7)
        return;

    uint8_t value = get_byte(address);
    registers[reg] &= ~( uint64_t(0xFF)<<(8*sizeof(value)*pos));

    registers[reg] |= uint64_t(value)<<(8*sizeof(value)*pos);
}

void processor::load_2(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 3)
        return;

    uint16_t value = get_2_bytes(address);
    registers[reg] &= ~( uint64_t(0xFFFF)<<(8*sizeof(value)*pos));

    registers[reg] |= uint64_t(value)<<(8*sizeof(value)*pos);
}

void processor::load_4(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 1)
        return;

    uint32_t value = get_4_bytes(address);
    registers[reg] &= ~( uint64_t(0xFFFF'FFFF)<<(8*sizeof(value)*pos));

    registers[reg] |= uint64_t(value)<<(8*sizeof(value)*pos);
}

void processor::load_8(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = 0;//ignore position for 8 byte values

    uint64_t value = get_8_bytes(address);
    registers[reg] &= ~( uint64_t(0xFFFF'FFFF'FFFF'FFFF)<<(8*sizeof(value)*pos));

    registers[reg] |= uint64_t(value)<<(8*sizeof(value)*pos);
}

void processor::store_1(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 7)
        return;

    uint8_t value = ( registers[reg]&(uint64_t(0xFF)<<8*sizeof(value)*pos) )>>8*sizeof(value)*pos;
    set_byte(address, value);

}

void processor::store_2(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 3)
        return;

    uint16_t value = ( registers[reg]&(uint64_t(0xFFFF)<<8*sizeof(value)*pos) )>>8*sizeof(value)*pos;
    set_2_bytes(address, value);
}

void processor::store_4(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = reg_pos&0xF;

    if(pos < 0 || pos > 1)
        return;

    uint32_t value = ( registers[reg]&(uint64_t(0xFFFF'FFFF)<<8*sizeof(value)*pos ) )>>8*sizeof(value)*pos;
    set_4_bytes(address, value);
}

void processor::store_8(){

    uint8_t reg_pos = get_program_byte();

    program_counter = (program_counter+8)&~7;// &~7 makes the pc 8 aligned

    uint64_t address = get_8_bytes( program_counter );//get address
    program_counter += 8;//step past byte;

    uint8_t reg = (reg_pos >> 4)&0xF;
    uint8_t pos = 0;

    uint64_t value = registers[reg];
    set_8_bytes(address, value);
}

/** Control Flow **/

/** Arithmetic **/

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
