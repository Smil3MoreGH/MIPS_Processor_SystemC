/*
 * control_unit_systemc.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "control_unit_systemc.h"

void control_unit_systemc::Behavioral()
{

    if(reset.read() == 1)
    {
        reg_dst.write(00);
        mem_to_reg.write(00);
        alu_op.write(00);

        jump.write(0);
        branch.write(0);
        mem_read.write(0);
        mem_write.write(0);
        alu_src.write(0);
        reg_write.write(0);
        sign_or_zero.write(1);
    }
    else
    {
        switch(opcode.read().to_uint())
        {
        case 0:
            reg_dst.write (01);
            mem_to_reg.write (00);
            alu_op.write (00);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (0);
            reg_write.write (1);
            sign_or_zero.write (1);
            break;
        case 1:
            reg_dst.write (00);
            mem_to_reg.write (00);
            alu_op.write (10);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (1);
            reg_write.write (1);
            sign_or_zero.write (0);
            break;
        case 2:
            reg_dst.write (00);
            mem_to_reg.write (00);
            alu_op.write (00);
            jump.write (1);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (0);
            reg_write.write (0);
            sign_or_zero.write (1);
            break;
        case 3:
            reg_dst.write (10);
            mem_to_reg.write (10);
            alu_op.write (00);
            jump.write (1);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (0);
            reg_write.write (1);
            sign_or_zero.write (1);
            break;
        case 4:
            reg_dst.write (00);
            mem_to_reg.write (01);
            alu_op.write (11);
            jump.write (0);
            branch.write (0);
            mem_read.write (1);
            mem_write.write (0);
            alu_src.write (1);
            reg_write.write (1);
            sign_or_zero.write (1);
            break;
        case 5:
            reg_dst.write (00);
            mem_to_reg.write (00);
            alu_op.write (11);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (1);
            alu_src.write (1);
            reg_write.write (0);
            sign_or_zero.write (1);
            break;
        case 6:
            reg_dst.write (00);
            mem_to_reg.write (00);
            alu_op.write (01);
            jump.write (0);
            branch.write (1);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (0);
            reg_write.write (0);
            sign_or_zero.write(1);
            break;
        case 7:
            reg_dst.write (00);
            mem_to_reg.write (00);
            alu_op.write (11);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (1);
            reg_write.write (1);
            sign_or_zero.write (1);
            break;
        default:
            reg_dst.write (01);
            mem_to_reg.write (00);
            alu_op.write (00);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            alu_src.write (0);
            reg_write.write (1);
            sign_or_zero.write (1);
            break;
        }
    }
};
/*
int sc_main(int argc, char* argv[])
{
    sc_signal<sc_lv<3>>opcode;
    sc_signal<bool>reset;

    sc_signal<sc_lv<2>>reg_dst,mem_to_reg,alu_op;
    sc_signal<bool>jump,branch,mem_read,mem_write,alu_src,reg_write,sign_or_zero;

	sc_trace_file *trace_file;
	trace_file = sc_create_vcd_trace_file("trace");
	trace_file->set_time_unit(1,SC_NS);

	control_unit_systemc uut("uut");

	uut.opcode(opcode);
	uut.reset(reset);

	uut.reg_dst(reg_dst);
	uut.mem_to_reg(mem_to_reg);
	uut.alu_op(alu_op);

	uut.jump(jump);
	uut.branch(branch);
	uut.mem_read(mem_read);
	uut.mem_write(mem_write);
	uut.alu_src(alu_src);
	uut.reg_write(reg_write);
	uut.sign_or_zero(sign_or_zero);

	sc_trace(trace_file , opcode, "opcode");
	sc_trace(trace_file , reset, "reset");

	sc_trace(trace_file , reg_dst, "reg_dst");
	sc_trace(trace_file , mem_to_reg, "mem_to_reg");
	sc_trace(trace_file , alu_op, "alu_op");

	sc_trace(trace_file , jump, "jump");
	sc_trace(trace_file , branch, "branch");
	sc_trace(trace_file , mem_read, "mem_read");
	sc_trace(trace_file , mem_write, "mem_write");
	sc_trace(trace_file , alu_src, "alu_src");
	sc_trace(trace_file , reg_write, "reg_write");
	sc_trace(trace_file , sign_or_zero, "sign_or_zero");

	opcode = 0;
	reset = 1;

	reg_dst = "00";
	mem_to_reg = "00";
	alu_op = "00";

	jump = 0;
	branch = 0;
	mem_read = 0;
	mem_write = 0;
	alu_src = 0;
	reg_write = 0;
	sign_or_zero = 0;

	sc_start(10,SC_NS);

	opcode = 1;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 2;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 3;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 4;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 5;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 6;
	reset = 0;
	sc_start(10,SC_NS);

	opcode = 7;
	reset = 0;
	sc_start(10,SC_NS);


	return 0;
}
*/
