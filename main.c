/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <avaures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:25:27 by avaures           #+#    #+#             */
/*   Updated: 2022/04/04 15:50:06 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_push_swap(t_data *a, t_data *b)
{
	int	len;
	int	i;

	len = a->len;
	if (is_little_tab(a, b) == 1)
		return (1);
	get_lis(a);
	if (!a->lis || !a->sub)
		return (1);
	b->len = a->len - a->len_sub;
	b->tab = malloc(sizeof(int) * b->len);
	if (!b->tab)
		return (1);
	make_b(a, b);
	big_sort(a, b);
	a->len = len;
	final_move(a);
	free(a->tab);
	return (0);
}

int	check_last(t_data *a)
{
	if (!a->tab)
		return (1);
	if (check_if_sort(*a) == 0)
	{
		free(a->tab);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	a;
	t_data	b;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (set_two(&a, argv) == 1)
		{
			free(a.tab);
			return (0);
		}
	}
	if (argc > 2)
	{
		if (set_more(&a, argc, argv) == 1)
		{
			free(a.tab);
			return (0);
		}
	}
	if (check_last(&a) == 1)
		return (0);
	if (make_push_swap(&a, &b) == 1)
		return (0);
}

void	big_sort(t_data *a, t_data *b)
{
	int	*found;
	int	**tabl;
	int	len;

	tabl = tab_sort(tabl, b);
	found = malloc(sizeof(int) * 2);
	if (!tabl || !found)
		return ;
	len = b->len - 1;
	while (b->len > 0)
	{
		determine_coords_b(*b, tabl);
		determine_coords_a(*a, *b, tabl);
		found_best(found, tabl, *b);
		sort_tab(tabl, found, *a, *b);
		a->len++;
		b->len--;
	}
	found_best(found, tabl, *b);
	free(found);
	while (len >= 0)
		free(tabl[len--]);
	free(tabl);
	free(b->tab);
}

void	get_lis(t_data *a)
{
	test_lis(a);
	find_lis_max(a);
	get_sub_sequence(a);
}
