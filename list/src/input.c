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
