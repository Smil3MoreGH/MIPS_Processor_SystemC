//test bench
#include "systemc.h"
#include "" 77 ALLES FILES
#include "tb.h"

SC_MODULE (MIPS_Processor)
{
	tb *tb0;
	//fir *fir0; //ersetzten mit unserem Namen
	sc_clock clk_sig;
	sc_signal<sc_lv<>> reset rst_sig;
	sc_signal<sc_lv<16>>pc_out  pcout_sig;
	sc_signal<sc_lv<16>>alu_result alur_sig;
	
	int sc_main(int argc, char* argv[])
	{
	void clk_process()
	{
	clk.write(0);
	 wait( clk_period/2 , NS);
	 clk.write(1);
	 wait( clk_period/2 , NS);
	}

	void stim_proc()
	{
	reset.write(1);
	wait( clk_period*10 , NS);
	 reset.write(0);
	 wait;
	 
	}
	}
	SC_CTOR (MIPS_Processor)
	{
	:clkp_sig("clkp_sig", 10, SC_NS);
	tb0 = new tb("tb0");
	tb0->clk(clk_sig);
	tb0->reset(rst_sig);
	tb0->pc_out(pcout_sig);
	tb0->alu_result(alur_sig);

	fir0 = new fir("fir0");
	fir0->clk(clk_sig);
	fir0->reset(rst_sig);
	fir0->pc_out(pcout_sig);
	fir0->alu_result(alur_sig);
	}

}