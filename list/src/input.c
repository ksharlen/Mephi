#include "list.h"

void	convertBufToList(infoList_t *list, char *buf)
{
	while (*buf)
		newElemList(list, *buf++);
}

void	getLine(infoList_t *list)
{
	int		retScanf;
	char	buf[30] = {0};

	do
	{
		retScanf = scanf("%29s", buf);

		if (retScanf == EOF)
		{
			//TODO
			return ;
		}
		else if (retScanf > 0)
		{
			convertBufToList(list, buf);
			bzero(buf, sizeof(char) * 30);
		}
	} while (retScanf > 0);
}

void	getLine(infoList_t *beg)
{
	char	buf[SIZE_BUF] = {0};
	int		retScanf;

	do
	{
		retScanf = scanf(FMT_SCANF, buf);
		if (retScanf > 0)
		{
			//TODO
		}
		else if (!retScanf)
			scanf(CLEAR_STREAM);
	}
	while (retScanf > 0);
	if (retScanf == EOF)
		;//TODO Удалить последнюю строку
	return (retScanf);
}

void	getLines(lines_t *lines)
{
	int	readStream;

	do
	{
		addNewLine(lines);
		getLine(lines->end);
		//TODO CHECK_INPUT в цикле
	} while (readStream != EOF);
}

void	input(lines_t *lines)
{
	getLines(&lines);
}
