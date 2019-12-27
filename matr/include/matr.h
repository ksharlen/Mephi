#ifndef MATR_H
# define MATR_H

# include <stdio.h>
# include <io.h>
# include <locale.h>

# include "libmp.h"
# include "structs.h"
# include "mp_types.h"

# define MATR_INIT {NULL, 0}

# define INPUT_NUM_LINES	"Введите кол-во строк: "
# define INPUT_SIZE_LINE	"Введите кол-во элементов строки: "

# define INVALID_NUM_LINES	"Вы ввели невернео кол-во строк\r\n"
# define INVALID_SIZE_LINE	"Вы ввели неверное кол-во элементов строки\r\n"
# define INVALID_VALUE		"Вы ввели невернео значение элемента\r\n"\

# define REPEAT_INPUT		"Попробуйте еще раз"

void	input(matrix *matr);
void	printMatr(matrix *matr);

#endif
