#include "systemc.h"

SC_MODLUE(instruction_memory_systemc)
{
	sc_in<sc_bv<16>> pc;
	sc_out<sc_bv<16>> instruction;

	SC_CTOR(instruction_memory_systemc)
	{
		SC_METHOD(Behavioral);
		sensitive << pc;
	}
	
	void Behavioral();
}
