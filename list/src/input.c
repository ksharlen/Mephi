#include "list.h"

static void		convertBufToList(infoList_t *list, char *buf)
{
	while (*buf)
		newElemList(list, *buf++);
}

static int		getLine(infoList_t *beg)
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

static int		checkValidateInputString(infoList_t *beg)
{
	line_t	*curr = beg->beg;
	int		readStream = EOF;

	while (curr)
	{
		if (!isdigit(curr->c) && !isspace(curr->c))
		{
			freeLine(beg);
			printf("%s\n%s\n", INVALID_STRING, REPEAT_INPUT);
			if (getLine(beg) == EOF)
				return (readStream);
			checkValidateInputString(beg);
			break ;
		}
		curr = curr->next;
	}
	return (0);
}

static void		getLines(lines_t *lines)
{
	int	readStream;
	int	readRecursiveStream;

	do
	{
		addNewLine(lines);
		readStream = getLine(lines->end);
		readRecursiveStream = checkValidateInputString(lines->end);
	} while (readStream != EOF && readRecursiveStream != EOF);
	deleteLastLine(lines);
}

void	input(lines_t *lines)
{
	getLines(lines);
}
