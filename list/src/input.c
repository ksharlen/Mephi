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

	printf("%s\n", GREETING);
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
	return (retScanf);
}

static void	checkValidateInputString(infoList_t *beg)
{
	list_t	*curr = beg->beg;

	while (curr)
	{
		if (!isdigit(curr->c) && !isspace(curr->c))
		{
			freeLine(beg);
			printf("%s\n%s\n", INVALID_STRING, REPEAT_INPUT);
			getLine(beg);
			checkValidateInputString(beg);
			break ;
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
	} while (readStream != EOF);
	deleteLastLine(lines);
}

void	input(lines_t *lines)
{
	getLines(lines);
}
