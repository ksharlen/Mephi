#include "list.h"

void	deleteList(line_t **beg)
{
	if (beg && *beg)
	{
		line_t	*tmp;

		while ((*beg))
		{
			tmp = (*beg);
			(*beg) = (*beg)->next;
			free(tmp);
		}
		(*beg) = NULL;
	}
}

void	cleanLine(infoList_t **line)
{
	if (line && *line)
	{
		deleteList(&(*line)->beg);
		(*line)->beg = NULL;
		(*line)->end = NULL;
		(*line)->size = 0;
	}
}

void	deleteSym(line_t **sym)
{
	if (sym && *sym)
	{
		free(*sym);
		*sym = NULL;
	}
}

void	freeLine(infoList_t *line)
{
	if (line->beg)
	{
		line_t	*curr;

		while (line->beg)
		{
			curr = line->beg;
			line->beg = line->beg->next;
			free(curr);
		}
	}
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
	if (*beg)
	{
		freeLine(*beg);
		free(*beg);
		(*beg) = NULL;
	}
	else if (*beg)
		free(*beg);
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
}
