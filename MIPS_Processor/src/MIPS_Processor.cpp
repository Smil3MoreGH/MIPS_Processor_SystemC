/*
 * MIPS_Processor.cpp
 *
 *  Created on: Jul 08, 2022
 *      Author: paul hartung
 */

#include "MIPS_Processor.h"

#include "instruction_memory_systemc.cpp"
#include "control_unit_systemc.cpp"
#include "register_file_systemc.cpp"
#include "alu_control_systemc.cpp"
#include "alu_systemc.cpp"
#include "dmem_systemc.cpp"


void MIPS_Processor::main()
{

    sc_signal <sc_lv<16>> pc_current, pc_next, pc2, instr;

    sc_signal <sc_lv<2>> reg_dst, mem_to_reg, alu_op;

    sc_signal <bool> jump, branch, mem_read, mem_write, alu_src, reg_write;

    sc_signal <sc_lv<3>> reg_write_dest;
    sc_signal <sc_lv<16>> reg_write_data;

    sc_signal <sc_lv<3>> reg_read_addr_1;
    sc_signal <sc_lv<16>> reg_read_data_1;

    sc_signal <sc_lv<3>> reg_read_addr_2;
    sc_signal <sc_lv<16>> reg_read_data_2;

    sc_signal <sc_lv<3>> ALU_Control;
    sc_signal <sc_lv<16>> ALU_out;

    sc_signal <sc_lv<16>> sign_ext_im, read_data2, zero_ext_im, imm_ext;

    sc_signal <bool> zero_flag, JRControl, beq_control;

    sc_signal <sc_lv<16>> im_shift_1, PC_j, PC_beq, PC_4beq, PC_4beqj, PC_jr;

    sc_signal <sc_lv<15>> jump_shift_1;
    sc_signal <sc_lv<16>> mem_read_data;
    sc_signal <sc_lv<16>> no_sign_ext;
    sc_signal <bool> sign_or_zero;
    sc_signal <sc_lv<9>> tmp1;

    sc_signal <sc_lv<1>> test;

    if (reset == 1)
        pc_current.write("x0000");
    else if (clk.event())
        pc_current.write(pc_next);

    pc2.write(pc_current + "x0002");

    // Create an instance of instruction_memory_systemc
    instruction_memory_systemc instruction_memory("instruction_memory_name");

    // Connect the IO ports of instruction_memory
    instruction_memory.pc(pc_current);
    instruction_memory.instruction(instr);

    jump_shift_1.write(instr.read().range(13,0) & "0");

    // Create an instance of control_unit_systemc
    control_unit_systemc control_unit("control_unit_name");

    // Connect the IO ports of control_unit_systemc
    control_unit.reset(reset);
    control_unit.opcode(instr.read().range(15,13));
    control_unit.reg_dst(reg_dst);
    control_unit.mem_to_reg(mem_to_reg);
    control_unit.alu_op(alu_op);
    control_unit.jump(jump);
    control_unit.branch(branch);
    control_unit.mem_read(mem_read);
    control_unit.mem_write(mem_write);
    control_unit.alu_src(alu_src);
    control_unit.reg_write(reg_write);
    control_unit.sign_or_zero(sign_or_zero);

    if (reg_dst == "10")
        reg_write_dest.write(111);
    else if(reg_dst == "01")
        reg_write_dest.write(instr.read().range(6,4));
    else
        reg_write_dest.write(instr.read().range(9,7));

    reg_read_addr_1.write(instr.read().range(12,10));
    reg_read_addr_2.write(instr.read().range(9,7));

    // Create an instance of register_file_systemc
    register_file_systemc register_file("register_file_name");

    // Connect the IO ports of register_file_systemc
    register_file.clk(clk);
    register_file.rst(reset);
    register_file.reg_write_en(reg_write);
    register_file.reg_write_dest(reg_write_dest);
    register_file.reg_write_data(reg_write_data);
    register_file.reg_read_addr_1(reg_read_addr_1);
    register_file.reg_read_data_1(reg_read_data_1);
    register_file.reg_read_addr_2(reg_read_addr_2);
    register_file.reg_read_data_2(reg_read_data_2);

    tmp1.write(others => instr[6]);
    sign_ext_im.write(instr.read().range(6,0) & tmp1);
    zero_ext_im.write("000000000" & instr.read().range(6,0));
    if(sign_or_zero == 1)
        imm_ext.write(sign_ext_im);
    else
        imm_ext.write(zero_ext_im);

    if(alu_op == 00 && instr.read().range(3,0) == 1000)
        JRControl.write(1);
    else
        JRControl.write(0);

    // Create an instance of alu_control_systemc
    alu_control_systemc alu_control("alu_control_name");

    // Connect the IO ports of alu_control_systemc
    alu_control.ALUOp(alu_op);
    alu_control.ALU_Funct(instr.read().range(2,0));
    alu_control.ALU_Control(ALU_Control);

    if(alu_src == 1)
        read_data2.write(imm_ext);
    else
        read_data2.write(reg_read_data_2);

    // Create an instance of alu_systemc
    alu_systemc alu("alu_name");

    // Connect the IO ports of alu_systemc
    alu.a(reg_read_data_1);
    alu.b(read_data2);
    alu.alu_control(ALU_Control);
    alu.alu_result(ALU_out);
    alu.zero(zero_flag);

    im_shift_1.write(imm_ext.read().range(14,0) & "0");
    no_sign_ext.write(!im_shift_1 + "x0001");

    if(im_shift_1.read().get_bit(15) == 1)
        PC_beq.write(pc2 - no_sign_ext);
    else
        PC_beq.write(pc2 + im_shift_1);

    beq_control.write(branch & zero_flag);

    if(beq_control == "1")
        PC_4beq.write(PC_beq);
    else
        PC_4beq.write(pc2);

        PC_j.write(pc2.read().get_bit(15) & jump_shift_1);

    if(jump == 1)
        PC_4beqj.write(PC_j);
    else
        PC_4beqj.write(PC_4beq);

    PC_jr.write(reg_read_data_1);

    if(JRControl == 1)
        pc_next.write(PC_jr);
    else
        pc_next.write(PC_4beqj);

    // Create an instance of data_memory_systemc
    dmem_systemc data_memory("data_memory_name");

    // Connect the IO ports of data_memory_systemc
    data_memory.clk(clk);
    data_memory.address(ALU_out);
    data_memory.write_data(reg_read_data_2);
    data_memory.MemWrite(mem_write);
    data_memory.MemRead(mem_read);
    data_memory.read_data(mem_read_data);

    if(mem_to_reg == 10)
        reg_write_data.write(pc2);
    else if(mem_to_reg == 01)
        reg_write_data.write(mem_read_data);
    else
        reg_write_data.write(ALU_out);

    pc_out.write(pc_current);
    alu_result.write(ALU_out);
}
