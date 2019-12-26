#include "libmp.h"

void	*mp_calloc(size_t numOfElements, size_t sizeOfElements)
{
	if (numOfElements && sizeOfElements)
	{
		void	*mem;
		mem = calloc(numOfElements, sizeOfElements);
		if (!mem)
			MP_DIE("mp_calloc: calloc does not allocated");
		return (mem);
	}
	else
		MP_DIE("mp_calloc: invalid size");
	return (NULL);
}

void	*mp_malloc(size_t size)
{
	if (size)
	{
		void	*mem;

		mem = malloc(size);
		if (!mem)
			MP_DIE("mp_malloc: malloc does not allocated");
		return (mem);
	}
	else
		MP_DIE("mp_malloc: invalid size");
	return (NULL);
}

void	mp_memdel(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	else
		mp_warning("nothing free");
}
