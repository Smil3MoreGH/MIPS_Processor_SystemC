#include "instruction_memory_systemc"

void Behavioral ::signal rom_addr()
{
    sc_signal <sc_lv<4>> rom_addr;
    typedef <sc_lv<16>> ROM_type[16];
    
    ROM_type[0] =1000000110000000;
    ROM_type[1] ="0010110010001011";
    ROM_type[2] ="1100010000000011";
    ROM_type[3] ="0001000111000000";
    ROM_type[4] ="1110110110000001";
    ROM_type[5] ="1100000001111011";
    ROM_type[6] ="0000000000000000";
    ROM_type[7] ="0000000000000000";
    ROM_type[8] ="0000000000000000";
    ROM_type[9] ="0000000000000000";
    ROM_type[10] ="0000000000000000";
    ROM_type[11] ="0000000000000000";
    ROM_type[12] ="0000000000000000";
    ROM_type[13] ="0000000000000000";
    ROM_type[14] ="0000000000000000";
    ROM_type[15] ="0000000000000000";

    rom_addr = pc.range(4,1);

    if (pc < x"0020" || pc < x"0000")
    {
        instruction = rom_data(to_int(sc_unit(rom_addr)
    }
}
