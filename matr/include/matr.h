#ifndef MATR_H
# define MATR_H

# include <stdio.h>
# include <io.h>
# include <locale.h>

# include "libmp.h"
# include "structs.h"
# include "mp_types.h"

# define MATR_INIT {NULL, 0}

# define INPUT_NUM_LINES	"������� ���-�� �����: "
# define INPUT_SIZE_LINE	"������� ���-�� ��������� ������: "

# define INVALID_NUM_LINES	"�� ����� �������� ���-�� �����\r\n"
# define INVALID_SIZE_LINE	"�� ����� �������� ���-�� ��������� ������\r\n"
# define INVALID_VALUE		"�� ����� �������� �������� ��������\r\n"\

# define REPEAT_INPUT		"���������� ��� ���"

void	input(matrix *matr);
void	printMatr(matrix *matr);

#endif
