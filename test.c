/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:27:32 by avaures           #+#    #+#             */
/*   Updated: 2022/03/31 21:17:40 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in_b(t_data *a, t_data *b, int pos)
{
	if (pos < 0)
	{
		while (pos < 0)
		{
			reverse_rra(a, b);
			pos++;
		}
		push_b(a, b);
	}
	else if (pos > 0)
	{
		while (pos > 0)
		{
			rotate_ra(a, b);
			pos--;
		}
		push_b(a, b);
	}
	else
		push_b(a, b);
}

int	sort_tab_3(t_data *a, t_data *b)
{
	int	tmp;

	if (a->tab[0] > a->tab[1])
	{
		swap_sa(a, b);
	}
	if (a->tab[1] > a->tab[2])
	{
		reverse_rra(a, b);
	}
	if (a->tab[0] > a->tab[1])
	{
		swap_sa(a, b);
	}
	return (0);
}

void	sort_tab_5(t_data *a, t_data *b)
{
	int	j;
	int	count;

	if (check_if_sort(*a) == 0)
		return ;
	count = 2;
	b->tab = malloc(sizeof(int) * 2);
	b->len = 2;
	j = 0;
	while (count > 0)
	{	j = indice_min(*a);
//		ft_printf("j : %d\n", j);
		push_in_b(a, b, j);
		count--;
	}
	sort_tab_3(a, b);
	a->len++;
	push_a(a, b);
	a->len++;
	push_a(a, b);
	free(b->tab);
//	j = 0;
//	while ( j < a->len)
//	{
//		ft_printf("a->tab[%d] : %d\n", j, a->tab[j]);
//		j++;
//	}
	final_move(a);
}

int	sort_tab_2(t_data *a, t_data *b)
{
	if (a->tab[0] > a->tab[1])
	{
		swap_sa(a, b);
	}
}

int	is_little_tab(t_data *a, t_data *b)
{
	if (a->len == 2)
	{
		sort_tab_2(a, b);
		free(a->tab);
		return (1);
	}
	if (a->len == 3)
	{
		sort_tab_3(a, b);
		free(a->tab);
		return (1);
	}
	if (a->len == 5)
	{
		sort_tab_5(a, b);
		free(a->tab);
		return (1);
	}
}
/*
int main(int argc, char **argv)
{
	s_data *a;
	s_data *b;
	int	i;
	char **arg_long;
	if (argc == 2)
	{
		arg_long = ft_split(argv[1], ' ');
		if (!arg_long)
			return (ft_printf("error of arguments\n"), 0);
		a->len = count_words(argv[1], ' ');
		ft_printf("taille arg : %d\n", a->len);
		a->tab = get_tab_long(arg_long, a->len);
		if (!a->tab)
			return (ft_printf("error of arguments2\n"), 0);
		i = 0;
		printf("premier elemtab ->%d\n", a->tab[0]);
		while (i < 3)
			printf("%d\n", a->tab[i++]);
		sort_tab_3(a, b);
		i = 0;
		while (i < 3)
			printf("%d\n", a->tab[i++]);
	}
	printf("enter !! \n");
	if (argc > 2)
	{
		i = 0;
		a->tab = get_tab(argv, argc - 1);
		if (!a->tab || a->tab == NULL)
			return (ft_printf("error of arguments3\n"), 0);
		printf("premier elemtab ->%d\n", a->tab[0]);
		while (i < 3)
			printf("%d\n", a->tab[i++]);
		sort_tab_3(a, b);
		i = 0;
		while (i < 3)
			printf("%d\n", a->tab[i++]);
	}
	return (0);
}
*/
