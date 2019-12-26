#include "libmp.h"
#include <locale.h>

int		main(void)
{
	int	a;
	char	buf1[20] = {0};
	char	*test;

	setlocale(LC_ALL, "Russian");
	test = mp_calloc(0, sizeof(char));
	strcpy(test, "hello");
	printf("%s", test);
	mp_memdel((void **)&test);
	return (0);
}
