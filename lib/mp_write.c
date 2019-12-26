#include "libmp.h"

int		mp_write(int fd, const void *buf, size_t bytes)
{
	if (buf)
	{
		if (bytes)
		{
			int bw = WRITE(fd, buf, bytes);

			if (bw == (int)bytes)
				return (MP_OK);
			else
				MP_DIE("write error");
		}
		else
			MP_DIE("mp_write: bytes = 0");
	}
	else
		MP_DIE("mp_write: buf = NULL");
	return (MP_KO);
}
