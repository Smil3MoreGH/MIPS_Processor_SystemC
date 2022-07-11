#include "system.c"

SC_MODULE(data_memory_systemc)
{
    sc_in<sc_logic>clk;
    sc_in<sc_lv<16>>mem_access_addr;
    sc_in<sc_lv<16>>mem_write_data;
    sc_in<sc_logic>mem_write_en;
    sc_in<sc_logic>mem_read;
    sc_out<sc_lv<16>>mem_read_data;
    
    SC_CTOR(data_memory_systemc)
    {
        SC_METHOD(Behavioral);
        sensitive << clk;
    }
    
    void Behavioral();
}
