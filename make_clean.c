/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:00:15 by avaures           #+#    #+#             */
/*   Updated: 2022/03/23 19:13:51 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	set_more(s_data *a, int argc, char **argv)
{
	a->len = argc - 1;
	a->tab = malloc(sizeof(int) * a->len);
	a->tab = get_tab(argv, argc - 1);
	if (!a->tab)
		return (1);
	return (0);
}

int	set_two(s_data *a, char **argv)
{
	char	**arg_long;
	int	i;

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
/*		if ( x < 0 && y < 0)
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
			}*/
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
	a.len++;
	push_a(&a, &b);
	ft_printf("pa\n");
	return(cpt + 1);
}
