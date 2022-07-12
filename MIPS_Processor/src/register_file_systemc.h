/*
 * register_file_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef register_file_systemc_h_
#define register_file_systemc_h_

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

	sc_lv<16> reg_array[8];

	SC_CTOR(register_file_systemc)
	{
		SC_METHOD(Behavioral);
		sensitive << clk << rst;
	}

	void Behavioral();
};

#endif
