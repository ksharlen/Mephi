#include "list.h"

static line_t	*createElemList(char c)
{
	line_t	*new = NULL;

	new = mp_calloc(1, sizeof(line_t));
	new->c = c;
	new->next = NULL;
	return (new);
}

void			newElemList(infoLine_t *list, char c)
{
	line_t	*new = createElemList(c);

	if (list)
	{
		if (list->beg)
			list->end->next = new;
		else
			list->beg = new;
		list->end = new;
		++list->size;
	}
}

infoLine_t	*createNewLine(void)
{
	infoLine_t	*new;

	new = (infoLine_t *)mp_calloc(1, sizeof(infoLine_t));
	new->beg = NULL;
	new->end = NULL;
	new->next = NULL;
	new->size = 0;
	return (new);
}

void		addNewLine(lines_t *lines)
{
	infoLine_t	*new = createNewLine();

	if (lines)
	{
		if (lines->beg)
		{
			lines->end->next = new;
			lines->end = new;
		}
		else
		{
			lines->beg = new;
			lines->end = new;
		}
		++lines->qt_lines;
	}
}
