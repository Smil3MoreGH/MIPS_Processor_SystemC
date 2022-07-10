/*
 * tb_whole_MIPS.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */
#include "systemc.h"
#include "alu_systemc.h"
#include "alu_control_systemc.h"
#include "control_unit_systemc.h"
#include "dmem_systemc.h"
#include "instruction_memory_systemc.h"
#include "MIPS_Processor.h"
#include "register_file_systemc.h"
#include "tb_whole_MIPS.cpp"

SC_MODULE (MIPS)
{
    sc_in <bool> clk;
    sc_in <bool> reset;
    sc_out <sc_lv<16>> pc_out;
    sc_out <sc_lv<16>> alu_result;

    sc_signal <bool> clk = 1;
    sc_signal <bool> clk = 1;
    sc_signal <sc_lv<16>> pc_out;
    sc_signal <sc_lv<16>> alu_result;

    const sc_time clk_period (10,SC_NS);

    MIPS_Processor MIPS("MIPS_name");

    MIPS.clk(clk);
    MIPS.reset(reset);
    MIPS.pc_out(pc_out);
    MIPS.alu_result(alu_result);

    // Clock process
    void clk_process()
    {
        clk.write(0);
        wait( clk_period/2 , NS);
        clk.write(1);
        wait( clk_period/2 , NS);
    }
    // Stimulus process
    void stim_proc()
    {
        reset.write(1);
        wait( clk_period*10 , NS);
        reset.write(0);
        wait;
    }
}
