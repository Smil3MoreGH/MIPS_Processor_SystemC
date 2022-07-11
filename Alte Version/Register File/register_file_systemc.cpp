#include "register_file_systemc.h"

void register_file_systemc::Behavioral()
{
	typedef <sc_lv<16>> reg_type[8];
	sc_signal <reg_type> reg_array;
	
	if(rst='1')
	{
		reg_array(0).write(x"0001");
		reg_array(1).write(x"0002");
		reg_array(2).write(x"0003");
		reg_array(3).write(x"0004");
		reg_array(4).write(x"0005");
		reg_array(5).write(x"0006");
		reg_array(6).write(x"0007");
		reg_array(7).write(x"0008");

		else if(clk.event() && reg_write_rn == 1)
		{
			reg_array(to_int(sc_unit(reg_write_dest))) = reg_write_data;
		}
	}

	if(reg_read_addr_1 = "000")
	{
		reg_read_data_1 = x"0000"
	}
	else 
	{
		reg_read_data_1 = reg_array(to_int(sc_unit(reg_read_addr_1)))
	}
	if(reg_read_addr_2 = "000")
	{
		reg_read_data_2 = x"0000"
	}
	else 
	{
		reg_read_data_2 = reg_array(to_int(sc_unit(reg_read_addr_2)))
	}
}
