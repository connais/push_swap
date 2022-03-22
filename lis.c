/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42->fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by avaures           #+#    #+#             */
/*   Updated: 2022/03/22 15:01:55 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	look_for_smallest_num(s_data a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = a.tab[0];
	j = 0;
	
	while (i < a.len)
	{
		if (tmp > a.tab[i])
		{
			tmp = a.tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	find_lis_max(s_data *a)
{
	int	i;

	i = 0;
	a->len_sub = 0;
	while (i < a->len)
	{
		if (a->len_sub < a->lis[i])
		{
			a->len_sub = a->lis[i];
			a->max_pos = i;
		}
		i++;
	}
}

void	place_it_on_top(s_data *a, int min_pos)
{
	s_data b;

	if (min_pos > a->len / 2)
	{
		while (min_pos < a->len)
		{
			reverse_rra(a, &b);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			rotate_ra(a, &b);
			min_pos--;
		}
	}
}

void	get_sub_sequence(s_data *a)
{
	int	i;
	int	j;
	int	k;

	i = a->max_pos;
	k = a->len_sub;
	j = i - 1;
	a->sub = malloc(sizeof(int) * k);
	if (!a->sub)
		return;
	k--;
	a->sub[k] = a->tab[i];
	while (j >= 0)
	{
		if (a->lis[i] - a->lis[j] == 1)
		{
			k--;
			a->sub[k] = a->tab[j];
			i = j;
		}
		j--;
	}
	free(a->lis);
	return ;
}

void	test_lis(s_data *a)
{
	int	i;
	int	j;

	j = 0;
	a->lis = malloc(sizeof(int) * a->len);

	if (!a->lis)
		return ;
	i = -1;
	while (++i < a->len)
		a->lis[i] = 1;
	i = 1;
	while (i < a->len)
	{
		while (j < i)
		{
			if (a->tab[i] > a->tab[j] && a->lis[i] < a->lis[j] + 1)
				a->lis[i] = a->lis[j] + 1;
			j++;
		}
		j = 0;
		i++;
	}
	return;
}
void	get_lis(s_data *a)
{
	test_lis(a);
	find_lis_max(a);
	get_sub_sequence(a);
}
/*
int main()
{
	s_data a;
	s_data b;
	int i = 0;
	int *tab = malloc(sizeof(int) * 5);
	int *lis;

	if (!tab)
		return (0);
	tab[0] = 6;
	tab[1] = 4;
	tab[2] = 1;
	tab[3] = 2;
	tab[4] = 42;
	a->len = 5;
	a->tab = tab;
	printf("helo\n");
	lis = get_lis(a);
	if (!a->tab || !lis)
		return (1);
	int lis_len = lis[0] + 1;
	printf("lenlis : %d\n", lis_len);
	i = 0;
	while (i < a->len)
	{
		printf("a[%d] : %d\n", i, a->tab[i]);
		i++;
	}
	i = 1;
	while (i < lis_len)
	{
		printf("lis[%d] : %d\n", i, lis[i]);
		i++;
	}
	return (0);
}*/
