/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:19:42 by avaures           #+#    #+#             */
/*   Updated: 2022/03/08 10:55:46 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int	reverse_rotate_tab(s_data *stack)
{
	int	i;
	int	tmp;
	int	tmp2;
	i = 0;
	if (stack->len >= 1)
	{
		tmp = stack->tab[i];
		while (i < stack->len -1)
		{
			tmp2 = tmp;
			tmp = stack->tab[i + 1];
			stack->tab[i + 1] = tmp2;
			i++;
		}
		stack->tab[0] = tmp;
		return (0);
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
/*
int main()
{
	s_data a;
	s_data b;

	int i = 0;
	a.tab = malloc(sizeof(int) * 4);
	a.len = 4;
	while (i < 4)
	{
		a.tab[i] = i + 1;
		printf("%d\n", a.tab[i]);
		i++;
	}

	i = 0;
	reverse_rra(&a, &b);
	while (i < 4)
	{
		printf("%d\n", a.tab[i]);
		i++;
	}
}
*/
