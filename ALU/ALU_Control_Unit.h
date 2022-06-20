SC_MODULE(ALU_Control_VHDL)
{
    sc_out <sc_lv<3>> ALU_Control;
    sc_in <sc_lv<2>> ALUOp;
    sc_in <sc_lv<3>> ALU_Funct;

    
    SC_CTOR(ALU_Control_VHDL)
    {      
        SC_METHOD(Behavioral);
        sensitive << ALUOp << ALU_Funct;
    }
    
    void Behavioral();
}
