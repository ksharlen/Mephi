#include "list.h"


static void		printLine(infoLine_t *line)
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

void	printLines(lines_t *lines)
{
	if (lines && lines->beg)
	{
		infoLine_t	*curr;
		size_t		i = 1;

		curr = lines->beg;
		while (curr)
		{
			printf("%sline %s%zd:>", LINE_COLOR, DFLT_COLOR, i++);
			printLine(curr);
			curr = curr->next;
		}
	}
	else
		printf("none\n");
}

void	printSourceLines(lines_t *lines)
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	printf("%s%s\n%s", ORANGE_COLOR, SRC_LINES, DFLT_COLOR);
	printLines(lines);
}

void	printNewLines(lines_t *lines)
{
	printf("%s%s%s\n", GREEN_COLOR, NEW_LINES, DFLT_COLOR);
	printLines(lines);
}
