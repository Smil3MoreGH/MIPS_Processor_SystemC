/*
 * instruction_memory_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef instruction_memory_systemc_h_
#define instruction_memory_systemc_h_

#include "systemc.h"

SC_MODULE(instruction_memory_systemc)
{
    sc_in<sc_lv<16>>pc;
    sc_out<sc_lv<16>>instruction;
    sc_lv<16>rom_data[16];


    SC_CTOR(instruction_memory_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive << pc;
    }

    void Behavioral();
};

#endif
