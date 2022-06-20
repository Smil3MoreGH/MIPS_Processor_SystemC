#include "systemc.h"

SC_MODULE (control_unit_systemc)
{
    sc_in<sc_lv<16>>opcode;
    sc_in<sc_logic>reset;

    sc_out<sc_lv<3>>reg_dst,mem_to_reg,alu_op;
    sc_out<sc_logic>jump,branch,mem_read,mem_write,alu_src,reg_write,sign_or_zero;

    SC_CTOR(control_unit_systemc)
    {
        SC_METHOD(Behavioral);
        sensitivie <<reset<<opcode;
    }

    void Behavioral();
}
