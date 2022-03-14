/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by avaures           #+#    #+#             */
/*   Updated: 2022/03/14 16:14:00 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void	startsmall(s_data *a)
{
	s_data	*b;
	int	position;
	int	i;

	position = found_position(a);
	i = 0;
	if (position <= a->len/2)
		while (position > 0)
		{
			rotate_ra(a, b);
			position--;
		}
	else
		while (position < a->len)
		{
			reverse_rra(a, b);		
			position++;
		}
	return ;
}

int	lislen(s_data *a)
{
	int	*alllen;
	int	i;
	int	j;

	i = 0;
	j = 1;

	alllen = malloc(sizeof(int) * a->len);
	if (!alllen)
		return (1);
	alllen[0] = 1;
	while (j < a->len)
	{
		alllen[j] = 1;
		while (i <= j - 1)
		{
			if (a->tab[i] <= a->tab[j] && alllen[j] < alllen[i] + 1)
				alllen[j] = alllen[i] + 1;
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	while(i < a->len)
	{
		printf("alllen[%d] : %d\n", i, alllen[i]);
		i++;
	}
	
	return (max(alllen, a->len));
}

int	*lis(s_data *a)
{
	int	*alllen;
	int	*indice;
	int	i;
	int	j;

	i = 0;
	indice = malloc(sizeof(int) * a->len);
	alllen = malloc(sizeof(int) * a->len);
	if (!indice || !alllen)
		return (NULL);
	while (i < a->len)
	{
		indice[i] = -1;
		i++;
	}
	i = 0;
	j = 1;
	alllen[0] = 1;
	while (j < a->len)
	{
		alllen[j] = 1;
		while (i <= j - 1)
		{
			if (a->tab[i] < a->tab[j] && alllen[j] < alllen[i] + 1)
			{
				alllen[j] = alllen[i] + 1;
				indice[j] = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	while(i < a->len)
	{
		printf("indicev2v[%d] : %d\n", i, indice[i]);
		i++;
	}
	free(alllen);
	return (indice);
}

int	*determine_lis(s_data *a)
{
	int len = lislen(a);
	int	*lisfine;
	int	*indice = lis(a);
	int i = 0;

	lisfine = malloc(sizeof(int) * len);
	if (!lisfine)
		return (NULL);
	printf("len : %d\n", len);
	while (indice[len] != -1)
	{
		len = indice[len];
		lisfine[len] = a->tab[len];
		printf("lisfine[%d] : %d\n", len, lisfine[len]);
	}
	return (lisfine);
}

int	*make_b(s_data a, int	*lis, int lenlis)
{
	int	*b;
	int	i;
	int	j;
	int	k;
	
	i = -1;
	j = -1;
	k = 0;
	b = malloc(sizeof(int) * a.len - lenlis);
	if (!b)
		return (NULL);
	while (++i < a.len)
	{
		while (++j < lenlis && a.tab[i] != lis[j])
		if (j == lenlis)
		{
			b[k] = a.tab[i];
			k++;
		}
		j = -1;
	}
	return (b);
	
}
int main()
{
	s_data a;
	int i = 0;
	int *tab = malloc(sizeof(int) * 5);
	int *lisfine;

	if (!tab)
		return (0);
	tab[0] = 6;
	tab[1] = 4;
	tab[2] = 1;
	tab[3] = 2;
	tab[4] = 42;
	a.len = 5;
	a.tab = tab;
	printf("helo\n");
	startsmall(&a);
	while (i < a.len)
	{
		printf("a[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	lisfine = determine_lis(&a);
	if (!a.tab || !lisfine)
		return (1);
/*	while (i < 3)
	{
		printf("lis[%d] : %d\n", i, lisfine[i]);
		i++;
	}*/
	return (0);
}
