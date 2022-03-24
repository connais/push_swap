/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_indice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:05:47 by avaures           #+#    #+#             */
/*   Updated: 2022/03/24 15:36:03 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indice_min(t_data a)
{
	int	i;
	int	min;
	int	indice;

	i = 0;
	min = a.tab[0];
	indice = 0;
	while (i < a.len)
	{
		if (a.tab[i] < min)
		{
			min = a.tab[i];
			indice = i;
		}
		i++;
	}
	if (indice > a.len / 2)
		indice = indice - a.len;
	return (indice);
}

int	indice_max(t_data a)
{
	int	i;
	int	max;
	int	indice;

	i = 0;
	max = a.tab[0];
	indice = 0;
	while (i < a.len)
	{
		if (a.tab[i] > max)
		{
			max = a.tab[i];
			indice = i;
		}
		i++;
	}
	if (indice > a.len / 2)
		indice = indice - a.len;
	return (indice);
}
