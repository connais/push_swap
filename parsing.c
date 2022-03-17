/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:01:18 by avaures           #+#    #+#             */
/*   Updated: 2022/03/17 18:51:12 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	valid_arg(char *str)
{
	int	i;
	
	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && '9' >= str[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int check_overflow(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		return (1);
	if (ft_strlen(str) == 11)
	{
		if (str[0] != '-')
			return (1);
		if (ft_strncmp(&str[1], "2147483648", 10) != 0)
			return (1);
	}
	if (ft_strlen(str) == 10)
		if (ft_strncmp(str, "2147483647", 10) > 0)
			return (1);
	return (0);
}

int	check_double(int *tab, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	*get_tab(char **arg, int nb_arg)
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	j = 1;
	stack = malloc(sizeof(int) * (nb_arg));
	if (!stack)
		return (0);
	while (i < nb_arg)
	{
		if (valid_arg(arg[j]) == 1 || check_overflow(arg[j]) == 1\
		|| check_double(stack, i, ft_atoi(arg[j])))
		{
			free(stack);
			ft_printf("invalid arguments\n");
			return (NULL);
		}
		stack[i] = ft_atoi(arg[j]);
		i++;
		j++;
	}
	return (stack);
}

int	*get_tab_long(char **arg, int nb_arg)
{
	int	i;
	int	j;
	int	*stack;

	i = 0;
	stack = malloc(sizeof(int) * (nb_arg));
	if (!stack)
		return (0);
	while (i < nb_arg)
	{
		if (valid_arg(arg[i]) == 1 || check_overflow(arg[i]) == 1\
		|| check_double(stack, i, ft_atoi(arg[i])))
		{
			free(stack);
			ft_printf("invalid arguments\n");
			return (NULL);
		}
		stack[i] = ft_atoi(arg[i]);
		i++;
	}
	return (stack);
}
/*
int main(int argc, char **argv)
{

	int	*tab;

	if (argc == 1)
		return (ft_printf("invalid number of argument\n"));
	if (argc == 2)
		tab = get_tab_long(argv, argc);
	else
		tab = get_tab(argv, argc);
	if (!tab)
		return (1);
	return (0);
}
*/
