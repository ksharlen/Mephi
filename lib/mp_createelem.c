#include "libmp.h"

list	*mp_createelem(void *content, size_t content_size)
{
	list	*new = NULL;

	if (content && content_size)
	{
		new = (list *)mp_calloc(1, sizeof(list));
		new->content = mp_malloc(content_size);
		memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	else
		MP_DIE("mp_createelem: invalid content or content_size");
	return (new);
}
