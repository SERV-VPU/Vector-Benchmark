#include "tinyio.h"
#include "soc.h"

void _putchar(char c)
{
    uart_bitbang_poll_out(c);
}