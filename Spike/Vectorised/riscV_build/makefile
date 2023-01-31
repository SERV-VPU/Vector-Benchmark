RV_COMPILER_OPTIONS = -Os -g -static -mabi=ilp32 -march=rv32i -Wall -pedantic 
RV_LINKING_OPTIONS_SPIKE = ${RV_COMPILER_OPTIONS} 

SPIKE_SIM_FLAGS= --isa=RV32IMV    --varch=vlen:32,elen:32
PK_DIR=/opt/riscv/riscv32-unknown-elf/bin

LIB_DIR =  ./

TC_PREFIX = riscv64-unknown-elf-

CC = ${TC_PREFIX}gcc
OBJCOPY = ${TC_PREFIX}objcopy

HEADER_DIR = ../src  \ ../src/NN_operations 
SOURCE_DIR = ../src  \ ../src/NN_operations 

BUILD_DIR = riscV_build

SOURCES += $(wildcard ../src/*.c) $(wildcard ../src/NN_operations/*.c) 
ASSEM_SOURCES = $(wildcard ../src/NN_operations/*.S)
OBJECTS = $(SOURCES:../%.c=%.o)  $(ASSEM_SOURCES:../%.S=%.o) 

NN_algorithms_testbench-riscv_spike.elf: $(OBJECTS)
	${CC} ${RV_LINKING_OPTIONS_SPIKE} -o NN_algorithms_testbench-riscv_spike.elf \
		 -L ${LIB_DIR}  $(OBJECTS)	
		

src/%.o : ../src/%.c  object_DIR
	${CC} ${RV_COMPILER_OPTIONS}  -c -o $@ $< 		

src/NN_operations/%.o :../src/NN_operations/%.c  object_DIR
	${CC} ${RV_COMPILER_OPTIONS}   -c -o $@ $< 		

src/NN_operations/%.o :../src/NN_operations/%.S  object_DIR
	${CC} -Os -g -static -mabi=ilp32 -march=rv32imv -Wall -pedantic   -c -o $@ $< 		


object_DIR:
	make dir

.PHONY : dir
dir:				
	mkdir -p src 
	mkdir -p src/NN_operations		
	
.PHONY : clean
clean:
	rm -f NN_algorithms_testbench-riscv.hex NN_algorithms_testbench-riscv.elf NN_algorithms_testbench-riscv_spike.elf
	rm -f $(OBJECTS) 

.PHONY : spike
spike: NN_algorithms_testbench-riscv_spike.elf
	spike  $(SPIKE_SIM_FLAGS) $(flags) $(PK_DIR)/pk NN_algorithms_testbench-riscv_spike.elf
	