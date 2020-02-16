#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
	printSourceLines(&lines);
	parser(&lines);
	printNewLines(&lines);
	deleteLines(&lines);
	return (0);
}
