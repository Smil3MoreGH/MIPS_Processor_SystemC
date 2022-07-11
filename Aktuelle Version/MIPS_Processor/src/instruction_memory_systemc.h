/*
 * instruction_memory_systemc.h
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */

#include "systemc.h"

SC_MODULE(instruction_memory_systemc)
{
    sc_in<sc_lv<16>>pc;
    sc_out<sc_lv<16>>instruction;
    sc_signal <sc_lv<4>> rom_addr;
    typedef sc_lv<16> ROM_type[16];
        	sc_signal<ROM_type> ROM_data;

    SC_CTOR(instruction_memory_systemc)
    {
    	ROM_data[0] ="1000000110000000";
		ROM_data[1] ="0010110010001011";
		ROM_data[2] ="1100010000000011";
		ROM_data[3] ="0001000111000000";
		ROM_data[4] ="1110110110000001";
		ROM_data[5] ="1100000001111011";
		ROM_data[6] ="0000000000000000";
		ROM_data[7] ="0000000000000000";
		ROM_data[8] ="0000000000000000";
		ROM_data[9] ="0000000000000000";
		ROM_data[10] ="0000000000000000";
		ROM_data[11] ="0000000000000000";
		ROM_data[12] ="0000000000000000";
		ROM_data[13] ="0000000000000000";
		ROM_data[14] ="0000000000000000";
		ROM_data[15] ="0000000000000000";

        SC_METHOD(Behavioral);
        sensitive << pc;
    }

    void Behavioral();
};
