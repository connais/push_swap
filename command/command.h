/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:33:39 by avaures           #+#    #+#             */
/*   Updated: 2022/03/24 15:31:19 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "../push_swap.h"

typedef struct s_data
{
	int	*tab;
	int	len;
	int	*lis;
	int	*sub;
	int	max_pos;
	int	len_sub;
}		t_data;

int		push_a(t_data *a, t_data *b);
int		push_b(t_data *a, t_data *b);
int		swap_sa(t_data *a, t_data *b);
int		swap_sb(t_data *a, t_data *b);
int		swap_ss(t_data *a, t_data *b);
int		rotate_ra(t_data *a, t_data *b);
int		rotate_rb(t_data *a, t_data *b);
int		rotate_rr(t_data *a, t_data *b);
int		reverse_rra(t_data *a, t_data *b);
int		reverse_rrb(t_data *a, t_data *b);
int		reverse_rrr(t_data *a, t_data *b);
int		moove_top(t_data *b);
int		rotate_tab(t_data *a);
int		swap_tab(t_data *stack);
int		push_top(t_data *a, t_data *b);
int		reverse_rotate_tab(t_data *stack);

#endif
