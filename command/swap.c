/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:05:36 by avaures           #+#    #+#             */
/*   Updated: 2022/03/03 10:47:59 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 
int	swap_tab(s_data *stack)
{
	int	tmp;

	tmp = stack->tab[1];
	stack->tab[1] = stack->tab[0];
	stack->tab[0] = tmp;
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
