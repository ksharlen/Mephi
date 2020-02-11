#include "list.h"

void	convertBufToList(infoList_t *list, char *buf)
{
	while (*buf)
		newElemList(list, *buf++);
}

int		getLine(infoList_t *beg)
{
	char	buf[SIZE_BUF] = {0};
	int		retScanf;

	do
	{
		retScanf = scanf(FMT_SCANF, buf);
		if (retScanf > 0)
		{
			convertBufToList(beg, buf);
			bzero(buf, SIZE_BUF);
		}
		else if (!retScanf)
			scanf(CLEAR_STREAM);
	}
	while (retScanf > 0);
	if (retScanf == EOF)
		;//TODO Удалить последнюю строку
	return (retScanf);
}

static void	checkValidateInputString(infoList_t *beg)
{
	list_t	*curr = beg->beg;

	while (curr)
	{
		if (!isdigit(curr->c) || !isspace(curr->c))
		{
			//DELTE LINE REPEAT INPUT
		}
		curr = curr->next;
	}
}

void	getLines(lines_t *lines)
{
	int	readStream;

	do
	{
		addNewLine(lines);
		readStream = getLine(lines->end);
		checkValidateInputString(lines->end);
		//TODO CHECK_INPUT в цикле
	} while (readStream != EOF);
}

//TODO TMP FUNC
static void	print_lines(lines_t *lines)
{
	while (lines->beg)
	{
		while (lines->beg->beg)
		{
			printf("%c", lines->beg->beg->c);
			lines->beg->beg = lines->beg->beg->next;
		}
		printf("\n");
		lines->beg = lines->beg->next;
	}
	printf("\n");
}

void	input(lines_t *lines)
{
	getLines(lines);
	printf("%slines:%s\n", WAR_COLOR, DFLT_COLOR);
	print_lines(lines);
}
