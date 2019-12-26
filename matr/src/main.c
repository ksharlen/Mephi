#include "matr.h"

int		main(void)
{
	mp_write(STDOUT_FILENO, "hello", 3);
	// mp_putstr_fd(STDOUT_FILENO, "hello world!");
	return (0);
}
