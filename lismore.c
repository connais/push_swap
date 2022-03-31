/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lismore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:06:50 by avaures           #+#    #+#             */
/*   Updated: 2022/03/31 15:37:01 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_data a)
{
	int	i;
	int	min;

	i = 1;
	min = a.tab[0];
	while (i < a.len)
	{
		if (a.tab[i] < min)
			min = a.tab[i];
		i++;
	}
	return (min);
}

int	maxi(t_data a)
{
	int	i;
	int	max;

	i = 1;
	max = a.tab[0];
	while (i < a.len)
	{
		if (a.tab[i] > max)
			max = a.tab[i];
		i++;
	}
	return (max);
}

void	final_move(t_data *a)
{
	int		place;
	t_data	b;

	place = indice_min(*a);
	if (place > 0)
	{
		while (place > 0)
		{
			rotate_ra(a, &b);
			place--;
		}
	}
	else
	{
		while (place < 0)
		{
			reverse_rra(a, &b);
			place++;
		}
	}
}

void	make_b(t_data *a, t_data *b)
{
	t_coords	var;

	var.i = -1;
	var.x = 0;
	while (a->len > a->len_sub)
	{
		while (++var.i < a->len_sub)
		{
			if (a->tab[0] == a->sub[var.i])
				var.x++;
		}
		if (var.x == 0)
			push_b(a, b);
		else
			rotate_ra(a, b);
		var.x = 0;
		var.i = -1;
	}
	free(a->sub);
}

int	**set_tab_sort(int **tabl, t_data *b)
{
	int	i;

	i = -1;
	tabl = malloc(sizeof(int *) * (b->len));
	if (!tabl)
		return (NULL);
	while (++i < b->len)
		tabl[i] = malloc(sizeof(int) * 2);
	if (!tabl)
		return (NULL);
	return (tabl);
}
