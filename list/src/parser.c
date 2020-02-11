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

static list_t	*deleteExtraSpacesInsideString(infoList_t *line, list_t *curr)
{
	if (line->beg == curr)
		deleteSpacesAtBegin(line);
	else
	{
		list_t	*tmp;
		//TODO удаляем все пробелы подряд кроме одного последнего перед числом, но если числа нет, удаляем и этот пробел
		while (curr)
		{
			if (isspace(curr->c))
			{
				if ((curr->next && !isdigit(curr->next->c)) || (!curr->next))
				{
					tmp = curr;
					curr = curr->next;
					deleteSym(&curr);
				}
				else
					break ;
			}
		}
	}
	return (curr);
}

static list_t	*deleteNumber(list_t *number)
{
	list_t	*tmp;

	while (number && !isspace(number->c))
	{
		tmp = number;
		number = number->next;
		deleteSym(&number);
	}
	return (number);
}

//TODO до пробела или до конца строки
static list_t	*checkNumberForParityOfBits(infoList_t *line, list_t *curr)
{
	list_t	*begBit = curr;

	while (curr && !isspace(curr->c))
	{
		if (!ISEVEN(curr->c))
		{
			curr = deleteNumber(curr);
			if (begBit == line->beg)
				line->beg = curr;
			break ;
		}
		curr = curr->next;
	}
	return (curr);
}

static void deleteExtraNumbers(infoList_t *line)
{
	list_t	*curr = line->beg;
	list_t	*res;

	while (curr)
	{
		curr = checkNumberForParityOfBits(line, curr);
		if (!curr)
			break ;
		curr = deleteExtraSpacesInsideString(line, curr);
	}
	// printf("here\n");
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
// output(lines);
// exit(EXIT_FAILURE);
			curr = curr->next;
		}
	}
}
