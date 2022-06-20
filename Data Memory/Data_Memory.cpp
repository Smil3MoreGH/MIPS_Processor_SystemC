#include <systemc>

SC_MODULE(Data_Memory)
{
    sc_in<sc_logic>clk;
    sc_in<sc_lv<16>>mem_access_addr;
    sc_in<sc_lv<16>>mem_write_data;
    sc_in<sc_logic>mem_write_en;
    sc_in<sc_logic>mem_read;
    sc_out<sc_lv<16>>mem_read_data;
}

SC_CTOR(Data_Memory)
{
    SC_METHOD(Behavioral);
    sensitive << clk
}