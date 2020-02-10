#include "matr.h"

int		main(void)
{
	matrix	srcMatr = MATR_INIT;
	matrix	newMatr = MATR_INIT;

	input(&srcMatr);
	newMatr = parser(&srcMatr);
	output(&srcMatr, &newMatr);
	erase(&srcMatr, &newMatr);
	return (0);
}
