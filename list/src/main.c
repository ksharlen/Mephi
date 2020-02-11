#include "list.h"

int		main(void)
{
	infoList_t	list = INIT_LIST;
	list_t	*ptr;

	getLine(&list);
ptr = list.beg;
printf("size: %zd\n", list.size);
printf("str: ");
while (ptr)
{
	printf("%c", ptr->c);
	ptr = ptr->next;
}
	return (0);
}
