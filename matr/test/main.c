#include <stdio.h>
#include <stdlib.h>

struct test
{
	int a;
	int b;
};

int		main(void)
{
	struct test *tes;

	tes = (struct test *)malloc(sizeof(struct test) * 2);
	if (!tes)
		printf("error");
	tes[1].a = 19;
	tes[1].b = 10;
	tes[2].a = 123;
	tes[2].b = 321;

	printf("tes[2].a = %d\n", tes[2].a);
	printf("tes[2].b = %d\n", tes[2].b);
	return (0);
}
