/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/24 18:16:35 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_found_best(int **shot, t_coords *abs)
{
	abs->i = -1;
	abs->save_i = 0;
	abs->x = shot[0][0];
	abs->y = shot[0][1];
	if (abs->x < 0)
		abs->x *= -1;
	if (abs->y < 0)
		abs->y *= -1;
	abs->better = abs->x + abs->y;
}

void	set_w_found(int **shot, t_coords *abs, int *cpy)
{	
	abs->x = shot[abs->i][0];
	abs->y = shot[abs->i][1];
	if (abs->x < 0)
		abs->x *= -1;
	if (abs->y < 0)
		abs->y *= -1;
	if (abs->better >= abs->y + abs->x && cpy[abs->i] == 0)
	{
		abs->better = abs->y + abs->x;
		abs->save_i = abs->i;
	}
	abs->i++;
}

void	found_best(int *found, int **shot, t_data b)
{
	static int	*cpy = NULL;
	t_coords	abs;

	set_found_best(shot, &abs);
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
	while (++abs.i < b.len)
		cpy[abs.i] = 0;
	abs.i = 0;
	while (abs.i < b.len)
		set_w_found(shot, &abs, cpy);
	cpy[abs.save_i] = 1;
	found[0] = abs.save_i;
	found[1] = abs.better;
	return ;
}

int	check_if_sort(t_data a)
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
