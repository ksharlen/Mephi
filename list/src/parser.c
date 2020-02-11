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
		cleanLine(&line);
		// deleteList(&curr);
		// line->size = 0;
		// line->beg = NULL;
		// line->end = NULL;
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

static list_t	*deleteExtraSpacesInsideString(list_t *line)
{
	
}

// static void	deleteExtraSpaces(infoList_t *line)
// {
// 	list_t	*curr;

// 	curr = line->beg;
// 	deleteSpacesAtBegin(line);
// 	if (line->beg)
// 		deleteExtraSpacesInsideString(line);
// 	//TODO need check line if (line->beg != NULL)
// 	//TODO deleteExtraSpacesInsideString()
// }

static list_t	*checkNumberForParityOfBits(list_t *string)
{
	list_t	*res = string;

	while (res && !isspace(res->c))
	{
		if (!ISEVEN(res->c))
		{
			res = deleteNumber(string);
			break ;
		}
		res = res->next;
	}
	return (res);
}

static void deleteExtraNumbers(infoList_t *line)
{
	list_t	*curr = line->beg;
	list_t	*res;

	while (curr)
	{
		curr = сheckNumberForParityOfBits(curr);
		if (!curr)
			break ;
		curr = deleteExtraSpacesInsideString(curr);
	}
}

static void	parseLine(infoList_t *line)
{
	if (line && line->size)
	{
		deleteSpacesAtBegin(line);
		if (line->beg)
			deleteExtraNumbers(line);
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
