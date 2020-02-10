#include "matr.h"

int		isDbl(int *arr, size_t size)
{
	size_t	i = 0;
	int	val = arr[i];

	while (i < size)
	{
		if (val == arr[++i])
			return (TRUE);
	}
	return (FALSE);
}

static size_t	getI(char *arr, size_t size, size_t i)
{
	size_t	j = i + 1;

	j = i + 1;
	while (j < size)
	{
		if (arr[j])
			return (j);
		++j;
	}
	return (j);
}

static void	print_tmp(char *tmp, size_t	size)
{
	size_t i = 0;

	while (i < size)
	{
		printf("%d\n", tmp[i]);
		++i;
	}
}

static char	*getTmpArr(struct line *src_line)
{
	size_t	i = 0;

	char	*tmp = (char *)mp_calloc(src_line->sizeLine, sizeof(char));

	memset(tmp, 1, sizeof(char) * src_line->sizeLine);
	while (i < src_line->sizeLine)
	{
		size_t	j = i + 1;
		int		flag = 0;

		while (j < src_line->sizeLine)
		{
			if (src_line->value[j] == src_line->value[i])
			{
				tmp[j] = 0;
				flag = 1;
			}
			++j;
		}
		if (!flag)
			tmp[i] = 0;
		flag = 0;
		i = getI(tmp, src_line->sizeLine, i);
	}
	return (tmp);
}

static size_t	getSizeNewLine(char *tmp, size_t size)
{
	size_t	numElems = 0;
	size_t	i = 0;

	while (i < size)
	{
		if (tmp[i])
			++numElems;
		++i;
	}
	return (numElems);
}

static void	fill_line(int *newLine, char *tmp, struct line *oldLine)
{
	size_t	i = 0;
	size_t	j = 0;

	while (i < oldLine->sizeLine)
	{
		if (tmp[i])
		{
			newLine[j] = oldLine->value[i];
			++j;
		}
		++i;
	}
}

static void		print_int(struct line *line)
{
	size_t	i = 0;

	while (i < line->sizeLine)
	{
		printf("elem: %d\n", line->value[i]);
		++i;
	}
}

static size_t	getQtRepeat(struct line *src_line, struct line *newLine)
{
	char	*tmp;
	size_t	i = 0;
	size_t	sizeNewLine;

	tmp = getTmpArr(src_line);
	sizeNewLine = getSizeNewLine(tmp, src_line->sizeLine);
	if (sizeNewLine)
	{
		newLine->value = (int *)mp_calloc(sizeNewLine, sizeof(int));
		fill_line(newLine->value, tmp, src_line);
	}
	newLine->sizeLine = sizeNewLine;
	free(tmp);
	return (0);
}

void	getRepeatValue(struct line *line_src_matr, struct line *res_line)
{
	res_line->sizeLine = getQtRepeat(line_src_matr, res_line);

}

static void	print_test(matrix *src)
{
	size_t	i = 0;

	while (i < src->numLines)
	{
		printf("qt_elem: %zd\n", src->lines[i].sizeLine);
		++i;
	}
}

matrix	parser(matrix *src_matr)
{
	matrix	result_matr;
	size_t	i = 0;

	result_matr.lines = (struct line *)mp_calloc(src_matr->numLines, sizeof(struct line));
	result_matr.numLines = src_matr->numLines;
	while (i < result_matr.numLines)
	{
		getRepeatValue(&src_matr->lines[i], &result_matr.lines[i]);
		++i;
	}
// print_test(&result_matr);
	return (result_matr);
}
