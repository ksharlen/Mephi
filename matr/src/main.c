#include "matr.h"

int		main(void)
{
	matrix	matr = MATR_INIT;

	setlocale(LC_ALL, "Russian");
	input(&matr);
	printMatr(&matr);
	//parser(&matr)
	//output(&matr)
	return (0);
}
