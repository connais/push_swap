/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/23 19:26:34 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	set_found_best(int **shot, int x, int y, int better)
{
	x = shot[0][0];
	y = shot[0][1];
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	better = x + y;
}
void	found_best(int *found, int **shot, s_data b)
{
	int			i;
	int			better;
	int			save_i;
	static int	*cpy = NULL;
	int			x;
	int			y;

	i = 0;
	if (!cpy)
	{
		cpy = malloc(sizeof(int) * b.len);
		if (!cpy)
			return ;

	}
	if (b.len == 0)
	{
		free(cpy);
		return ;
	}
	while (i < b.len)
	{
		cpy[i] = 0;
		i++;
	}
	i = 0;
	save_i = 0;
	set_found_best(shot, x, y, better);
	while (i < b.len)
	{
		x = shot[i][0];
		y = shot[i][1];
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		if (better >= y + x && cpy[i] == 0)
		{
			better = y + x;
			save_i = i;
		}
		i++;
	}
	cpy[save_i] = 1;
	found[0] = save_i;
	found[1] = better;
	return ;
}

int	check_if_sort(s_data a)
{
	int	i;

	i = 0;
	while (i < a.len - 1)
	{
		if (a.tab[i + 1] < a.tab[i])
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	s_data	a;
	s_data	b;
	char	**arg_long;
	int	len;

	if (argc == 1)
		return (0);
	if (argc == 2)
		if (set_two(&a, argv) == 1)
		{
			free(a.tab);
			return (0);
		}
	if (argc > 2)
		if (set_more(&a, argc, argv) == 1)
		{
			free(a.tab);
			return (0);
		}
	if (!a.tab)
		return(0);
	if (check_if_sort(a) == 0)
	{
		free(a.tab);
		return(0);
	}
	len = a.len;
	place_it_on_top(&a,min(a));
	get_lis(&a);
	if (!a.lis || !a.sub)
		return (1);
	b.len = a.len - a.len_sub;
	b.tab = malloc(sizeof(int) * b.len);
	make_b(&a, &b);
	big_sort(&a, &b);
	a.len = len;
	final_move(&a);
	int	i = 0;
	while (i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	free(a.tab);
}
