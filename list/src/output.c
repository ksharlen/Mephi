#include "list.h"

static void	printLine(infoList_t *line)
{
	if (line->beg)
	{
		line_t	*curr = line->beg;

		while (curr)
		{
			printf("%c", curr->c);
			curr = curr->next;
		}
	}
	else
		printf("none");
	printf("\n");
}

void	output(lines_t *lines)
{
	if (lines && lines->beg)
	{
		infoList_t	*curr;
		size_t		i = 1;

		curr = lines->beg;
		printf("%snewList:%s\n", GREEN_COLOR, DFLT_COLOR);
		while (curr)
		{
			printf("line %zd:>", i++);
			printLine(curr);
			curr = curr->next;
		}
	}
	else
		printf("none\n");
}
