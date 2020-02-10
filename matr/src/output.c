#include "matr.h"

static void	printMatr(matrix *matr)
{
	for (int i = 0; i < matr->numLines; ++i)
	{
		fprintf(stdout, "%d)\t", i + 1);
		if (matr->lines[i].sizeLine)
			for (int j = 0; j < matr->lines[i].sizeLine; ++j)
				fprintf(stdout, "%d\t", matr->lines[i].value[j]);
		else
			fprintf(stdout, "none");
		fprintf(stdout, "\n");
	}
}

void		output(matrix *srcMatr, matrix *newMatr)
{
	fprintf(stdout, "\e[2J");
	fprintf(stdout, "\e[H");
	fprintf(stdout, "source matrix: \n");
	if (srcMatr->numLines)
		printMatr(srcMatr);
	else
		fprintf(stdout, "none\n");
	fprintf(stdout, "new Matrix\n");
	if (newMatr->numLines)
		printMatr(newMatr);
	else
		fprintf(stdout, "none\n");
}
