#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/types.h>
# include <limits.h>

# include "mp_types.h"

struct line
{
	len_t	sizeLine;
	int		*value;
};

typedef struct	matr
{
	struct line *lines;
	size_t		numLines;
}				matrix;

#endif
