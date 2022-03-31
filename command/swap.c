/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:05:36 by avaures           #+#    #+#             */
/*   Updated: 2022/03/31 15:35:37 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

int	swap_tab(t_data *stack)
{
	int	tmp;

	if (stack->len <= 1)
		return (0);
	tmp = stack->tab[1];
	stack->tab[1] = stack->tab[0];
	stack->tab[0] = tmp;
	return (0);
}

int	swap_sa(t_data *a, t_data *b)
{
	(void) b;
	ft_printf("sa\n");
	return (swap_tab(a));
}

int	swap_sb(t_data *a, t_data *b)
{
	(void) a;
	ft_printf("sb\n");
	return (swap_tab(b));
}

int	swap_ss(t_data *a, t_data *b)
{
	swap_tab(a);
	swap_tab(b);
	ft_printf("sb\n");
	return (0);
}
/*
int main()
{
	s_data a;
	s_data b;
	int i = 0;

	//a = malloc(sizeof(s_data));
	//b = malloc(sizeof(s_data));
	a.len = 3;
	a.tab = malloc(sizeof(int) * a.len);
	a.tab[0] = 1;
	a.tab[1] = 2;
	a.tab[2] = 3;
	while(i < a.len)
	{
		printf("%d \n", a.tab[i]);
		i++;
	}
	swap_sa(&a, &b);
	i = 0;
	while(i < a.len)
	{
		printf("%d \n", a.tab[i]);
		i++;
	}
	return (0);
}*/
