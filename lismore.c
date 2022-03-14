/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lismore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:06:50 by avaures           #+#    #+#             */
/*   Updated: 2022/03/14 15:29:48 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int found_position(s_data *a)
{
	int	i;
	int	position;
	int	smallest;

	i = 0;
	position = 0;
	smallest = a->tab[i];
	while (++i < a->len)
		if(smallest > a->tab[i])
		{
			smallest = a->tab[i];
			position = i;
		}
	return (position);
}
int found_smallest(s_data *a)
{
	int	position;
	int	smallest;

	position = 0;
	smallest = a->tab[position];
	while (++position < a->len)
		if(smallest > a->tab[position])
			smallest = a->tab[position];
	return (smallest);
}
int	max(int *array, int len)
{
	int	max;
	int	i;
	int	found;

	found = 0;
	i = 0;
	max = array[i];
	while (i < len)
	{
		if (array[i] > max)
		{
			max = array[i];
			found = i;
			printf("i : %d", i);
		}
		i++;
	}
	return (found);
}
