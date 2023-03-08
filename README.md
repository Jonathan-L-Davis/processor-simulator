# Processor Simulator

not an emulator, doesn't simulate a cpu to an exact degree, <br>
only enough to feel the same from an assembly perspective

## 16 instructions so far

## Memory instructions: 16 : 

# Note: 
invalid position currently results in memory instructions giving a no-op.<br>
this will change in the (near) future<br>
<br>
Incomplete, will detail the spec incrementally.
#move(s)
<br>

move1<br>
    Moves 1 byte from a source register (src) to a destination register (dst).<br>
    A position 0-7 can be chosen to write to and from. <br>
    0 being the least significant byte and 7 being the most<br>
<br>
    takes 3 bytes.<br>
    \[8bit(op-code)]\[4bit(src-reg) 4bit(dst-reg)]\[4bit(src-pos) 4bit(dst-pos)]<br>
<br>
move2<br>
    Moves 1 byte from a source register (src) to a destination register (dst).<br>
    A position 0-7 can be chosen to write to and from. <br>
    0 being the least significant byte and 7 being the most<br>
<br>
    takes 3 bytes.<br>
    \[8bit(op-code)]\[4bit(src-reg) 4bit(dst-reg)]\[4bit(src-pos) 4bit(dst-pos)]<br>
<br>
move4<br>
    Moves 1 byte from a source register (src) to a destination register (dst).<br>
    A position 0-7 can be chosen to write to and from. <br>
    0 being the least significant byte and 7 being the most<br>
<br>
    takes 3 bytes.<br>
    \[8bit(op-code)]\[4bit(src-reg) 4bit(dst-reg)]\[4bit(src-pos) 4bit(dst-pos)]<br>
<br>
move8<br>
    Moves 1 byte from a source register (src) to a destination register (dst).<br>
    A position 0-7 can be chosen to write to and from. <br>
    0 being the least significant byte and 7 being the most<br>
<br>
    takes 2 bytes.<br>
    \[8bit(op-code)]\[4bit(src-reg) 4bit(dst-reg)]<br>
<br>
swap(1-8)<br>
load(1-8)<br>
store(1-8)<br>

