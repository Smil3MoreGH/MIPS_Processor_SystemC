/*
 * register_file_systemc.h
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */

#include "systemc.h"

SC_MODULE(register_file_systemc)
{
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in<bool> reg_write_en;

	sc_in<sc_lv<3>>reg_write_dest;
	sc_in<sc_lv<16>>reg_write_data;
	sc_in<sc_lv<3>>reg_read_addr_1, reg_read_addr_2;
	sc_out<sc_lv<16>>reg_read_data_1,reg_read_data_2;

	typedef sc_lv<16> mem_array[16];
		sc_signal<mem_array> reg_array;

	SC_CTOR(register_file_systemc)
	{
		reg_read_addr_1 = reg_array[(int)((sc_uint<16>)reg_read_data_1)];
		reg_read_addr_2 = reg_array[(int)((sc_uint<16>)reg_read_data_2)];
		SC_METHOD(Behavioral);
		sensitive << clk << rst;
	}

	void Behavioral();
};
