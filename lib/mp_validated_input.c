#include "libmp.h"

#define NO_RECORD 0

void	mp_validated_input(const char *fmt, void *src, const char *err_str)
{
	int	ret_scanf = 0;
	int	trash_stdin;

	do
	{
		ret_scanf = scanf(fmt, src);
		trash_stdin = mp_clean_stdin();
		if (ret_scanf == ERR)
			MP_DIE("mp_scanf: ret_scanf = ERR");
		else if (ret_scanf == NO_RECORD || trash_stdin)
		{
			mp_warning(err_str);
			mp_putstr_fd(STDOUT_FILENO, "Попробуйте еще раз: ");
		}
	} while (ret_scanf <= 0 || trash_stdin);
}
