#include "matr.h"

static void	printMatr(matrix *matr)
{
	for (int i = 0; i < matr->numLines; ++i)
	{
		for (int j = 0; j < matr->lines[i].sizeLine; ++j)
		{
			fprintf(stdout, "%d\t", matr->lines[i].value[j]);
		}
		fprintf(stdout, "\n");
	}
}

void		output(matrix *srcMatr, matrix *newMatr)
{
	fprintf(stdout, "source matrix: \n");
	printMatr(srcMatr);
	fprintf(stdout, "new Matrix\n");
	printMatr(newMatr);
}
