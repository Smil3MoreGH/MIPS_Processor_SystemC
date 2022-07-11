#include "systemc.h"

SC_MODULE(MIPS_Processor)
{
    sc_in <sc_lv> clk;
    sc_in <sc_lv> reset;
    
    sc_out <sc_lv<16>> pc_out;
    sc_out <sc_lv<16>> alu_result;
    
    
    SC_CTOR(MIPS_Processor)
    {      
        SC_METHOD(Behavioral);
        sensitive << clk << reset;
    }
    
    void Behavioral();
}
