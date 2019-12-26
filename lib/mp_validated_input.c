#include "libmp.h"

#define NO_RECORD 0

void	mp_validated_input(const char *fmt, void *src, const char *err_str, const char *greet)
{
	int	ret_scanf = 0;
	int	trash_stdin;

	do
	{
		fprintf(stdout, "%s", greet);
		// greet();
		ret_scanf = scanf(fmt, src);
		trash_stdin = mp_clean_stdin();
		if (ret_scanf == ERR)
			MP_DIE("mp_validate_input: ret_scanf = ERR");
		else if (ret_scanf == NO_RECORD || trash_stdin)
		{
			mp_warning(err_str);
			mp_warning("Попробуйте еще раз\n");
		}
	} while (ret_scanf <= 0 || trash_stdin);
}

int		mp_check_input(const char *fmt, void *src, const char *err_str)
{
	int	ret = 0;
	int	ret_scanf = 0;
	int	trash_stdin;

	ret_scanf = scanf(fmt, src);
	trash_stdin = mp_clean_stdin();
	if (ret_scanf == ERR)
		MP_DIE("mp_check_input: ret_scanf == ERR");
	else if (ret_scanf == NO_RECORD || trash_stdin)
	{
		mp_warning(err_str);
		mp_warning("Попробуйте еще раз\n");
	}
	else
		ret = 1;
	return (ret);
}
