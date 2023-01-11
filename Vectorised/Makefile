PREFIX := riscv64-unknown-elf-
CXX := $(PREFIX)g++
CC := $(PREFIX)gcc
AS := $(PREFIX)as

GENDIR := gen/
OBJDIR := $(GENDIR)obj

TARGET := $(GENDIR)nnalgo.out

COMMON_FLAGS = \
  -fmessage-length=0 \
  -fno-unwind-tables \
  -ffunction-sections \
  -fdata-sections \
  -funsigned-char \
  -Wall \
  -Wextra \
  -Wno-missing-field-initializers \
  -Wno-return-type \
  -Wno-sign-compare \
  -Wno-strict-aliasing \
  -Wno-type-limits \
  -Wno-unused-function \
  -Wno-unused-parameter \
  -fno-delete-null-pointer-checks \
  -nostdlib \
  -march=rv32i -mabi=ilp32 \

CXXFLAGS := \
  -fno-rtti \
  -fno-use-cxa-atexit \
  -fno-threadsafe-statics \
  -fno-exceptions \
  $(COMMON_FLAGS)

CCFLAGS := \
  $(COMMON_FLAGS)

ASFLAGS := \
  -march=rv32imv -mabi=ilp32 \

LDFLAGS += \
  -march=rv32i -mabi=ilp32 \
  -nostartfiles -static \
  -Wl,--gc-sections\
  -Wl,--start-group -lm -lc -lgcc -Wl,--end-group \
  -fno-exceptions \
  -nostdlib -t -lstdc++ -lc -lnosys -lm \
  -Wl,-Triscv.ld \

INCLUDES := \
  -I. \

CC_SRCS := $(shell find src -name "*.cc" -o -name "*.c" -o -name "*.cpp")
S_SRCS := $(shell find src -name "*.S")

ALL_SRCS := \
	$(CC_SRCS) \
	$(S_SRCS)

OBJS := \
  $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(patsubst %.cc,%.o,$(patsubst %.cpp, %.o, $(CC_SRCS))))) \
  $(addprefix $(OBJDIR)/, $(patsubst %.S, %.o, $(S_SRCS)))

$(OBJDIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: %.S
	@mkdir -p $(dir $@)
	${AS} $< ${ASFLAGS} -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) -o $(TARGET)

hex: $(TARGET)
	$(PREFIX)objcopy -O binary $< temp.bin
	python3 makehex.py temp.bin > nnalgo.hex
	rm temp.bin

clean:
	rm -rf $(GENDIR)
	rm nnalgo.hex

echo:
	@echo $(OBJS)

dump: $(TARGET)
	$(PREFIX)objdump -D $< > main.list