/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by avaures           #+#    #+#             */
/*   Updated: 2022/03/10 19:28:52 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int *startsmall(s_data *a)
{
	s_data	tmp;
	s_data	*b;
	int	position;
	int	i;

	position = found_position(a);
	tmp.tab = malloc(sizeof(int) * a->len);
	if (!tmp.tab)
		return (NULL);
	tmp.len = a->len;
	i = 0;
	while (i < a->len)
	{
		tmp.tab[i] = a->tab[i];
		i++;
	}
	if (position <= a->len/2)
		while (position > 0)
		{
			rotate_ra(&tmp, b);
			position--;
		}
	else
		while (position < a->len)
		{
			reverse_rra(&tmp, b);		
			position++;
		}
	return (tmp.tab);
}
int	lislen(s_data *a)
{
	int	*alllen;
	int	*indice;
	int	i;
	int	j;
	int	position;
	s_data	tmp;
	i = 0;
	j = 1;

	tmp.len = a->len;
	tmp.tab = startsmall(a);
	alllen = malloc(sizeof(int) * a->len);
	indice = malloc(sizeof(int) * a->len);
	if (!tmp.tab || !alllen || !indice)
		return (1);
	while (i < a->len)
	{
		indice[i] = -1;
		i++;
	}
	i = 0;
	alllen[0] = 1;
	while (j < a->len)
	{
	printf("j++\n");
		alllen[j] = 1;
		while (i < j - 1)
		{
			if (tmp.tab[i] <= tmp.tab[j] && alllen[j] < alllen[i] + 1)
			{
				alllen[j] = alllen[i] + 1;
				indice[j] = i;
				printf("indice[%d] : %d\n", i, indice[i]);
			}
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
	position = max(alllen, a->len);
	return (position);
}
int	*lis(s_data *a)
{
	int	*alllen;
	int	*indice;
	int	i;
	int	j;
	s_data	tmp;
	s_data	*b;

	tmp.len = a->len;
	tmp.tab = startsmall(a);
	indice = malloc(sizeof(int) * a->len);
	alllen = malloc(sizeof(int) * a->len);
	if (!tmp.tab || !indice || !alllen)
		return (NULL);
	i = 0;
	while (i < a->len)
	{
		indice[i] = 0;
		i++;
	}
	i = 0;
	j = 1;
	alllen[0] = 1;
	while (j < a->len)
	{
		alllen[j] = 1;
		while (i < j - 1)
		{
			if (tmp.tab[i] <= tmp.tab[j] && alllen[j] < alllen[i] + 1)
			{
				alllen[j] = alllen[i] + 1;
				indice[j] = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
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
	int	j;
	int	*indice = lis(a);
	int i = 0;
	s_data	tmp;
	j = len;
	len--;

	tmp.tab = startsmall(a);
	lisfine = malloc(sizeof(int) * len);
	if (!tmp.tab || !lisfine)
		return (NULL);
	while (i < len)
	{
		printf("indicelen[%d] : %d\n", i, indice[i]);
		i++;
	}
	while (len >= 0 && indice[j] != -1)
	{
		j = indice[j];
		lisfine[len] = tmp.tab[j];
		printf("lisfine[%d] : %d\n", len, lisfine[len]);
		len--;
	}
	return (lisfine);
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
	lisfine = determine_lis(&a);
	if (!lisfine)
		return (1);
/*	while (i < 3)
	{
		printf("lis[%d] : %d\n", i, lisfine[i]);
		i++;
	}*/
	return (0);
}
