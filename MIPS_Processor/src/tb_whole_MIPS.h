/*
 * tb_whole_MIPS.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */


// IST NUR EIN TEST GEWESEN

#ifndef TB_WHOLE_MIPS_H_
#define TB_WHOLE_MIPS_H_

#include "MIPS_Processor.h"

SC_MODULE( tb_whole_MIPS )
{
	sc_signal<bool>clk;
	sc_signal<bool>reset;

	sc_signal <sc_lv<16>> pc_out;
	sc_signal <sc_lv<16>> alu_result;

	MIPS_Processor uut;

	const sc_time clk_period = sc_time(10,SC_NS);

	void main();

	SC_CTOR(tb_whole_MIPS) :
    	clk ("clk"),
		reset ("reset"),
		pc_out ("pc_out"),
		alu_result ("alu_result"),
		uut ("uut")
    {

    	uut.clk(clk);
    	uut.reset(reset);
    	uut.pc_out(pc_out);
    	uut.alu_result(alu_result);

    	SC_METHOD(main);
    }
};

#endif
