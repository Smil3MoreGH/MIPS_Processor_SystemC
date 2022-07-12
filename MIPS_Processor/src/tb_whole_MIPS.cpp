/*
 * tb_whole_MIPS.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */


// IST NUR EIN TEST GEWESEN

#include "tb_whole_MIPS.h"

void tb_whole_MIPS::main()
{
	// Clock process
	clk.write(0);
    wait(clk_period/2);
    clk.write(1);
    wait(clk_period/2);

    // Stimulus process
	reset.write(1);
	wait(clk_period*10);
	reset.write(0);
	wait();
}
