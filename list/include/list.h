#ifndef LIST_H
# define LIST_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "libmp.h"

# define INVALID_STRING	"Вы ввели строку состоящую не только из чисел"
# define REPEAT_INPUT	"Повторите ввод"
# define GREETING		"Введите строку:"

# define INIT_LIST {NULL, NULL, 0}
# define INIT_LINES {NULL, NULL, 0}

# define CLEAN_LINE	(infoList_t){NULL, NULL, 0}

# define SIZE_BUF 32

# define FMT_SCANF		"%31[^\n]"
# define CLEAR_STREAM	"%*c"
# define NOT_EOF		0
# define ISEVEN(digit) (((digit) - '0') % 2)

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
	size_t		qt_lines;
}				lines_t;

/*
**MAIN FUNC
*/
void			input(lines_t *lines);
void			output(lines_t *lines);
void			parser(lines_t *lines);

/*
**LIST WORLK
*/
void			newElemList(infoList_t *list, char c);
void			addNewLine(lines_t *lines);


/*
**FREE MEMORY
*/
void			deleteSym(list_t **sym);
void			deleteList(list_t **beg);
void			deleteLines(lines_t *lines);
void			deleteLastLine(lines_t *lines);
void			deleteLine(infoList_t **beg);
void			freeLine(infoList_t *line);
void			cleanLine(infoList_t **line);

#endif
