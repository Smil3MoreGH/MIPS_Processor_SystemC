/*
 * instruction_memory_systemc.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */
#include "instruction_memory_systemc.h"

void instruction_memory_systemc::Behavioral()
{
    rom_addr = pc;

    if (pc < "x0020" || pc < "x0000")
    {
        instruction = ROM_data[(int)((sc_uint<16>)rom_addr)];
    }
};
