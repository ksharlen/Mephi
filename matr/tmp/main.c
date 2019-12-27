#include <stdio.h>
#include <io.h>
#include <stdlib.h>

struct test
{
	int a;
	int b;
};

int		main(void)
{
	struct test *tmp = NULL;

	// printf("hello world\r\n");
	tmp = (struct test *)calloc(3, sizeof(struct test));
	if (!tmp)
		printf("error");
	tmp[1].a = 42;
	tmp[1].b = 10;
	tmp[2].a = 4;
	tmp[2].b = 111;
	tmp[3].a = 321;
	tmp[3].b = 228;

	printf("tmp[2].a = %d\r\n", tmp[2].a);
	printf("tmp[2].b = %d\r\n", tmp[2].b);
	while (1);
	return (0);
}
