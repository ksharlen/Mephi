#include "list.h"

#define DOUBLE_NUMBER isdigit(currentSym->c) && currentSym->next\
	&& currentSym->next->c == SPLIT_FOR_DBL_NUM\
	&& currentSym->next->next && isdigit(currentSym->next->next->c)\
	&& !dot

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
	line_t	*currentSym 		= beg->beg;
	int		readStream	= 0;
	int		dot			= 0;

	while (currentSym)
	{
		if (DOUBLE_NUMBER)
		{
			++dot;
			currentSym = currentSym->next->next;
		}
		else if (isspace(currentSym->c))
			dot = 0;
		else if ((!isdigit(currentSym->c)) && !isspace(currentSym->c))
		{
			freeLine(beg);
			printf("%s\n%s\n", INVALID_STRING, REPEAT_INPUT);
			readStream = getLine(beg);
			return (readStream + checkValidateInputString(beg));
		}
		currentSym = currentSym->next;
	}
	return (readStream);
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

void			input(lines_t *lines)
{
	getLines(lines);
}
