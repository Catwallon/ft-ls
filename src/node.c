#include "ft_ls.h"

struct node *create_node(char *path, struct dirent *entry)
{
	struct node *ret = malloc(sizeof(struct node));

	ret->path = ft_strjoin(path, "/");
	ret->path = ft_strjoin(ret->path , entry->d_name);;
	ret->entry = entry;
	ret->childs = NULL;
	if (entry->d_type == DT_DIR && ft_strcmp(entry->d_name, ".") && ft_strcmp(entry->d_name, ".."))
	{
		ft_putstr("\n");
		ft_putstr(ret->path);
		ft_putstr(":\n");
		DIR *dir = opendir(ret->path);
		if (!dir)
			return (NULL);
		for (struct dirent *node_entry; (node_entry = readdir(dir));)
		{
			struct node *node = create_node(ret->path, node_entry);
			if (node)
				add_list(ret->childs, create_list(node));
		}
		closedir(dir);
	}
	else
	{
		ft_putstr(entry->d_name);
		ft_putstr(" ");
	}
	return (ret);
}