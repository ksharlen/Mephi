#include "list.h"

static list_t	*getNextSymAfterSpaces(infoList_t *line)
{
	list_t	*curr = line->beg;

	while (curr && isspace(curr->c))
		curr = curr->next;
	return (curr);
}

static void	deleteSpacesAtBegin(infoList_t *line)
{
	list_t	*curr;

	curr = getNextSymAfterSpaces(line);
	if (curr == NULL)
	{
		deleteList(&curr);
		line->beg = NULL;
	}
	else if (line->beg != curr)
	{
		list_t	*tmp;

		while (line->beg != curr)
		{
			tmp = line->beg;
			line->beg = line->beg->next;
			deleteSym(&tmp);
		}
	}//TODO delete spaces at begin
}

static void	deleteExtraSpaces(infoList_t *line)
{
	list_t	*curr;

	curr = line->beg;
	deleteSpacesAtBegin(line);
}

static void	parseLine(infoList_t *line)
{
	if (line && line->size)
	{
		deleteExtraSpaces(line);
		// deleteExtraNumbers(line);
	}
}

void	parser(lines_t *lines)
{
	//TODO del_space
	//TODO check_num
	if (lines->qt_lines && lines->beg)
	{
		infoList_t	*curr = lines->beg;

		while (curr)
		{
			parseLine(curr);
			curr = curr->next;
		}
	}
}
