/*
 * alu_control_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul
 */

#ifndef alu_control_systemc_h_
#define alu_control_systemc_h_

#include <systemc.h>

SC_MODULE(alu_control_systemc)
{

    sc_in <sc_lv<2>> ALUOp;
    sc_in <sc_lv<3>> ALU_Funct;
    sc_out <sc_lv<3>> ALU_Control;

    SC_CTOR(alu_control_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive << ALUOp << ALU_Funct;
    }

    void Behavioral();
};

#endif
