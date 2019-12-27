#ifndef LIBMP_H
# define LIBMP_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>

//WINDOWS
# if (defined _WIN64 || defined _WIN32)
#  include <io.h>
#  define WRITE _write
# elif (defined linux || defined __linux__)
#  include <unistd.h>
#  define WRITE write
# endif

// # ifdef _WIN64
// #  include <io.h>
// #  define WRITE _write
// # elif _WIN32
// #  include <io.h>
// #  define WRITE _write
// # endif

//LINUX
# ifdef linux
#  include <unistd.h>
#  define WRITE write
# elif __linux__
#  include <unistd.h>
#  define WRITE write
# endif

# define FULL_PROG

# define P_UNUSED(var) ((void)(var))
# define MP_DIE(err) mp_die(err, __FILE__, __LINE__)

/*
**COLORS
*/
# define DFLT_COLOR	"\x1b[0m"
# define WAR_COLOR	"\x1b[38;2;217;89;208m"
# define ERR_COLOR	"\x1b[38;2;224;58;58m"

/*
**DEFINE
*/
# define ERR	-1

enum	libok
{
	MP_OK,
	MP_KO
};

typedef struct	list
{
	struct list	*next;
	size_t		content_size;
	void		*content;
}				list;

/*
**write
*/
int		mp_write(int fd, const void *buf, size_t bytes);
void	mp_putstr_fd(int fd, const char *str);

/*
**read
*/
int		mp_clean_stdin(void);
void	mp_validated_input(const char *fmt, void *src, const char *err_str, const char *greet);
int		mp_check_input(const char *fmt, void *src, const char *err_str);

/*
**ERRORS
*/
void	mp_die(const char *err, const char *filename, const int line);
void	mp_warning(const char *err);
void	mp_sys_die(const char *err);

/*
**alloc
*/
void	*mp_calloc(size_t numOfElements, size_t sizeOfElements);
void	*mp_malloc(size_t size);
void	mp_memdel(void **ptr);

/*
**LIST
*/
list	*mp_createelem(void *content, size_t content_size);
void	mp_add_elem_list_beg(list **beg, list *need_add);
void	mp_add_elem_list_end(list **beg, list *need_add);
void	mp_add_data_elem_list_beg(list **beg, void *content, size_t content_size);
void	mp_add_data_elem_list_end(list **beg, void *content, size_t content_size);

#endif
