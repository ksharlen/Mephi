#include "list.h"

list_t	*getLastDigit(list_t **current)
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

list_t	*deleteSpacesBeforeNum(list_t *current, list_t *lastDigit)
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

int		checkValidNumber(list_t *number)
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

void		setHeadOnFirstValidNumber(infoList_t *line)
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
