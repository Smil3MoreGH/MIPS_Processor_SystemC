#include "systemc.h"

SC_MODLUE(instruction_Memory_VHDL)
{
	sc_in<sc_bv<16>> pc;
	sc_out<sc_bv<16>> instruction;

	SC_CTOR(Instruction_Memory_VHDL)
	{
		SC_METHOD(Behavioral);
	}
}