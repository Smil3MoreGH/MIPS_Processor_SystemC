#include "systemc"

SC_MODULE(alu_control_systemc)
{
    sc_out <sc_lv<3>> ALU_Control;
    sc_in <sc_lv<2>> ALUOp;
    sc_in <sc_lv<3>> ALU_Funct;

    
    SC_CTOR(alu_control_systemc)
    {      
        SC_METHOD(Behavioral);
        sensitive << ALUOp << ALU_Funct;
    }
    
    void Behavioral();
}
