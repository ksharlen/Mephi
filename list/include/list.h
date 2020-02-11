#ifndef LIST_H
# define LIST_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>

# include "libmp.h"

# define INIT_LIST {NULL, NULL, 0}

typedef struct	list_s
{
	char			c;
	struct list_s	*next;
}				list_t;

typedef struct	infoList_s
{
	list_t	*beg;
	list_t	*end;
	size_t	size;
}				infoList_t;

void			newElemList(infoList_t *list, char c);
void			getLine(infoList_t *list);

#endif
