#include "system.c"

SC_MODULE(alu_systemc)
{
    sc_in <sc_lv<16>> a; // src1
    sc_in <sc_lv<16>> b; // src2

    sc_in <sc_lv<3>> alu_control; // function select
    sc_out <sc_lv<16>> alu_result; // ALU Output Result

    sc_out <sc_logic> zero; //Zero Flag

    
    SC_CTOR(ALU_VHDL)
    {      
        SC_METHOD(Behavioral);
        sensitive << a << b << alu_control;
    }
    
    void Behavioral();
}
