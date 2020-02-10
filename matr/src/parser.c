#include "matr.h"

static size_t	getPosNextCheckDublicate(char *arrOfDublicate, size_t sizeArr, size_t i)
{
	while (i < sizeArr)
	{
		if (arrOfDublicate[i])
			++i;
		else
			break ;
	}
	return (i);
}

static void	fillArrDublicate(char *arrOfDublicate, struct line *srcLine)
{
	size_t	i = 0;
	size_t	j;
	int		flag_dublicate = 0;

	while (i < srcLine->sizeLine)
	{
		j = i + 1;
		while (j < srcLine->sizeLine)
		{
			if (srcLine->value[j] == srcLine->value[i])
			{
				arrOfDublicate[j] = 1;
				flag_dublicate = 1;
			}
			++j;
		}
		if (flag_dublicate)
		{
			arrOfDublicate[i] = 1;
			flag_dublicate = 0;
		}
		i = getPosNextCheckDublicate(arrOfDublicate, srcLine->sizeLine, i + 1);
	}
}

static void	print_tmp(char *arrayOfDublicate, size_t size)
{
	size_t	i = 0;

	printf("array:\n");
	while (i < size)
	{
		printf("%d	", arrayOfDublicate[i]);
		++i;
	}
	printf("\n");
}

void	getRepeatValue(struct line *srcLine, struct line *newLine)
{
	char	*arrayOfDublicate;

	arrayOfDublicate = (char *)mp_calloc(srcLine->sizeLine, sizeof(char));
	fillArrDublicate(arrayOfDublicate, srcLine);

print_tmp(arrayOfDublicate, srcLine->sizeLine);

	free(arrayOfDublicate);
	arrayOfDublicate = NULL;
}

matrix	parser(matrix *src_matr)
{
	matrix	newMatr;
	size_t	i = 0;

	newMatr.lines = (struct line *)mp_calloc(src_matr->numLines, sizeof(struct line));
	newMatr.numLines = src_matr->numLines;
	while (i < newMatr.numLines)
	{
		getRepeatValue(&src_matr->lines[i], &newMatr.lines[i]);
		++i;
	}
	return (newMatr);
}
