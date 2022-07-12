/*
 * dmem_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "dmem_systemc.h"

void dmem_systemc::Behavioral()
{
	for(int i=0; i<=15; i++)
	{
		data_mem[i] = {0x00000000};
	}

	if (clk.read() == 1 && clk.event())
	{
		if (mem_write_en.read() == 1)
		{
			data_mem[mem_access_addr.read().range(8,1).to_uint()] = mem_write_data;
		}
	}

	if (mem_read.read() == 1)
	{
		mem_read_data.write(data_mem[mem_access_addr.read().range(8,1).to_uint()]);
	}else
	{
		mem_read_data.write(0);
	}
};
/*
int sc_main(int argc, char* argv[])
{
    sc_signal<sc_lv<16>>mem_access_addr;
    sc_signal<sc_lv<16>>mem_write_data;
    sc_signal<sc_lv<16>>mem_read_data;

    sc_signal<bool>mem_write_en;
    sc_signal<bool>mem_read;
    sc_signal<bool>clk;

    sc_trace_file *trace_file;
    trace_file = sc_create_vcd_trace_file("trace");
    trace_file->set_time_unit(1,SC_NS);

    dmem_systemc uut("uut");

    uut.mem_access_addr(mem_access_addr);
    uut.mem_write_data(mem_write_data);
    uut.mem_read_data(mem_read_data);
    uut.mem_write_en(mem_write_en);
    uut.mem_read(mem_read);
    uut.clk(clk);

    sc_trace(trace_file, mem_access_addr, "mem_access_addr");
    sc_trace(trace_file, mem_write_data, "mem_write_data");
    sc_trace(trace_file, mem_read_data, "mem_read_data");
    sc_trace(trace_file, mem_write_en, "mem_write_en");
    sc_trace(trace_file, mem_read, "mem_read");
    sc_trace(trace_file, clk, "clk");

    mem_access_addr = "0000001000100101";
    mem_write_data = "0000000000100100";
    mem_read_data = "0000000000100001";

    mem_write_en = 1;
    mem_read = 1;
    clk = 1;

    sc_start(10,SC_NS);

    return 0;
}
*/
