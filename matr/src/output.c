#include "matr.h"

void	printMatr(matrix *matr)
{
	fprintf(stdout, "\nsource matrix:\n");
	for (int i = 0; i < matr->numLines; ++i)
	{
		for (int j = 0; j < matr->lines[i].sizeLine; ++j)
		{
			fprintf(stdout, "%d\t", matr->lines[i].value[j]);
		}
		fprintf(stdout, "\n");
	}
}
