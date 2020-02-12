#include "list.h"

static void	printString(list_t *beg)
{
	while (beg)
	{
		printf("%c", beg->c);
		beg = beg->next;
	}
	if (!beg)
		printf("%p", beg);
	printf("\n");
}

static void	printStringExt(list_t *beg)
{
	printString(beg);
	exit(EXIT_FAILURE);
}

list_t		*deleteNumber(list_t *number)
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

static int		deleteNotValidNumber(list_t *number, list_t **lastDigit)
{
	number = deleteNumber(number);
	deleteSym(&(*lastDigit)->next);
	(*lastDigit)->next = number;
	if ((number = deleteSpacesBeforeNum(number, *lastDigit)) == END_OF_LIST)
	{
		if (*lastDigit)
			(*lastDigit)->next = NULL;
		return (END_OF_STRING);
	}
	else
		number = (*lastDigit);
	return (NOT_END_OF_STRING);
}

static void	deleteNotValidNumbers(infoList_t *line)
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
		{//TODO deleteNotCalidNumber
			if (checkValidNumber(current) == NOT_VALID_VALIE)
			{
				if ((deleteNotValidNumber(current, &lastDigit)) == END_OF_STRING)
					break ;
			}
		}
	}
	printStringExt(line->beg);
}

static void	parseLine(infoList_t *line)
{
	if (line && line->beg && line->size)
	{
		setHeadOnFirstValidNumber(line);
		if (line->beg)
			deleteNotValidNumbers(line);
	}
}

void	parser(lines_t *lines)
{
	if (lines->beg)
	{
		infoList_t	*curr = lines->beg;

		while (curr)
		{
			parseLine(curr);
			curr = curr->next;
		}
	}
}
