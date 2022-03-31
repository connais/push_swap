/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:06:38 by avaures           #+#    #+#             */
/*   Updated: 2022/03/31 15:33:46 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	rotate_tab(t_data *a)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = a->len -1;
	if (a->len >= 1)
	{
		tmp = a->tab[i];
		while (i > 0)
		{
			tmp2 = tmp;
			tmp = a->tab[i - 1];
			a->tab[i - 1] = tmp2;
			i--;
		}
		a->tab[a->len - 1] = tmp;
		return (0);
	}
	return (1);
}

int	rotate_ra(t_data *a, t_data *b)
{
	(void) b;
	ft_printf("ra\n");
	return (rotate_tab(a));
}

int	rotate_rb(t_data *a, t_data *b)
{
	(void) a;
	ft_printf("rb\n");
	return (rotate_tab(b));
}

int	rotate_rr(t_data *a, t_data *b)
{
	rotate_tab(a);
	rotate_tab(b);
	ft_printf("rr\n");
	return (0);
}
/*
int main()
{
	t_data a;
	t_data b;

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
	rotate_ra(&a, &b);
	while (i < 4)
	{
		printf("%d\n", a.tab[i]);
		i++;
	}
}*/
