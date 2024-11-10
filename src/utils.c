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

void *ft_memset(void *ptr, int value, size_t size)
{
	size_t i;
	unsigned char *u_ptr;

	i = -1;
	u_ptr = (unsigned char *) ptr;
	while (++i < size)
		u_ptr[i] = (unsigned char) value;
	return (ptr);
}

void *ft_bzero(char *ptr, size_t size)
{
	return (ft_memset(ptr, 0, size));
}

void *ft_calloc(int nb, size_t size)
{
	char *output;

	output = (char *) malloc(nb * size);
	if (!output)
		return (NULL);
	ft_bzero(output, nb * size);
	return ((void *) output);
}

char *ft_strjoin(const char *str1, const char *str2)
{
	char *ret = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, ft_strlen(str1) + ft_strlen(str2) + 1);
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