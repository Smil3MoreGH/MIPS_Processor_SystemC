/*
 * alu_control_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "alu_control_systemc.h"

void alu_control_systemc::Behavioral()
{
	switch (ALUOp.read().to_uint())
    {
        case 0: ALU_Control.write(ALU_Funct.read());
            break;
        case 1: ALU_Control.write(001);
            break;
        case 2: ALU_Control.write(100);
            break;
        case 3: ALU_Control.write(000);
            break;
        default: ALU_Control.write(000);
    }
};
/*
int sc_main(int argc, char* argv[])
{
	sc_signal <sc_lv<2>> ALUOp;
	sc_signal <sc_lv<3>> ALU_Funct;
	sc_signal <sc_lv<3>> ALU_Control;

	sc_trace_file *trace_file;
	trace_file = sc_create_vcd_trace_file("trace");
	trace_file->set_time_unit(1,SC_NS);

	alu_control_systemc uut("uut");

	uut.ALUOp(ALUOp);
	uut.ALU_Funct(ALU_Funct);
	uut.ALU_Control(ALU_Control);

	sc_trace(trace_file , ALUOp, "ALUOp");
	sc_trace(trace_file , ALU_Funct, "ALU_Funct");
	sc_trace(trace_file , ALU_Control, "ALU_Control");

	ALUOp = 00;
	ALU_Funct = "010";
	ALU_Control = "000";

	sc_start(10,SC_NS);

	ALUOp = 01;
	sc_start(10,SC_NS);

	ALUOp = 10;
	sc_start(10,SC_NS);

	ALUOp = 11;
	sc_start(10,SC_NS);

	return 0;
}
*/
