/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by avaures           #+#    #+#             */
/*   Updated: 2022/03/09 12:17:23 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int found_position(s_data *a)
{
	int	i;
	int	position;
	int	smallest;

	i = 0;
	position = 0;
	smallest = a->tab[i];
	while (++i < a->len)
		if(smallest > a->tab[i])
		{
			smallest = a->tab[i];
			position = i;
		}
	return (position);
}

int found_smallest(s_data *a)
{
	int	position;
	int	smallest;

	position = 0;
	smallest = a->tab[position];
	while (++position < a->len)
		if(smallest > a->tab[position])
			smallest = a->tab[position];
	return (smallest);
}

int	*determine_lis(s_data *a)
{

	s_data	lis;
	int	max_lis;
	s_data	tmp;
	int	i;
	int	j;
	int	k;
	int	l;
	int	position;
	s_data	*b;

	position = found_position(a);
	i = 0;
	max_lis = 0;
	j = 0;
	k = 0;
	l = 0;
	lis.len = 1;
	tmp.tab = malloc(sizeof(int) * a->len);
	if (!tmp.tab)
		return (NULL);
	lis.tab = malloc(sizeof(int) * a->len);
	if (!lis.tab)
		return (NULL);
	tmp.len = a->len;
	while (i < a->len)
	{
		tmp.tab[i] = a->tab[i];
		i++;
	}
	i = 0;
	while (i < a->len)
	{
		printf("oldtmp[%d] : %d\n", i, tmp.tab[i]);
		i++;
	}
	
	printf("position du plus petit dans la iste de depart : %d\n", position);
	
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
	printf("position du plus petit dans la iste de depart : %d\n", position);
	i = 0;
	while (i < a->len)
	{
		printf("tmp[%d] : %d\n", i, tmp.tab[i]);
		i++;
	}
	/*
	i = 0;
	while (k < a->len && max_lis < (a->len - k))
	{
		ft_printf("DEBUT DUNE LIS : \n");
		lis.tab[j] = tmp.tab[i];
		ft_printf("%d termes de la LIS first : %d\n", j, lis.tab[j]);
		i++;
		while (i < a->len)
		{
			if (tmp.tab[i] > lis.tab[j])
			{
				j++;
				lis.tab[j] = tmp.tab[i];
				ft_printf("%d termes de la LIS : %d\n", j, lis.tab[j]);
				lis.len++;
			}
			i++;
		}
		k++;
		i = k;
		j = 0;
		if (max_lis < lis.len)
			max_lis = lis.len;
		lis.len = 1;
	}
	*/
	i = 0;
	j = 0;
	k = 0;
	lis.len = 1;
	int tour = 1;
	while (k < tmp.len -1)
	{
		ft_printf("DEBUT DUNE LIS : \n");
		lis.tab[i] = tmp.tab[k];
		ft_printf("%d termes de la LIS first : %d\n", i, lis.tab[i]);
		j = k + 1;
		while (tour < tmp.len - 1)
		{
			ft_printf("DEBUT DUNE LIS : \n");
			while (j < tmp.len - 1)
			{
				if (lis.tab[i] < tmp.tab[j])
				{
					i++;
					lis.tab[i] = tmp.tab[j];
					ft_printf("%d termes de la LIS : %d\n", i, lis.tab[i]);
				}
				j++;
			}
			i = 0;
			j = tour;
			tour++;
		}
		k++;
		i = 0;
		j = k;
		tour = k;
	}
	/*
	while (lis.len != max_lis)
	{
		lis.len = 1;
		ft_printf("DEBUT DUNE LIS : \n");
		lis.tab[j] = tmp.tab[i];
		ft_printf("%d termes de la LIS first : %d\n", j, lis.tab[j]);
		i++;
		while (i < a->len)
		{
			if (tmp.tab[i] > lis.tab[j])
			{
				j++;
				lis.tab[j] = tmp.tab[i];
				ft_printf("%d termes de la LIS : %d\n", j, lis.tab[j]);
				lis.len++;
			}
			i++;
		}
		k++;
		i = k;
		j = 0;
		if (max_lis < lis.len)
			max_lis = lis.len;
	}
	*/
	i = 0;
	while (i < a->len)
	{
		printf("lis[%d] : %d\n", i, lis.tab[i]);
		i++;
	}
	return (lis.tab);
}
int main()
{
	s_data a;
	int i = 0;
	int *tab = malloc(sizeof(int) * 10);
	int *lis;
	if (!tab)
		return (0);
	tab[0] = 6;
	tab[1] = 4;
	tab[2] = 1;
	tab[3] = 42;
	tab[4] = 11;
	tab[5] = 2;
	tab[6] = 9;
	tab[7] = 99;
	tab[8] = 12;
	tab[9] = 27;
	ft_printf("hello1\n");
	a.len = 10;
	a.tab = tab;
	ft_printf("hello2\n");
	lis = determine_lis(&a);
	return (0);
}
