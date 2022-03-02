/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:42 by avaures           #+#    #+#             */
/*   Updated: 2022/03/02 17:32:15 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_tab(s_data *stack)
{
	int	i;
	int	tmp;
	int	tmp2;
	i = 0;
	if (stack->len >= 1)
	{
		tmp = stack->tab[0];
		while (i < tab->len -1)
		{
			tmp2 = tmp;
			tmp = stack->tab[i + 1];
			stack->tab[i + 1] = tmp2;
			i++;
		}
		tab->tab[0] = tmp;
		retun (0);
	}
	return (1);
}

int	reverse_rra(s_data *a, s_data *b)
{
	(void) b;
	return (reverse_rotate_tab(a));
}

int	reverse_rrb(s_data *a, s_data *b)
{
	(void) a;
	return (reverse_rotate_tab(b));
}

int	reverse_rrr(s_data *a, s_data *b)
{
	return (reverse_rotate_tab(a));
	return (reverse_rotate_tab(b));
	return (0);
}
