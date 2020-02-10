#include "matr.h"

static void	deleteLine(struct line *line)
{
	if (line && line->value && line->sizeLine)
	{
		free(line->value);
		*line = EMPTY_LINE;
	}
}

static void	deleteMatrix(matrix *matr)
{
	size_t	currLine = 0;

	while (currLine < matr->numLines)
		deleteLine(&matr->lines[currLine++]);
	free(matr->lines);
	*matr = EMPTY_MATRIX;
}

void	erase(matrix *srcMatr, matrix *newMatr)
{
	if (srcMatr->lines && srcMatr->numLines)
		deleteMatrix(srcMatr);
	if (newMatr->lines && newMatr->numLines)
		deleteMatrix(newMatr);
}
