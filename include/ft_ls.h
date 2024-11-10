#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

// node.c
struct node
{
	char *path;
	struct dirent *entry;
	struct list *childs;
};
struct node *create_node(char *path, struct dirent *entry);

// list.c
struct list
{
	struct node *node;
	struct list *next;
};
struct list *create_list(struct node *node);
void add_list(struct list *begin_list, struct list *list);

// utils.c
size_t ft_strlen(const char *str);
int ft_strcmp(const char *str1, const char *str2);
char *ft_strcat(char *dest, const char *src);
char *ft_strjoin(const char *str1, const char *str2);
void ft_putstr(const char *str);

