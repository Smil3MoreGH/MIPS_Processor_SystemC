/*
 * dmem_systemc.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */
#include "dmem_systemc.h"

void dmem_systemc::Behavioral()
{
	if (ck.read() == '0' && ck.event())
	{
		if (MemWrite == '1')
		{
			sc_lv<5>snippet = address.read().range(6,2);
			data_mem[snippet.to_int()] = write_data;
		}
	}
};
