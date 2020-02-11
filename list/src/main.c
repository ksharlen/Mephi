#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
	output(&lines);
	deleteLines(&lines);
	return (0);
}
