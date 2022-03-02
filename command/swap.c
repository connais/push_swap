/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:05:36 by avaures           #+#    #+#             */
/*   Updated: 2022/02/28 13:55:06 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h" 
static int	*swap_tab(s_data *stack)
{
	int	tmp;
	int	size;

	size = stack->len;
	tmp = stack->tab[size - 1];
	stack->tab[size - 1] = stack->tab[size - 2];
	stack->tab[size - 2] = tmp;
	return (0);	

}

int swap_sa(s_data *a, s_data *b)
{
	(void) b;
	return (swap_tab(a));
}

int swap_sb(s_data *a, s_data *b)
{
	(void) a;
	return (swap_tab(b));
}
int swap_ss(s_data *a, s_data *b)
{
	swap_tab(a);
	swap_tab(b);
	return (0);
}
