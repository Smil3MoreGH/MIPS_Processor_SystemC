/*
 * register_file_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "register_file_systemc.h"

void register_file_systemc::Behavioral()
{

	if(rst.read() == 1)
	{
		reg_array[0] = "0x0001";
		reg_array[1] = "0x0002";
		reg_array[2] = "0x0003";
		reg_array[3] = "0x0004";
		reg_array[4] = "0x0005";
		reg_array[5] = "0x0006";
		reg_array[6] = "0x0007";
		reg_array[7] = "0x0008";

	}else if (clk.event() && reg_write_en.read() == 1)
	{
		reg_array[reg_write_dest.read().to_uint()] = reg_write_data;
    }

	if(reg_read_addr_1.read().to_uint() == 0)
	{
		reg_read_data_1.write( "0x0000" );
	}else
	{
		reg_read_data_1.write( reg_array[reg_read_addr_1.read().to_uint()] );
	}

	if(reg_read_addr_2.read().to_uint() == 0)
	{
		reg_read_data_2.write( "0x0000" );
	}else
	{
		reg_read_data_2.write( reg_array[reg_read_addr_2.read().to_uint()] );
	}

};
/*
int sc_main(int argc, char* argv[])
{
	sc_signal<bool> clk;
	sc_signal<bool> rst;
	sc_signal<bool> reg_write_en;
	sc_signal<sc_lv<3>>reg_write_dest;
	sc_signal<sc_lv<16>>reg_write_data;
	sc_signal<sc_lv<3>>reg_read_addr_1, reg_read_addr_2;
	sc_signal<sc_lv<16>>reg_read_data_1,reg_read_data_2;

	sc_trace_file *trace_file;
	trace_file = sc_create_vcd_trace_file("trace");
	trace_file->set_time_unit(1,SC_NS);

	register_file_systemc uut("uut");

	uut.clk(clk);
	uut.rst(rst);
	uut.reg_write_en(reg_write_en);
	uut.reg_write_dest(reg_write_dest);
	uut.reg_write_data(reg_write_data);
	uut.reg_read_addr_1(reg_read_addr_1);
	uut.reg_read_addr_2(reg_read_addr_2);
	uut.reg_read_data_1(reg_read_data_1);
	uut.reg_read_data_2(reg_read_data_2);

	sc_trace(trace_file , clk, "clk");
	sc_trace(trace_file , rst, "rst");
	sc_trace(trace_file , reg_write_en, "reg_write_en");
	sc_trace(trace_file , reg_write_dest, "reg_write_dest");
	sc_trace(trace_file , reg_write_data, "reg_write_data");

	sc_trace(trace_file , reg_read_addr_1, "reg_read_addr_1");
	sc_trace(trace_file , reg_read_addr_2, "reg_read_addr_2");
	sc_trace(trace_file , reg_read_data_1, "reg_read_data_1");
	sc_trace(trace_file , reg_read_data_2, "reg_read_data_2");

	rst = 1;
	clk = 0;
	reg_write_en = 0;
	reg_write_dest = "000";
	reg_write_data = "0000000000001001";
	reg_read_addr_1 = "000";
	reg_read_addr_2 = "000";
	reg_read_data_1 = "0000000000000000";
	reg_read_data_2 = "0000000000000000";

	sc_start(10,SC_NS);

	rst = 0;
	clk = 1;
	reg_write_en = 1;
	reg_write_dest = "000";
	reg_write_data = "0000000000001001";
	reg_read_addr_1 = "001";
	reg_read_addr_2 = "001";
	reg_read_data_1 = "0000000000000000";
	reg_read_data_2 = "0000000000000000";

	sc_start(10,SC_NS);

	return 0;
}
*/
