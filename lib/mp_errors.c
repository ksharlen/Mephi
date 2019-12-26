#include "libmp.h"

void	mp_warning(const char *err)
{
	mp_putstr_fd(STDERR_FILENO, err);
}

void	mp_die(const char *err, const char *filename, const int line)
{
	fprintf(stderr, "%sfilename: %s\nline: %d\nerror: %s%s", ERR_COLOR, filename, line, err, DFLT_COLOR);
	exit(EXIT_FAILURE);
}

void	mp_sys_die(const char *err)
{
	perror((err && *err) ? err : "");
	exit(EXIT_FAILURE);
}
