#include "ft_ls.h"

int main()
{
	struct dirent *entry;
	DIR *dir = opendir(".");
	if (!dir)
		return (EXIT_FAILURE);
	while ((entry = readdir(dir)))
		printf("%s ", entry->d_name);
	closedir(dir);
	return (EXIT_SUCCESS);
}