#include "list.h"

line_t	*getLastDigit(line_t **current)
{
	while (*current)
	{
		if ((isdigit((*current)->c) && (*current)->next && isspace((*current)->next->c)) ||
			(!(*current)->next))
		{
			line_t	*lastDigit = (*current);
			(*current) = (*current)->next;
			return (lastDigit);
		}
		(*current) = (*current)->next;
	}
	return ((*current));
}

line_t	*deleteSpacesBeforeNum(line_t *current, line_t *lastDigit)
{
	line_t	*tmp;

	while (current && isspace(current->c))
	{
		if (current->next && isdigit(current->next->c))
		{
			lastDigit->next = current;//TODO: need refact!
			current = current->next;
			break ;
		}
		tmp = current;
		current = current->next;
		deleteSym(&tmp);
	}
	return (current);
}

int		checkValidNumber(line_t *number)
{
	int	validate = VALID_VALUE;

	while (number && (isdigit(number->c) || number->c == SPLIT_FOR_DBL_NUM))
	{
		if (number->c == SPLIT_FOR_DBL_NUM)
			number = number->next;
		if (ISEVEN(number->c))
		{
			validate = NOT_VALID_VALUE;
			break ;
		}
		number = number->next;
	}
	return (validate);
}

static line_t	*getNextSymAfterSpaces(infoLine_t *line)
{
	line_t	*curr = line->beg;

	while (curr && isspace(curr->c))
		curr = curr->next;
	return (curr);
}

static void	deleteSpacesAtBegin(infoLine_t *line)
{
	line_t	*curr;

	curr = getNextSymAfterSpaces(line);
	if (curr == NULL)
		cleanLine(&line);
	else if (line->beg != curr)
	{
		line_t	*tmp;

		while (line->beg != curr)
		{
			tmp = line->beg;
			line->beg = line->beg->next;
			deleteSym(&tmp);
		}
	}
}

void		setHeadOnFirstValidNumber(infoLine_t *line)
{
	line_t	*current = line->beg;

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

void	deleteTabsLine(infoLine_t *line)
{
	if (line->beg)
	{
		line_t	*curr = line->beg;

		while (curr)
		{
			if (isspace(curr->c) && curr->c != ' ')
				curr->c = ' ';
			curr = curr->next;
		}
	}
}

void	deleteTabsLines(lines_t *lines)
{
	infoLine_t	*curr = lines->beg;

	while (curr)
	{
		deleteTabsLine(curr);
		curr = curr->next;
	}

}
