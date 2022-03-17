/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:00:15 by avaures           #+#    #+#             */
/*   Updated: 2022/03/17 11:50:23 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sort_tab(int **tabl, int *found, s_data a, s_data b)
{
	int		i;
	static int	cpt = 0;
	int	x;
	int	y;

	y = tabl[found[0]][1];
	x = tabl[found[0]][0];
	i = 0;
	while (found[1] > 0)
	{
		if (y > 0)
			while (y > 0)
			{
				rotate_rb(&a, &b);
				ft_printf("rb\n");
				cpt++;
				y--;
				found[1]--;
			}
		else
			while (y < 0)
			{
				reverse_rrb(&a, &b);
				ft_printf("rrb\n");
				cpt++;
				y++;
				found[1]--;
			}
		if (x > 0)
			while (x > 0)
			{
				rotate_ra(&a, &b);
				ft_printf("ra\n");
				cpt++;
				x--;
				found[1]--;
			}
		else
			while (x < 0)
			{
				reverse_rra(&a, &b);
				ft_printf("rra\n");
				cpt++;
				x++;
				found[1]--;
			}		
	}
/*
	i = 0;
	while (i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	i = 0;
	while (i < b.len)
	{
		printf("b.tab[i] : %d\n", b.tab[i]);
		i++;
	}
	
*/	a.len++;
	push_a(&a, &b);
	if (a.tab[0] > a.tab[1])
	{
		swap_sa(&a, &b);
		ft_printf("sa\n");
		cpt++;
	}
//	b.len--;
//	printf("len_b : %d\n", b.len);
	return(cpt);
}
