/*
 * alu_systemc.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: paul
 */
#include "alu_systemc.h"

void alu_systemc::Behavioral()
{
    sc_signal <sc_lv<16>> result;

    switch (alu_control.read())
    {
        case 000: result = a + b;         // add
            break;
        case 001: result = a - b;         // sub
            break;
        case 010: result = a & b;         // and
            break;
        case 011: result = a | b;         // or
            break;
        case 100:
            if (a<b)
                result = "x0001";
            else
                result = "x0000";
            break;
        default: result = a + b;            // add
    }
    if (result == "x0000")
        zero.write(1);
    else
        zero.write(0);
    alu_result.write(result);
}
