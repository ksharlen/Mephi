#include "list.h"

int		main(void)
{
	lines_t	lines = INIT_LINES;

	input(&lines);
	printf("old lines:\n");
	output(&lines);
	parser(&lines);
	printf("%snewList:%s\n", GREEN_COLOR, DFLT_COLOR);
	output(&lines);
	deleteLines(&lines);
	return (0);
}
