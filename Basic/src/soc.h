#include <stdint.h>

/* Bitbang UART configuration */
#define UART_BITBANG_BASE 0x40000000

/* Timer configuration */
#define SERV_TIMER_BASE   0x80000000
#define SERV_TIMER_IRQ    7

#define EXIT_BASE   0x90000000

#define reg_timer_data *((uint32_t *)SERV_TIMER_BASE)
#define reg_uart_data *((uint32_t *)UART_BITBANG_BASE)
#define reg_exit_data *((uint32_t *)EXIT_BASE)

void set_mtimecmp(uint32_t time);
uint32_t get_mtime(void);
void uart_bitbang_poll_out(unsigned char c);
int uart_bitbang_poll_in(unsigned char *c);
int uart_bitbang_init();