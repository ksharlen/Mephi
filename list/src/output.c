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
		size_t		i = 0;
		infoList_t	*curr;

		curr = lines->beg;
		while (i < lines->qt_lines)
		{
			printLine(curr);
			curr = curr->next;
			++i;
		}
	}
	else
		printf("none\n");
}
