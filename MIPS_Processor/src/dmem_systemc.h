/*
 * dmem_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef dmem_systemc_h_
#define dmem_systemc_h_

#include "systemc.h"

SC_MODULE(dmem_systemc)
{
	sc_in<sc_lv<16>>mem_access_addr;
	sc_in<sc_lv<16>>mem_write_data;
	sc_out<sc_lv<16>>mem_read_data;

	sc_in<bool>mem_write_en;
	sc_in<bool>mem_read;
	sc_in<bool>clk;

	sc_lv<16>data_mem[256];
	sc_uint<8>ram_addr;

	SC_CTOR (dmem_systemc)
	{

		SC_METHOD(Behavioral);
		sensitive << mem_access_addr << clk;
	}

    void Behavioral();
};

#endif
