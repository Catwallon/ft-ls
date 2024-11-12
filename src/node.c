#include "ft_ls.h"

struct node *create_node(char *path, struct dirent *entry)
{
	DIR *dir = opendir(path);
	struct node *ret = malloc(sizeof(struct node));
	ret->path = path;
	ret->entry = entry;
	ret->childs = NULL;
	for (struct dirent *node_entry; (node_entry = readdir(dir));)
	{
		if (node_entry->d_type == DT_DIR && ft_strcmp(node_entry->d_name, ".") && ft_strcmp(node_entry->d_name, ".."))
		{
			path = ft_strjoin(path, "/");
			path = ft_strjoin(path, node_entry->d_name);
			struct node *node = create_node(path, node_entry);
			if (node)
				add_list(ret->childs, create_list(node));
			printf("\n%s:\n", path);
		}
		else
			printf("%s ", node_entry->d_name);
	}
	closedir(dir);
	return (ret);
}