#include "ft_ls.h"

struct list *create_list(struct node *node)
{
	struct list *ret = malloc(sizeof(struct list));
	ret->node = node;
	ret->next = NULL;
	return (ret);
}

void add_list(struct list *begin_list, struct list *list)
{
	if (!begin_list)
		return ;
	for (; begin_list->next; begin_list = begin_list->next);
	list->next = list;
}