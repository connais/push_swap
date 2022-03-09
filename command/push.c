/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:55:26 by avaures           #+#    #+#             */
/*   Updated: 2022/03/07 19:58:58 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_top(s_data *a, s_data *b)
{
	int	i;
	int	len;
	int	tmp;
	int	tmp2;
	
	i = 0;
	len = a->len;
	if (!b->len)
		return (1);
	tmp = a->tab[0];
	while(i < len - 1)
	{
		tmp2 = tmp;
		tmp = a->tab[i + 1];
		a->tab[i + 1] = tmp2; 
		i++;
	}
	a->tab[0] = b->tab[0];
	return (0);
}

int moove_top(s_data *b)
{
	int	i;
	int	tmp;
	int	tmp2;
	
	i = b->len - 1;
	if (!b->len)
		return (1);
	tmp = b->tab[i];
	while(i > 0)
	{
		tmp2 = tmp;
		tmp = b->tab[i - 1];
		b->tab[i - 1] = tmp2; 
		i--;
	}
	b->len--;
	return (0);
}

int push_a(s_data *a, s_data *b)
{
	push_top(a, b);
	moove_top(b);
	return (0);
}

int push_b(s_data *a, s_data *b)
{
	push_top(b, a);
	moove_top(a);
	return (0);
}
/*
int main()
{
	s_data a;
	s_data b;

	int i = 0;
	a.tab = malloc(sizeof(int) * 4);
	b.tab = malloc(sizeof(int) * 4);
	a.len = 4;
	b.len = 4;
	while (i < 4)
	{
		a.tab[i] = i + 1;
		b.tab[i] = i + 2;
		printf("a[%d] : %d\n", i, a.tab[i]);
		printf("b[%d] : %d\n", i, b.tab[i]);
		i++;
	}
	b.tab[0] = 10;

	i = 0;
	push_a(&a, &b);
	while (i < 4)
	{
		printf("%d\n", a.tab[i]);
		i++;
	}
}*/
