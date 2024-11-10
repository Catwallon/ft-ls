#include "ft_ls.h"

int main()
{
	DIR *dir = opendir(".");
	struct dirent *entry;
	if (!dir)
		return (EXIT_FAILURE);
	while ((entry = readdir(dir)))
		create_node(".", entry);
	closedir(dir);
	return (EXIT_SUCCESS);
}