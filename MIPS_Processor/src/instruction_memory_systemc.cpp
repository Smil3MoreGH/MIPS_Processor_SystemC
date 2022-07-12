/*
 * instruction_memory_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "instruction_memory_systemc.h"

void instruction_memory_systemc::Behavioral()
{
	rom_data[0] = "1000000110000000";
	rom_data[1] = "0010110010001011";
	rom_data[2] = "1100010000000011";
	rom_data[3] = "0001000111000000";
	rom_data[4] = "1110110110000001";
	rom_data[5] = "1100000001111011";
	rom_data[6] = "0000000000000000";
	rom_data[7] = "0000000000000000";
	rom_data[8] = "0000000000000000";
	rom_data[9] = "0000000000000000";
	rom_data[10] ="0000000000000000";
	rom_data[11] ="0000000000000000";
	rom_data[12] ="0000000000000000";
	rom_data[13] ="0000000000000000";
	rom_data[14] ="0000000000000000";
	rom_data[15] ="0000000000000000";

	sc_uint<4>rom_addr;
	rom_addr = pc.read().range(4,1).to_uint();

    if (pc.read().to_uint() < 0x0020)
    {
        instruction.write(rom_data[rom_addr]);
    }else
    {
    	instruction.write(0x0000);
    }
};
/*
int sc_main(int argc, char* argv[])
{
	sc_signal<sc_lv<16>>pc;
	sc_signal<sc_lv<16>>instruction;

    sc_trace_file *trace_file;
    trace_file = sc_create_vcd_trace_file("trace");
    trace_file->set_time_unit(1,SC_NS);;

	instruction_memory_systemc uut("uut");

	uut.pc(pc);
	uut.instruction(instruction);

	sc_trace(trace_file, pc, "pc");
	sc_trace(trace_file, instruction, "instruction");

	pc = "0x0020";
	instruction = "0000000000010000";
	sc_start(10,SC_NS);

	pc = "0x0000";
	sc_start(10,SC_NS);

	return 0;
}
*/
