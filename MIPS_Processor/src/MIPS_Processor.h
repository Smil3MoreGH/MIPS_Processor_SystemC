/*
 * MIPS_Processor.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef MIPS_Processor_h_
#define MIPS_Processor_h_

#include "systemc.h"

SC_MODULE(MIPS_Processor)
{
	sc_in<sc_logic>clk;
	sc_in<sc_logic>reset;

    sc_out <sc_lv<16>> pc_out;
    sc_out <sc_lv<16>> alu_result;


    SC_CTOR(MIPS_Processor)
    {

        SC_METHOD(main);
        sensitive << clk << reset;
    }

    void main();
};

#endif
