#include "list.h"

void	deleteSym(list_t **sym)
{
	if (sym && *sym)
	{
		free(*sym);
		*sym = NULL;
	}
}

void	freeLine(infoList_t *line)
{
	if (line->beg && line->size)
	{
		list_t	*curr;

		while (line->beg)
		{
			curr = line->beg;
			line->beg = line->beg->next;
			free(curr);
		}
		*line = CLEAN_LINE;
	}
	else
		MP_DIE("freeLine: line->beg == NULL || line->size == 0");
}

void	deleteLastLine(lines_t *lines)
{
	if (lines->end && lines->qt_lines)
	{
		infoList_t	*curr = lines->beg;

		if (lines->qt_lines > 1)
		{
			while (curr->next != lines->end)
				curr = curr->next;
		}
		if (lines->end->size)
			freeLine(lines->end);
		else
			free(lines->end);
		lines->end = curr;
		curr->next = NULL;
		--lines->qt_lines;
	}
}

void	deleteLine(infoList_t **beg)
{
	if (*beg && (*beg)->size)
	{
		freeLine(*beg);
		free(*beg);
		(*beg) = NULL;
	}
	else if (*beg)
	{
		free(*beg);
		*beg = NULL;
	}
	else
		MP_DIE("beg == NULL || beg->size == 0");
}

void	deleteLines(lines_t *lines)
{
	if (lines->beg && lines->qt_lines)
	{
		infoList_t	*curr;

		while (lines->beg)
		{
			curr = lines->beg;
			lines->beg = lines->beg->next;
			deleteLine(&curr);
		}
	}
	// else
		// MP_DIE("deleteLines: lines->beg == NULL || lines->qt_lines == 0");
}
