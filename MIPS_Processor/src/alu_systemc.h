/*
 * alu_systemc.h
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */
#include "systemc.h"

SC_MODULE(alu_systemc)
{
    sc_in <sc_lv<16>> a; // src1
    sc_in <sc_lv<16>> b; // src2

    sc_in <sc_lv<3>> alu_control; // function select
    sc_out <sc_lv<16>> alu_result; // ALU Output Result

    sc_out <bool> zero; //Zero Flag

    SC_CTOR(alu_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive << a << b << alu_control;
    }

    void Behavioral();
};
