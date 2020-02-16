#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
	printf("Source Lines:\n");
	output(&lines);
	parser(&lines);
	printf("%sNew Lines:%s\n", GREEN_COLOR, DFLT_COLOR);
	output(&lines);
	deleteLines(&lines);
	return (0);
}
