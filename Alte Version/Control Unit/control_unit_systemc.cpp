#include "control_unit_systemc.h"

void control_unit_systemc::Behavioral()
{

    if(reset=1)
    {
        reg_dst.write(00);
        mem_to_reg.write(00);
        alu_op.write (00);
        jump.write(0);
        branch.write (0);
        mem_read.write (0);
        mem_write.write (0);
        alu_src.write (0);
        reg_write.write (0);
        sign_or_zero.write (1);
    }
    else
    {
        switch(opcode)
        {
        case 000:
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
        case 001:
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
        case 010:
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
        case 011:
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
        case 100:
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
        case 101:
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
        case 110:
            reg_dst.write (01);
            mem_to_reg.write (00);
            alu_op.write (00);
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            mem_write.write (0);
            alu_src.write (0);
            reg_write.write (1);
            ign_or_zero.write (1);
            break;
        case 111:
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
        default:
            reg_dst.write (01);
            mem_to_reg.write (00);
            alu_op.write (00)
            jump.write (0);
            branch.write (0);
            mem_read.write (0);
            alu_src.write (0);
            reg_write.write (1);
            sign_or_zero (1);
            break;
        }
    }
}
