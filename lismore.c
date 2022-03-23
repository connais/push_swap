/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lismore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:06:50 by avaures           #+#    #+#             */
/*   Updated: 2022/03/23 18:39:12 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int min(s_data a)
{
	int i = 1;
	int min = a.tab[0];

	while (i < a.len)
	{
		if (a.tab[i] < min)
			min = a.tab[i];
		i++;
	}
	return (min);
}

int maxi(s_data a)
{
	int i = 1;
	int max = a.tab[0];

	while (i < a.len)
	{
		if (a.tab[i] > max)
			max = a.tab[i];
		i++;
	}
	return (max);
}

void	final_move(s_data *a)
{
	int	place;
	s_data	b;

	place = indice_min(*a);
	if (place > 0)
		while (place > 0)
		{
			rotate_ra(a, &b);
			place--;
		}
	else
		while (place < 0)
		{
			reverse_rra(a, &b);
			place++;
		}
}

void	make_b(s_data *a, s_data *b)
{
	int vu;
	int indice;
	int	j;

	j = 0;
	vu = 0;
	indice = 0;
	while(a->len > a->len_sub)
	{
		while (j < a->len_sub)
		{
			if (a->tab[0] == a->sub[j])
			{
				vu++;
			}
			j++;
		}
		if (vu == 0)
		{
			push_b(a, b);
			ft_printf("pb\n");
		}
		else
		{
			rotate_ra(a, b);
			ft_printf("ra\n");
		}
		vu = 0;
		j = 0;
	}
	free(a->sub);
}

void	big_sort(s_data *a, s_data *b)
{
	int i;
	int *found;
	int **tabl;
	int	len;

	len = b->len - 1;
	i = 0;
	tabl = malloc(sizeof(int *) * (b->len));
	while(i < b->len) 
	{
  	  	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	found = malloc(sizeof(int) * 2);
	if (!tabl || !found)
		return;
	while (b->len > 0)
	{
		determine_coords_b(*b, tabl);
		determine_coords_a(*a, *b, tabl);
		found_best(found, tabl, *b);
		sort_tab(tabl, found, *a, *b);
		a->len++;
		b->len--;
		i++;
	}
	found_best(found, tabl, *b);
	free(found);
	while(len >= 0) 
  	  	free(tabl[len--]);
	free(tabl);
	free(b->tab);
}
