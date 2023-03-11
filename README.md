# Processor Simulator

Emulator for an abstract processor.
### Instructions:

planned, not all implemented yet (most are not)

/**--- MEMORY ---**/ (implemented, not finished)
move_1
move_2
move_4
move_8
swap_1
swap_2
swap_4
swap_8
load_1
load_2
load_4
load_8
store_1
store_2
store_4
store_8

/**--- Control Flow ---**/
/// "Absolute" Jumps
//relative to program start position
absolute_jump
absolute_jump_equal_0
absolute_jump_not_equal_0
absolute_jump_positive
absolute_jump_negative
absolute_jump_not_positive
absolute_jump_not_negative
absolute_jump_equal
absolute_jump_not_equal
absolute_jump_greater
absolute_jump_less
absolute_jump_greater_equal
absolute_jump_less_equal
/// Relative Jumps - may just be implemented via a flag for jumps
// relative to jump instruction
relative_jump
relative_jump_equal_0
relative_jump_not_equal_0
relative_jump_positive
relative_jump_negative
relative_jump_not_positive
relative_jump_not_negative
relative_jump_equal
relative_jump_not_equal
relative_jump_greater
relative_jump_less
relative_jump_greater_equal
relative_jump_less_equal

/**--- Arithmetic ---**/
add
subtract
increment
decrement
negate
multiply
divide

/**--- Bit-Wise ---**/
bit_and
bit_or
bit_nand
bit_nor
bit_xor
shift_left
shift_right
rotate_left
rotate_right
