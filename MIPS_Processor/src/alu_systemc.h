/*
 * alu_systemc.h
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#ifndef alu_systemc_h_
#define alu_systemc_h_

#include "systemc.h"

SC_MODULE(alu_systemc)
{
    sc_in <sc_lv<16>> a;
    sc_in <sc_lv<16>> b;

    sc_in <sc_lv<3>> alu_control;
    sc_out <sc_lv<16>> alu_result;

    sc_out <bool> zero;

    SC_CTOR(alu_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive << a << b << alu_control;
    }

    void Behavioral();
};

#endif
