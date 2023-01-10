#include "soc.h"

void set_mtimecmp(uint32_t time)
{
  reg_timer_data = time;
}

uint32_t get_mtime(void)
{
  return reg_timer_data;
}


void uart_bitbang_poll_out(unsigned char c)
{
	int bits[10];

	bits[8] = 2;
	bits[9] = 1;

	bits[0] = (c & 1 << 0) ? 1 : 2;
	bits[1] = (c & 1 << 1) ? 1 : 2;
	bits[2] = (c & 1 << 2) ? 1 : 2;
	bits[3] = (c & 1 << 3) ? 1 : 2;
	bits[4] = (c & 1 << 4) ? 1 : 2;
	bits[5] = (c & 1 << 5) ? 1 : 2;
	bits[6] = (c & 1 << 6) ? 1 : 2;
	bits[7] = (c & 1 << 7) ? 1 : 2;

	//Start bit
	reg_uart_data = bits[8];
	//Data bits
	reg_uart_data = bits[0];
	reg_uart_data = bits[1];
	reg_uart_data = bits[2];
	reg_uart_data = bits[3];
	reg_uart_data = bits[4];
	reg_uart_data = bits[5];
	reg_uart_data = bits[6];
	reg_uart_data = bits[7];
	//Stop bit
	reg_uart_data = bits[9];
}

int uart_bitbang_poll_in(unsigned char *c)
{
	*c = reg_uart_data;
	return 0;
}

int uart_bitbang_init()
{
    reg_uart_data = 1;
	return 0;
}
