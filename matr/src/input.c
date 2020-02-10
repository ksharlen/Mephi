#include "matr.h"

static struct line *alloc_lines(size_t numLines)
{
	return ((struct line *)mp_calloc(numLines, sizeof(struct line)));
}

static void	input_line(struct line *line)
{
	if (line->sizeLine)
	{
		line->value = mp_calloc(line->sizeLine, sizeof(int));
		for (int i = 0; i < line->sizeLine; ++i)
		{
			do
				fprintf(stdout, "Введите %d-ый элемент: ", i + 1);
			while (!mp_check_input("%d", &line->value[i], INVALID_VALUE));
		}
	}
	else
		line->value = NULL;
}

static void input_lines(matrix *matr)
{
	for (int i = 0; i < matr->numLines; ++i)
	{
		do
			fprintf(stdout, "Введите кол-во элементов %d-й строки: ", i + 1);
		while (!mp_check_input("%d", &matr->lines[i].sizeLine, INVALID_SIZE_LINE));
		input_line(&matr->lines[i]);
	}
}

void	input(matrix *matr)
{
	if (matr)
	{
		mp_validated_input("%zd", &matr->numLines, INVALID_NUM_LINES, INPUT_NUM_LINES);
		if (matr->numLines)
		{
			matr->lines = alloc_lines(matr->numLines);
			input_lines(matr);
		}
		else
			matr->lines = NULL;
	}
	else
		MP_DIE("input: invalid matr");
}
