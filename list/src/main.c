#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
	printSourceLines(&lines);
	// printf("Source Lines:\n");
	// output(&lines);
	parser(&lines);
	// printf("%sNew Lines:%s\n", GREEN_COLOR, DFLT_COLOR);
	printNewLines(&lines);
	// output(&lines);
	deleteLines(&lines);
	return (0);
}
