#include "matr.h"

static struct line *alloc_lines(size_t numLines)
{
	return ((struct line *)mp_calloc(numLines, sizeof(struct line)));
}

static void	input_line(struct line *line)
{
	line->value = mp_calloc(line->sizeLine, sizeof(int));
	for (int i = 0; i < line->sizeLine; ++i)
	{
		do
			fprintf(stdout, "������� %d-�� �������: ", i + 1);
		while (!mp_check_input("%d", &line->value[i], INVALID_VALUE));
	}
}

static void input_lines(matrix *matr)
{
	for (int i = 0; i < matr->numLines; ++i)
	{
		do
			fprintf(stdout, "������� ���-�� ��������� %d-�� ������: ", i + 1);
		while (!mp_check_input("%d", &matr->lines[i].sizeLine, INVALID_SIZE_LINE));
		input_line(&matr->lines[i]);
	}
}

void	input(matrix *matr)
{
	if (matr)
	{
		mp_validated_input("%zd", &matr->numLines, INVALID_NUM_LINES, INPUT_NUM_LINES);
		matr->lines = alloc_lines(matr->numLines);
		input_lines(matr);
	}
	else
		MP_DIE("input: invalid matr");
}
