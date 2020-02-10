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

len_t	getSizeNewLine(char *arrayOfDublicate, size_t sizeArr)
{
	size_t	i = 0;
	size_t	qtDublicate = 0;

	while (i < sizeArr)
	{
		if (arrayOfDublicate[i])
			++qtDublicate;
		++i;
	}
	return (qtDublicate);
}

static void	fillNewLine(struct line *newLine, char *arrayOfDublicate, struct line *srcLine)
{
	size_t	currElemArrOfDublicate = 0;
	size_t	currElemArrNewLine = 0;

	newLine->value = (int *)mp_calloc(newLine->sizeLine, sizeof(int));
	while (currElemArrNewLine < srcLine->sizeLine)
	{
		if (arrayOfDublicate[currElemArrOfDublicate])
		{
			newLine->value[currElemArrNewLine] = srcLine->value[currElemArrOfDublicate];
			++currElemArrNewLine;
		}
		++currElemArrOfDublicate;
	}
}

void	getRepeatValue(struct line *srcLine, struct line *newLine)
{
	char	*arrayOfDublicate;

//TODO newLine->value = NULL;
	if (srcLine->sizeLine)
	{
		arrayOfDublicate = (char *)mp_calloc(srcLine->sizeLine, sizeof(char));
		fillArrDublicate(arrayOfDublicate, srcLine);
		newLine->sizeLine = getSizeNewLine(arrayOfDublicate, srcLine->sizeLine);
printf("sizeNewLine: %zd\n", newLine->sizeLine);
//TODO else newLine->value = NULL
		if (newLine->sizeLine)
		{
			fillNewLine(newLine, arrayOfDublicate, srcLine);
		}
		free(arrayOfDublicate);
		arrayOfDublicate = NULL;
	}
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
