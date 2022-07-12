################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MIPS_Processor.cpp \
../src/alu_control_systemc.cpp \
../src/alu_systemc.cpp \
../src/control_unit_systemc.cpp \
../src/dmem_systemc.cpp \
../src/instruction_memory_systemc.cpp \
../src/register_file_systemc.cpp \
../src/tb_whole_MIPS.cpp 

CPP_DEPS += \
./src/MIPS_Processor.d \
./src/alu_control_systemc.d \
./src/alu_systemc.d \
./src/control_unit_systemc.d \
./src/dmem_systemc.d \
./src/instruction_memory_systemc.d \
./src/register_file_systemc.d \
./src/tb_whole_MIPS.d 

OBJS += \
./src/MIPS_Processor.o \
./src/alu_control_systemc.o \
./src/alu_systemc.o \
./src/control_unit_systemc.o \
./src/dmem_systemc.o \
./src/instruction_memory_systemc.o \
./src/register_file_systemc.o \
./src/tb_whole_MIPS.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc23x/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/MIPS_Processor.d ./src/MIPS_Processor.o ./src/alu_control_systemc.d ./src/alu_control_systemc.o ./src/alu_systemc.d ./src/alu_systemc.o ./src/control_unit_systemc.d ./src/control_unit_systemc.o ./src/dmem_systemc.d ./src/dmem_systemc.o ./src/instruction_memory_systemc.d ./src/instruction_memory_systemc.o ./src/register_file_systemc.d ./src/register_file_systemc.o ./src/tb_whole_MIPS.d ./src/tb_whole_MIPS.o

.PHONY: clean-src

