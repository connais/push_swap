/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:33:39 by avaures           #+#    #+#             */
/*   Updated: 2022/03/18 17:22:32 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
#define COMMAND_H

#include "../push_swap.h"

typedef struct	t_data                                                           
{                                                                               
	int	*tab;                        
	int	len;
	int	*lis;
	int	*sub;
	int	max_pos;
	int	len_sub;
}               s_data;

int		push_a(s_data *a, s_data *b);
int		push_b(s_data *a, s_data *b);
int 		swap_sa(s_data *a, s_data *b);
int 		swap_sb(s_data *a, s_data *b);
int 		swap_ss(s_data *a, s_data *b);
int		rotate_ra(s_data *a, s_data *b);
int		rotate_rb(s_data *a, s_data *b);
int		rotate_rr(s_data *a, s_data *b);
int		reverse_rra(s_data *a, s_data *b);
int		reverse_rrb(s_data *a, s_data *b);
int		reverse_rrr(s_data *a, s_data *b);
int	moove_top(s_data *b);
int	rotate_tab(s_data *a);
int	swap_tab(s_data *stack);
int	push_top(s_data *a, s_data *b);
int	reverse_rotate_tab(s_data *stack);

#endif
