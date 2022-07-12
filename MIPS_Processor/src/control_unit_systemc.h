/*
 * control_unit_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef control_unit_systemc_h_
#define control_unit_systemc_h_

#include "systemc.h"

SC_MODULE (control_unit_systemc)
{
    sc_in<sc_lv<3>>opcode;
    sc_in<bool>reset;

    sc_out<sc_lv<2>>reg_dst,mem_to_reg,alu_op;
    sc_out<bool>jump,branch,mem_read,mem_write,alu_src,reg_write,sign_or_zero;

    SC_CTOR(control_unit_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive <<reset<<opcode;
    }

    void Behavioral();
};

#endif
