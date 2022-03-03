/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:38 by avaures           #+#    #+#             */
/*   Updated: 2022/03/03 10:47:52 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	rotate_tab(s_data *a)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = a->len -1;
	if (a->len >= 1)
	{
		tmp = a->tab[i];
		while (i >= 0)
		{
			tmp2 = tmp;
			tmp = a->tab[i - 1];
			a->tab[i - 1] = tmp2;
			i--;
		}
		a->tab[0] = tmp;
		return (0);
	}
	return (1);
}

int	rotate_ra(s_data *a, s_data *b)
{
	(void) b;
	return (rotate_tab(a));
}

int	rotate_rb(s_data *a, s_data *b)
{
	(void) a;
	return (rotate_tab(b));
}

int	rotate_rr(s_data *a, s_data *b)
{
	rotate_tab(a);
	rotate_tab(b);
	return (0);
}
