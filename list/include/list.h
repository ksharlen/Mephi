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

# define CLEAN_LINE	(infoLine_t){NULL, NULL, 0}

# define SIZE_BUF 			32

# define FMT_SCANF			"%31[^\n]"
# define CLEAR_STREAM		"%*c"
# define NOT_EOF			0
# define ISEVEN(digit) 		(((digit) - '0') % 2)
# define VALID_VALUE		1
# define NOT_VALID_VALUE	0
# define END_OF_LIST		NULL
# define END_OF_STRING		1
# define NOT_END_OF_STRING	0
# define SRC_LINES			"Source lines:"
# define NEW_LINES			"New lines:"
# define LINE_COLOR			CYAN_COLOR
# define SPLIT_FOR_DBL_NUM	'.'

typedef struct	line_s
{
	char			c;
	struct line_s	*next;
}				line_t;

typedef struct	infoLine
{
	struct infoLine	*next;
	line_t				*beg;
	line_t				*end;
	size_t				size;
}				infoLine_t;

typedef struct	lines
{
	infoLine_t	*beg;
	infoLine_t	*end;
	size_t		qt_lines;
}				lines_t;

/*
**MAIN FUNC
*/
void			input(lines_t *lines);
void			parser(lines_t *lines);
void			printSourceLines(lines_t *lines);
void			printNewLines(lines_t *lines);

/*
**LIST WORLK
*/
void			newElemList(infoLine_t *list, char c);
void			addNewLine(lines_t *lines);

/*
**COMMON
*/
line_t			*deleteSpacesBeforeNum(line_t *current, line_t *lastDigit);
line_t			*getLastDigit(line_t **current);
int				checkValidNumber(line_t *number);
void			setHeadOnFirstValidNumber(infoLine_t *line);
line_t			*deleteNumber(line_t *number);
void			deleteTabsLines(lines_t *lines);

/*
**FREE MEMORY
*/
void			deleteSym(line_t **sym);
void			deleteList(line_t **beg);
void			deleteLines(lines_t *lines);
void			deleteLastLine(lines_t *lines);
void			deleteLine(infoLine_t **beg);
void			freeLine(infoLine_t *line);
void			cleanLine(infoLine_t **line);

#endif
