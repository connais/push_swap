/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:43:23 by avaures           #+#    #+#             */
/*   Updated: 2022/03/22 17:26:39 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int indice_min(s_data a)
{
	int i = 0;
	int min = a.tab[0];
	int indice = 0;

	while (i < a.len)
	{
		if (a.tab[i] < min)
		{
			min = a.tab[i];
			indice = i;
		}
		i++;
	}
	if (indice > a.len/2)
		indice = indice -a.len;
	return (indice);
}

int indice_max(s_data a)
{
	int i = 0;
	int max = a.tab[0];
	int indice = 0;

	while (i < a.len)
	{
		if (a.tab[i] > max)
		{
			max = a.tab[i];
			indice = i;
		}
		i++;
	}

	if (indice > a.len/2)
		indice = indice -a.len;
	return (indice);
}
int	get_perfect_pos(int top, s_data a)
{
	int	i;

	i = a.len - 1;
	while (i > 0)
	{
		if (top < a.tab[i] && top > a.tab[i - 1])
		{
			if (i <= a.len/2)
				return (i);
			else
				return (i - a.len);
		}
		i--;
	}
	return (0);
}
int	*tabl_diff(int place, s_data a)
{
	int	i;
	int	*tab_diff;
	i = -1;
	tab_diff = malloc(sizeof(int) * a.len);
	while (++i < a.len)
	{
		tab_diff[i] = place - a.tab[i];
		if (tab_diff[i] < 0)
			tab_diff[i] *= -1;
	}
	return (tab_diff);
}

int	determine_place(int place, s_data a)
{
	int	i;
	int	*tab_diff;
	int	diff;
	int indice;

	i = -1;
	tab_diff = tabl_diff(place, a);
	if (!tab_diff)
		return (1);
	diff = tab_diff[0];
	indice = 0;
	while (++i <= a.len)
	{
		if (diff > tab_diff[i])
		{
			diff = tab_diff[i];
			indice = i;
		}
	}
		indice++;
	free(tab_diff);
	return (indice);
}
void determine_coords_a(s_data a, s_data b, int **coords)
{
	int	i;

	i = 0;
	while (i < b.len)
	{
		if (b.tab[i] < min(a) || b.tab[i] > maxi(a))
			coords[i][0] = indice_min(a);
		else
			coords[i][0] = get_perfect_pos(b.tab[i], a);
		i++;
	}
	return ;
}

void determine_coords_b(s_data b, int **coords)
{
	int	i;

	i = 0;
//	printf("ok\n");
	while (i <= b.len/2)
	{
		coords[i][1] = i;
		i++;
	}
	i = b.len - 1;
	while (i > b.len/2)
	{
		coords[i][1] = i - b.len;
		i--;
	}
	return ;
}
/*
int main()
{
	s_data a;
	s_data b;
	int ** tabl = malloc(sizeof(int) * 10);
	int i = 0;
	while(i < 10) 
	{	
    	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	a.tab = malloc(sizeof(int) * 10);
	b.tab = malloc(sizeof(int) * 4);
	a.tab[0] = 3;
	a.tab[1] = 8;
	a.tab[2] = 9;
	a.tab[3] = 0;
	a.tab[4] = 1;
	a.tab[5] = 2;
	b.tab[0] = 10;
	b.tab[1] = 6;
	b.tab[2] = 4;
	b.tab[3] = 7;
	a.len = 10;
	b.len = 4;
	determine_coords_b(b, tabl);
	determine_coords_a(a, b, tabl);
	i = 0;
	while (i < b.len)
	{
		printf("pour %d : %d, %d\n", b.tab[i],tabl[i][0], tabl[i][1]);
		i++;
	}
}
*/
