#include "matr.h"

static void	printNewMatr(matrix *newMatr)
{
	size_t	i = 0;

	while (i < newMatr->numLines)
	{
		size_t	j = 0;
		while (j < newMatr->lines[i].sizeLine)
		{
			printf("%d	", newMatr->lines[i].value[j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

int		main(void)
{
	matrix	matr = MATR_INIT;
	matrix	newMatr;


	setlocale(LC_ALL, "Russian");

	input(&matr);
	newMatr = parser(&matr);
	printMatr(&matr);
	//output(&matr)
	return (0);
}
