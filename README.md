# Processor Simulator



Done for the time being, next steps include Documentation and Unit testing.<br>
need to write vector ops for division and multiplication too,<br>
but that will likely wait until someone complains.<br>
<BR>
Final plans will involve integrating into a website<br>
writing a server & miniOS (glorified loader & scheduler)<br>
for running user programs against each other. "Assembly Gladiators!"<br>
<br>
all projects of similar size on their own<br>
will do slowly over the next year.<br>


### Instructions:
<br>
<br>
/**--- MEMORY ---**/ (implemented!)<br>
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
    relative to program start position<br> 
    (for now all programs start at physical 0, will change, but is too complicated for me to do in one go)<br>
/// Relative Jumps - may just be implemented via a prefix/suffix for jumps<br>
 relative to jump instruction<br>
jump<br>
jump_equal_0<br>
jump_not_equal_0<br>
jump_positive<br>
jump_negative<br>
jump_not_positive<br>
jump_not_negative<br>
jump_equal<br>
jump_not_equal<br>
jump_greater<br>
jump_less<br>
jump_greater_equal<br>
jump_less_equal<br>
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
/**--- Bit-Wise ---**/ (implemented!)<br>
bit_and<br>
bit_or<br>
bit_nand<br>
bit_nor<br>
bit_xor<br>
shift_left<br>
shift_right<br>
rotate_left<br>
rotate_right
