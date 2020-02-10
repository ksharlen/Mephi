#ifndef MATR_H
# define MATR_H

# include <stdio.h>
# include <locale.h>

# include "libmp.h"
# include "mp_types.h"

# define MATR_INIT {NULL, 0}

# define INPUT_NUM_LINES	"Введите кол-во строк: "
# define INPUT_SIZE_LINE	"Введите размер строки: "

# define INVALID_NUM_LINES	"Вы ввели неверное кол-во строк\n"
# define INVALID_SIZE_LINE	"Вы ввели неверный размер строки\n"
# define INVALID_VALUE		"Вы ввели неверное значение\n"

# define REPEAT_INPUT		"Повторите еще раз"

# define TRUE	1
# define FALSE	0

struct line
{
	len_t	sizeLine;
	int		*value;
};

typedef struct	matr
{
	struct line *lines;
	size_t		numLines;
}				matrix;

void	input(matrix *matr);
void	printMatr(matrix *matr);
matrix	parser(matrix *src_matr);

#endif
