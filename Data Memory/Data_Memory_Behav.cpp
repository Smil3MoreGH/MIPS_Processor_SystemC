#include Untilted-1

void Data_Memory::Behavioral()
{
    sc_signal <sc_lv<8>> > ram_addr;
    sc_signal <int> i;
    typedef<sc_lv<256>>data_mem[16];

    sc_signal <sc_lv> RAM //?

    ram_addr = mem_access_addr;

    if(clk.event() && mem_write_en == 1)
    {
        ram(to_int(sc_unit(ram_addr))) = mem_write_data;
    }

    if(mem_read == 1)
    {
        mem_read_data =  ram(to_int(sc_unit(ram_addr)))
    }
    else
    {
        mem_read_data = x"0000";
    }
}
