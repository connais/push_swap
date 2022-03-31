/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:00:15 by avaures           #+#    #+#             */
/*   Updated: 2022/03/31 15:38:14 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	set_more(t_data *a, int argc, char **argv)
{
	a->len = argc - 1;
	a->tab = malloc(sizeof(int) * a->len);
	a->tab = get_tab(argv, argc - 1);
	if (!a->tab)
		return (1);
	return (0);
}

int	set_two(t_data *a, char **argv)
{
	char	**arg_long;
	int		i;

	i = 0;
	arg_long = ft_split(argv[1], ' ');
	if (!arg_long)
		return (1);
	a->len = count_words(argv[1], ' ');
	a->tab = get_tab_long(arg_long, a->len);
	if (!a->tab)
	{
		while (i < a->len)
			free(arg_long[i++]);
		free(arg_long);
		return (1);
	}
	return (0);
}
/*
int	opti_sort_tab(int **tabl, int *found, s_data a, s_data b)
{
	if ( x < 0 && y < 0)
		while (y < 0 && x < 0)
		{
			reverse_rrr(&a, &b);
			ft_printf("rrr\n");
			cpt++;
			y++;
			x++;
			found[1] -= 2;
		}
	if ( x > 0 && y > 0)
		while (y > 0 && x > 0)
		{
			rotate_rr(&a, &b);
			ft_printf("rr\n");
			cpt++;
			y--;
			x--;
			found[1] -= 2;
		}
}
*/

int	sort_tab_x(int **tabl, int *found, t_data a, t_data b)
{
	int	x;

	x = tabl[found[0]][0];
	while (x > 0)
	{
		rotate_ra(&a, &b);
		x--;
		found[1]--;
	}
	while (x < 0)
	{
		reverse_rra(&a, &b);
		x++;
		found[1]--;
	}
}

int	sort_tab(int **tabl, int *found, t_data a, t_data b)
{
	int	y;

	y = tabl[found[0]][1];
	while (y > 0)
	{
		rotate_rb(&a, &b);
		y--;
		found[1]--;
	}
	while (y < 0)
	{
		reverse_rrb(&a, &b);
		y++;
		found[1]--;
	}
	sort_tab_x(tabl, found, a, b);
	a.len++;
	push_a(&a, &b);
	return (0);
}
