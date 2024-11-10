#include "ft_ls.h"

size_t ft_strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
	return (i);
}

int ft_strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char *ft_strcat(char *dest, const char *src)
{
	size_t i = 0;
	size_t j = 0;
	
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char *ft_strjoin(const char *str1, const char *str2)
{
	char *ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!ret)
		return (NULL);
	ft_strcat(ret, str1);
	ft_strcat(ret, str2);
	return (ret);
}

void ft_putstr(const char *str)
{
	size_t len = ft_strlen(str);
	write(1, str, len);
}