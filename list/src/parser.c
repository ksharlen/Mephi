#include "list.h"

static void	printString(list_t *beg)
{
	while (beg)
	{
		printf("%c", beg->c);
		beg = beg->next;
	}
	printf("\n");
}

static void	printStringExt(list_t *beg)
{
	printString(beg);
	exit(EXIT_FAILURE);
}

static list_t	*getNextSymAfterSpaces(infoList_t *line)
{
	list_t	*curr = line->beg;

	while (curr && isspace(curr->c))
		curr = curr->next;
	return (curr);
}

// static list_t	*deleteExtraSpacesInsideString(infoList_t *line, list_t *curr)
// {
// 	if (line->beg == curr)
// 	{
// 		deleteSpacesAtBegin(line);
// 		curr = line->beg;
// 	}
// 	else
// 	{
// 		list_t	*tmp;
// 		//TODO удаляем все пробелы подряд кроме одного последнего перед числом, но если числа нет, удаляем и этот пробел
// 		while (curr)
// 		{
// 			if (isspace(curr->c))
// 			{
// 				if ((curr->next && !isdigit(curr->next->c)) || (!curr->next))
// 				{
// 					tmp = curr;
// 					curr = curr->next;
// 					deleteSym(&tmp);
// 				}
// 				else
// 				{
// 					curr = curr->next;
// 					break ;
// 				}
// 			}
// 		}
// 	}
// 	return (curr);
// }

// // static void		cleanGarbage(infoList_t *line, list_t *beforeSym)
// // {
// // 	list_t	*curr = line->beg;

// // 	while (curr && curr->next && curr->next->next && curr->next->next != beforeSym)
// // 		curr = curr->next;
// // 	line->end = curr;
// // 	deleteSym(&curr->next);
// // 	curr->next = NULL;
// // }

// static list_t	*deleteNumber(list_t *number, infoList_t *line)
// {
// 	list_t	*tmp;
// 	list_t	*beginNumber = number;

// 	P_UNUSED(line);
// 	while (number && !isspace(number->c))
// 	{
// 		// if (number == line->end && line->beg != line->end)
// 		// {
// 		// 	cleanGarbage(line, beginNumber);
// 		// 	break ;
// 		// }
// 		tmp = number;
// 		number = number->next;
// 		deleteSym(&tmp);
// 	}
// 	return (number);
// }

// //TODO до пробела или до конца строки
// static list_t	*checkNumberForParityOfBits(infoList_t *line, list_t *curr)
// {
// 	list_t	*begBit = curr;

// // printStringExt(line->beg);
// 	while (curr && !isspace(curr->c))
// 	{
// 		if (ISEVEN(curr->c))
// 		{
// 			curr = deleteNumber(begBit, line);
// 			if (begBit == line->beg)
// 				line->beg = curr;
// 			break ;
// 		}
// 		curr = curr->next;
// 	}
// 	return (curr);
// }

// static void deleteExtraNumbers(infoList_t *line)
// {
// 	list_t	*curr = line->beg;

// 	while (curr)
// 	{
// // exit(EXIT_FAILURE);
// // printf("line->beg: %d\nsizeLine: %zd\n", line->beg->c, line->size);
// // exit(EXIT_FAILURE);
// 		curr = checkNumberForParityOfBits(line, curr);
// // printStringExt(line->beg);
// 		if (!curr)
// 			break ;
// // printf("here\n");
// 		curr = deleteExtraSpacesInsideString(line, curr);
// 	}
// }

// static list_t	*getLastDigitNum(list_t *begNumber)
// {
// 	while (begNumber && begNumber->next && !isspace(begNumber->next->c))
// 		begNumber = begNumber->next;
// 	return (begNumber);
// }

// static void	deleteExtraSpacesAtEndLine(infoList_t *line)
// {
// 	list_t	*lastDigitBeforeDelSpaces;
// 	list_t	*curr = line->beg;

// 	lastDigitBeforeDelSpaces = getLastDigitNum(curr);
// 	curr = lastDigitBeforeDelSpaces->next;
// 	while (curr)
// 	{
// 		if (isdigit(curr->c))
// 		{
// 			lastDigitBeforeDelSpaces = getLastDigitNum(curr);
// 			curr = lastDigitBeforeDelSpaces->next;
// 		}
// 		else
// 			curr = curr->next;
// 	}
// 	deleteExtraSpacesInsideString(line, lastDigitBeforeDelSpaces->next);
// 	line->end = lastDigitBeforeDelSpaces;
// 	line->end->next = NULL;
// // printStringExt(line->beg);
// // printf("digit: %c\n", lastDigitBeforeDelSpaces->c);
// // exit(EXIT_FAILURE);
// // printStringExt(line->beg);
// }

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

static void	parseLine(infoList_t *line)
{
	if (line && line->beg && line->size)
	{
		setHeadOnFirstValidNumber(line);
printf("beg: %p\n", line->beg);
printStringExt(line->beg);
		// deleteSpacesAtBegin(line);
		// if (line->beg)
		// {
		// 	deleteExtraSpacesAtEndLine(line);
		// }
		// if (line->beg)
		// {
		// 	deleteExtraNumbers(line);
		// }
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