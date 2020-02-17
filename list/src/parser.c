#include "list.h"

line_t		*deleteNumber(line_t *number)
{
	line_t	*tmp = number;

	while (number && (isdigit(number->c) || number->c == SPLIT_FOR_DBL_NUM))
	{
		tmp = number;
		number = number->next;
		deleteSym(&tmp);
	}
	return (number);
}

static int		deleteNotValidNumber(line_t **number, line_t **lastDigit)
{//TODO: need refact
	(*number) = deleteNumber(*number);
	deleteSym(&(*lastDigit)->next);
	(*lastDigit)->next = (*number);
	if (((*number) = deleteSpacesBeforeNum(*number, *lastDigit)) == END_OF_LIST)
	{
		if (*lastDigit)
			(*lastDigit)->next = NULL;
		return (END_OF_STRING);
	}
	else
		(*number) = (*lastDigit);
	return (NOT_END_OF_STRING);
}

static void	deleteNotValidNumbers(infoLine_t *line)
{
	line_t	*lastDigit;
	line_t	*current = line->beg;

	while (current)
	{
		lastDigit = getLastDigit(&current);
		if ((current = deleteSpacesBeforeNum(current, lastDigit)) == END_OF_LIST)
		{
			lastDigit->next = NULL;
			break ;
		}
		else if (checkValidNumber(current) == NOT_VALID_VALUE
				&& (deleteNotValidNumber(&current, &lastDigit) == END_OF_STRING))
			break ;
	}
}

static void	parseLine(infoLine_t *line)
{
	if (line && line->beg)
	{
		setHeadOnFirstValidNumber(line);//TODO: need refact
		if (line->beg)
			deleteNotValidNumbers(line);
	}
	// TODO: for tests
	//printStringExt(line->beg);
}

void	parser(lines_t *lines)
{
	if (lines->beg)
	{
		infoLine_t	*current = lines->beg;

		while (current)
		{
			parseLine(current);
			current = current->next;
		}
	}
}
