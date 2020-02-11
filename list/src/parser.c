#include "list.h"

// static void	printString(list_t *beg)
// {
// 	while (beg)
// 	{
// 		printf("%c", beg->c);
// 		beg = beg->next;
// 	}
// 	printf("\n");
// }

// static void	printStringExt(list_t *beg)
// {
// 	printString(beg);
// 	exit(EXIT_FAILURE);
// }

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
		cleanLine(&line);
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
	{
		deleteSpacesAtBegin(line);
		curr = line->beg;
	}
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
					deleteSym(&tmp);
				}
				else
				{
					curr = curr->next;
					break ;
				}
			}
		}
	}
	return (curr);
}

static void		cleanGarbage(infoList_t *line, list_t *beforeSym)
{
	list_t	*curr = line->beg;

	while (curr && curr->next && curr->next->next && curr->next->next != beforeSym)
		curr = curr->next;
	deleteSym(&curr->next);
	curr->next = NULL;
	line->end = curr->next;
}

static list_t	*deleteNumber(list_t *number, infoList_t *line)
{
	list_t	*tmp;
	list_t	*beginNumber = number;

	P_UNUSED(line);
	while (number && !isspace(number->c))
	{
		if (number == line->end && line->beg != line->end)
		{
			cleanGarbage(line, beginNumber);
		}
		tmp = number;
		number = number->next;
		deleteSym(&tmp);
	}
	return (number);
}

//TODO до пробела или до конца строки
static list_t	*checkNumberForParityOfBits(infoList_t *line, list_t *curr)
{
	list_t	*begBit = curr;

	while (curr && !isspace(curr->c))
	{
		if (ISEVEN(curr->c))
		{
			curr = deleteNumber(begBit, line);
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

	while (curr)
	{
		curr = checkNumberForParityOfBits(line, curr);
		if (!curr)
			break ;
		curr = deleteExtraSpacesInsideString(line, curr);
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