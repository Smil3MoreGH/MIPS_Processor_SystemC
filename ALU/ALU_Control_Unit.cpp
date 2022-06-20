#include "MIPS_ALU.h"
 
void alu_control_systemc::Behavioral()
{
    sc_signal <sc_lv<16>> result;

    switch (ALUOp.read())
    {
        case 00: ALU_Control.write(ALU_Funct.range);
            break;
        case 01: ALU_Control.write(001);
            break;
        case 10: ALU_Control.write(100);
            break;
        case 11: ALU_Control.write(000);
            break;
        default: ALU_Control.write(000);
    }
}
