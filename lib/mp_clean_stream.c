#include "libmp.h"

int		mp_clean_stdin(void)
{
	int c = 0;
	int	trash = 0;

	while ((c = getchar()) != '\n')
		++trash;
	return (trash);
}

