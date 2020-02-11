#include "list.h"

static void	printLine(infoList_t *line)
{
	if (line->beg)
	{
		list_t	*curr = line->beg;

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

		curr = lines->beg;
		printf("%snewList:%s\n", GREEN_COLOR, DFLT_COLOR);
		while (curr)
		{
			printLine(curr);
			curr = curr->next;
		}
	}
	else
		printf("none\n");
}
