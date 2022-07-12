/*
 * alu_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "alu_systemc.h"

void alu_systemc::Behavioral()
{
	switch (alu_control.read().to_uint())
    {
        case 0: alu_result.write(a.read().to_uint() + b.read().to_uint());
            break;
        case 1: alu_result.write(a.read().to_uint() - b.read().to_uint());
            break;
        case 2: alu_result.write(a.read() & b.read());
            break;
        case 3: alu_result.write(a.read() | b.read());
            break;
        case 4:
            if (a.read().to_uint() < b.read().to_uint())
            	alu_result = 0x0001;
            else
            	alu_result = 0x0000;
            break;
        default: alu_result.write(a.read().to_uint() + b.read().to_uint());
    }
    if (alu_result.read() == 0x0000)
        zero.write(1);
    else
        zero.write(0);
}
/*
int sc_main(int argc, char* argv[])
{
	sc_signal <sc_lv<16>> a;
	sc_signal <sc_lv<16>> b;
	sc_signal <sc_lv<16>> alu_result;
	sc_signal <sc_lv<3>> alu_control;
	sc_signal <bool> zero;

	sc_trace_file *trace_file;
	trace_file = sc_create_vcd_trace_file("trace");
	trace_file->set_time_unit(1,SC_NS);

	alu_systemc uut("uut");

	uut.a(a);
	uut.b(b);
	uut.alu_result(alu_result);
	uut.alu_control(alu_control);
	uut.zero(zero);

	sc_trace(trace_file , a, "a");
	sc_trace(trace_file , b, "b");
	sc_trace(trace_file , alu_result, "alu_result");
	sc_trace(trace_file , alu_control, "alu_control");
	sc_trace(trace_file , zero, "zero");

	a = "0000000100001001";
	b = "0000010001000001";
	alu_control = 0;
	zero = 0;

	sc_start(10,SC_NS);

	alu_control = 1;

	sc_start(10,SC_NS);

	alu_control = 2;

	sc_start(10,SC_NS);

	alu_control = 3;

	sc_start(10,SC_NS);

	alu_control = 4;

	sc_start(10,SC_NS);

	return 0;
}
*/
