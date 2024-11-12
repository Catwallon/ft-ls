#include "ft_ls.h"

void exit_error(char *error)
{
	if (!error)
		error = strerror(errno);
	fprintf(stderr, "ls: %s\n", error);
	exit(EXIT_FAILURE);
}

struct ls parse_command(int ac, char **av)
{
	struct ls ret;
	ret.options = 0;
	ret.files = malloc(1000 * sizeof(char *)); //TODO -> Replace by custom malloc allocation
	int k = 0;
	for (int i = 0; i < ac; i++)
	{
		if (av[i][0] == '-')
		{
			if (!av[i][1])
				ret.files[k++] = av[i];
			for (int j = 0; av[i][j]; j++)
			{
				if (av[i][j] == 'l')
					ret.options |= LIST;
				else if (av[i][j] == 'R')
					ret.options |= RECURSIVE;
				else if (av[i][j] == 'a')
					ret.options |= SHOW_HIDDEN;
				else if (av[i][j] == 't')
					ret.options |= SORT_TIME;
				else if (av[i][j] == 'r')
					ret.options |= REVERSE;
				else
					exit_error("invalid option"); //TODO -> Add " -- 'x'", where x is the unknown option
			}
		}
		else
			ret.files[k++] = av[i];
	}
	return (ret);
}

int main(int ac, char **av)
{
	struct ls ls = parse_command(ac, av);
	if (ls.files[0])
	{
		// TODO -> Case files passed in args
	}
	else
	{
		// TODO -> Case no files passed in args
	}
	// create_node(".", NULL);
	return (EXIT_SUCCESS);
}