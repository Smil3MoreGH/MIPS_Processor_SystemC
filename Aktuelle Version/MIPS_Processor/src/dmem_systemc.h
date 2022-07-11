/*
 * dmem_systemc.h
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */

#include "systemc.h"

SC_MODULE(dmem_systemc)
{
	sc_in<sc_lv<16>>address;
	sc_in<sc_lv<16>>write_data;
	sc_in<sc_logic>MemWrite;
	sc_in<sc_logic>MemRead;
	sc_in<sc_logic>ck;
	sc_out<sc_lv<16>>read_data;
	sc_lv<16>data_mem[16];

	SC_CTOR (dmem_systemc)
	{
		for(int i=0; i<16; i++){
			data_mem[i] = {0x00000000};
			sc_lv<32> tmp = data_mem[i];
		}

		if (MemRead == '1')
		{
			sc_lv<5>snippet = address.read().range(6,2);
			read_data =  snippet.to_int();
		} else {
			read_data = 0x00000000;
		}

		SC_METHOD(Behavioral);
		sensitive << address ;
		sensitive_neg << ck;
	}

    void Behavioral();
};
