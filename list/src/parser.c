#include "list.h"

// static void	printString(list_t *beg)
// {
// 	while (beg)
// 	{
// 		printf("%c", beg->c);
// 		beg = beg->next;
// 	}
// 	if (!beg)
// 		printf("%p", beg);
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
	}
}

static int	checkValidNumber(list_t *number)
{
	int	validate = VALID_VALUE;

	while (number && isdigit(number->c))
	{
		if (ISEVEN(number->c))
		{
			validate = NOT_VALID_VALIE;
			break ;
		}
		number = number->next;
	}
	return (validate);
}

static list_t	*deleteNumber(list_t *number)
{
	list_t	*tmp = number;

	while (number && isdigit(number->c))
	{
		tmp = number;
		number = number->next;
		deleteSym(&tmp);
	}
	return (number);
}

static void		setHeadOnFirstValidNumber(infoList_t *line)
{
	list_t	*current = line->beg;

	while (current)
	{
		if (isspace(current->c))
		{
			deleteSpacesAtBegin(line);
			current = line->beg;
		}
		else if (isdigit(current->c))
		{
			if (checkValidNumber(current) == VALID_VALUE)
				break ;
			else
				current = deleteNumber(current);
		}
		line->beg = current;
	}
}

static list_t	*getLastDigit(list_t **current)
{
	while (*current)
	{
		if ((isdigit((*current)->c) && (*current)->next && isspace((*current)->next->c)) ||
			(!(*current)->next))
		{
			list_t	*lastDigit = (*current);
			(*current) = (*current)->next;
			return (lastDigit);
		}
		(*current) = (*current)->next;
	}
	return ((*current));
}

static list_t	*deleteSpacesBeforeNum(list_t *current, list_t *lastDigit)
{
	list_t	*tmp;

	while (current && isspace(current->c))
	{
		if (current->next && isdigit(current->next->c))
		{
			lastDigit->next = current;
			current = current->next;
			break ;
		}
		tmp = current;
		current = current->next;
		deleteSym(&tmp);
	}
	return (current);
}

static void	deleteNotValidNumber(infoList_t *line)
{
	list_t	*lastDigit;
	list_t	*current = line->beg;

	while (current)
	{
		lastDigit = getLastDigit(&current);
		if ((current = deleteSpacesBeforeNum(current, lastDigit)) == END_OF_LIST)
		{
			lastDigit->next = NULL;
			break ;
		}
		else
		{
			if (checkValidNumber(current) == NOT_VALID_VALIE)
			{
				current = deleteNumber(current);
				deleteSym(&lastDigit->next);
				lastDigit->next = current;
				if ((current = deleteSpacesBeforeNum(current, lastDigit)) == END_OF_LIST)
				{
					if (lastDigit)
						lastDigit->next = NULL;
					break ;
				}
				else
					current = lastDigit;
			}
		}
	}
	// printStringExt(line->beg);
}

static void	parseLine(infoList_t *line)
{
	if (line && line->beg && line->size)
	{
		setHeadOnFirstValidNumber(line);
		if (line->beg)
		{
			deleteNotValidNumber(line);
		}
	}
}

void	parser(lines_t *lines)
{
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
