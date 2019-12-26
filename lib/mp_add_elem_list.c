#include "libmp.h"

void	mp_add_elem_list_beg(list **beg, list *need_add)
{
	if (beg && need_add)
	{
		if (*beg)
		{
			need_add->next = (*beg);
			(*beg) = need_add;
		}
		else
		{
			(*beg) = need_add;
			need_add->next = NULL;
		}
	}
	else
		MP_DIE("mp_add_elem_list: invalid list");
}

void	mp_add_elem_list_end(list **beg, list *need_add)
{
	if (beg && need_add)
	{
		if (*beg)
		{
			list *res = (*beg);
			while (res->next)
				res = res->next;
			res->next = need_add;
			need_add->next = NULL;
		}
		else
		{
			(*beg) = need_add;
			need_add->next = NULL;
		}
	}
	else
		MP_DIE("mp_add_elem_list_end: invalid list");
}

void	mp_add_data_elem_list_beg(list **beg, void *content, size_t content_size)
{
	list *new = mp_createelem(content, content_size);
	mp_add_elem_list_beg(beg, new);
}

void	mp_add_data_elem_list_end(list **beg, void *content, size_t content_size)
{
	list *new = mp_createelem(content, content_size);
	mp_add_elem_list_end(beg, new);
}
