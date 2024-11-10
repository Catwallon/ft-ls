#include "ft_ls.h"

int main()
{
	DIR *dir = opendir(".");
	if (!dir)
		return (EXIT_FAILURE);
	readdir(dir);
	readdir(dir);
	create_node(".", readdir(dir));
	closedir(dir);
	return (EXIT_SUCCESS);
}