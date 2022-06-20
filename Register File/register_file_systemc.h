#include "systemc.h"

SC_MODULE(register_file_systemc)
{
	sc_in<sc_logic> clk;
	sc_in<sc_logic> rst;

	sc_in<sc_logic> reg_write_en;
	sc_in<sc_lv<3>>reg_write_dest;
	sc_in<sc_lv<16>>reg_write_data;
	sc_in<sc_lv<3>>reg_read_addr_1;
	sc_out<sc_lv<16>>reg_read_data_1;
	sc_in<sc_lv<3>>reg_read_addr_2;
	sc_out<sc_lv<16>>reg_read_data_2;

	SC_CTOR(register_file_systemc)
	{	
		SC_METHOD(Behavioral);
		sensitive << clk << rst;
	}

	void Behavioral();
}
