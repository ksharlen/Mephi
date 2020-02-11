#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
printf("beg: %p\nsize: %zd\n", lines.beg, lines.qt_lines);
	deleteLines(&lines);
	return (0);
}
