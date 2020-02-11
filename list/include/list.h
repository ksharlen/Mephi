#ifndef LIST_H
# define LIST_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>

# include "libmp.h"

# define INIT_LIST {NULL, NULL, 0}
# define INIT_LINES {NULL, NULL}

# define SIZE_BUF 32

# define FMT_SCANF		"%31[^\n]"
# define CLEAR_STREAM	"%*c"
# define NOT_EOF		0

typedef struct	list_s
{
	char			c;
	struct list_s	*next;
}				list_t;

typedef struct	infoList_s
{
	struct infoList_s	*next;
	list_t				*beg;
	list_t				*end;
	size_t				size;
}				infoList_t;

typedef struct	lines
{
	infoList_t	*beg;
	infoList_t	*end;
}				lines_t;

void			newElemList(infoList_t *list, char c);
void			getLine(infoList_t *list);
void			addNewLine(lines_t *lines);

#endif
