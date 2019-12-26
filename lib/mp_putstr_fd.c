#include "libmp.h"

void	mp_putstr_fd(int fd, const char *str)
{
	if (str && *str)
	{
		size_t	len = strlen(str);
		mp_write(fd, str, len);
	}
	else
		MP_DIE("str is empty");
}
