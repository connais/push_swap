/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:01:18 by avaures           #+#    #+#             */
/*   Updated: 2022/03/02 17:40:53 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	valid_arg(char *str)
{
	int	i;
	
	i = 0;
	if (!str[i])
		return (1);
	if (str[i] == '+' || str[i] == '-')
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
	int	*stack;

	i = 1;
	stack = malloc(sizeof(int) * (nb_arg - 1));
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
int main(int argc, char **argv)
{
	int	*tab = get_tab(argv, argc); 
	return (0);
}
