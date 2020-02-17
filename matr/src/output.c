#include "matr.h"

static void	printMatr(matrix *matr)
{
	for (int i = 0; i < matr->numLines; ++i)
	{
		fprintf(stdout, "%s%d)%s\t", CYAN_COLOR, i + 1, DFLT_COLOR);
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
	fprintf(stdout, "%ssource matrix: %s\n", ORANGE_COLOR, DFLT_COLOR);
	if (srcMatr->numLines)
		printMatr(srcMatr);
	else
		fprintf(stdout, "none\n");
	fprintf(stdout, "%snew Matrix%s\n", GREEN_COLOR, DFLT_COLOR);
	if (newMatr->numLines)
		printMatr(newMatr);
	else
		fprintf(stdout, "none\n");
}
