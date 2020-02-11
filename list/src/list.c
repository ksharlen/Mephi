#include "list.h"

static list_t	*createElemList(char c)
{
	list_t	*new = NULL;

	if (c >= '0' && c <= '9')
	{
		new = mp_calloc(1, sizeof(list_t));
		new->c = c;
		new->next = NULL;
	}
	else
		MP_DIE("Символ не является цифрой");
	return (new);
}

//TODO need check NULL
void			newElemList(infoList_t *list, char c)
{
	list_t	*new = createElemList(c);

	if (list)
	{
		if (list->beg)
		{
			list->end->next = new;
			list->end = new;
		}
		else
		{
			list->beg = new;
			list->end = new;
		}
		++list->size;
	}
}
