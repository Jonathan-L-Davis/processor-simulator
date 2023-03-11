# Processor Simulator

Emulator for an abstract processor.
### Instructions:
<br>
planned, not all implemented yet (most are not)<br>
<br>
/**--- MEMORY ---**/ (implemented, fail on improper position, will change to not read un needed bits soon.)<br>
move_1<br>
move_2<br>
move_4<br>
move_8<br>
swap_1<br>
swap_2<br>
swap_4<br>
swap_8<br>
load_1<br>
load_2<br>
load_4<br>
load_8<br>
store_1<br>
store_2<br>
store_4<br>
store_8<br>
<br>
/**--- Control Flow ---**/<br>
/// "Absolute" Jumps<br>
//relative to program start position<br>
absolute_jump<br>
absolute_jump_equal_0<br>
absolute_jump_not_equal_0<br>
absolute_jump_positive<br>
absolute_jump_negative<br>
absolute_jump_not_positive<br>
absolute_jump_not_negative<br>
absolute_jump_equal<br>
absolute_jump_not_equal<br>
absolute_jump_greater<br>
absolute_jump_less<br>
absolute_jump_greater_equal<br>
absolute_jump_less_equal<br>
/// Relative Jumps - may just be implemented via a flag for jumps<br>
// relative to jump instruction<br>
relative_jump<br>
relative_jump_equal_0<br>
relative_jump_not_equal_0<br>
relative_jump_positive<br>
relative_jump_negative<br>
relative_jump_not_positive<br>
relative_jump_not_negative<br>
relative_jump_equal<br>
relative_jump_not_equal<br>
relative_jump_greater<br>
relative_jump_less<br>
relative_jump_greater_equal<br>
relative_jump_less_equal<br>
<br>
/**--- Arithmetic ---**/<br>
add<br>
subtract<br>
increment<br>
decrement<br>
negate<br>
multiply<br>
divide<br>
<br>
/**--- Bit-Wise ---**/<br>
bit_and<br>
bit_or<br>
bit_nand<br>
bit_nor<br>
bit_xor<br>
shift_left<br>
shift_right<br>
rotate_left<br>
rotate_right
