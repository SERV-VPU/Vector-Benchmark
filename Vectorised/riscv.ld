OUTPUT_ARCH( "riscv" )
ENTRY(_start)

__STACK_SIZE__ = 0x50000;
__HEAP_SIZE__ = 0x40000;
SECTIONS
{
  . = 0x00000000;
  .init : { *(.init) }
  .text : { *crt0.o(.text) }
  .text : { *(.text) }
  . = ALIGN(16);
  __DATA_BEGIN__ = .;
  .data : { *(.data) }
  __DATA_END__ = .;
  __BSS_START__ = .;
  .bss : { *(.bss) }
  __BSS_END__ = .;
  _end = .;
  end = .;
  __global_pointer$ = MAX(__DATA_BEGIN__ + 0x800, __BSS_END__ - 0x800);
  __stack_pointer = _end + __HEAP_SIZE__ + __STACK_SIZE__;
}
