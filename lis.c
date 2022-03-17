/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:46:37 by avaures           #+#    #+#             */
/*   Updated: 2022/03/17 18:28:34 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	look_for_smallest_num(s_data a)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = a.tab[0];
	j = 0;
	
//	printf("a%d\n", a.len);
	while (i < a.len)
	{
		if (tmp > a.tab[i])
		{
//			printf("%d\n", a.tab[i]);
			tmp = a.tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	find_lis_max(s_data a, int *lis)
{
	int	i;
	int	lis_max;
	int	max_pos;
	i = 0;
	lis_max = 1;
	while (i < a.len)
	{
		if (lis_max < lis[i])
		{
			lis_max = lis[i];
			max_pos = i;
		}
		i++;
	}
	return (lis_max);
}

int	find_max_pos(s_data a, int *lis)
{
	int	i;
	int	lis_max;
	int	max_pos;
	i = 0;
	lis_max = 1;
	while (i < a.len)
	{
		if (lis_max < lis[i])
		{
			lis_max = lis[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	place_it_on_top(s_data a, int min_pos)
{
	s_data b;

	if (min_pos > a.len / 2)
	{
		while (min_pos < a.len)
		{
			rotate_ra(&a, &b);
			min_pos++;
		}
	}
	else
	{
		while (min_pos >= 0)
		{
			reverse_rra(&a, &b);
			min_pos--;
		}
	}
}

int	*get_sub_sequence(s_data a, int *lis)
{
	int	i;
	int	j;
	int	k;
	int	*subsequence;

	i = find_max_pos(a, lis);
	k = find_lis_max(a, lis);
	j = i - 1;
	subsequence = malloc(sizeof(int) * k);
	if (!subsequence)
		return (NULL);
	subsequence[k] = a.tab[i];
	while (j >= 0)
	{
		if (lis[i] - lis[j] == 1)
		{
			k--;
			subsequence[k] = a.tab[j];
			i = j;
		}
		j--;
	}
	subsequence[0] = find_lis_max(a, lis);
	free(lis);
	return (subsequence);
}

int	*test_lis(s_data a)
{
	int	i;
	int	j;
	int 	*lis;

	j = 0;
	lis = malloc(sizeof(int) * a.len);
	if (!lis)
		return (NULL);
	i = -1;
	while (++i < a.len)
		lis[i] = 1;
	i = 1;
	while (i < a.len)
	{
		while (j < i)
		{
			if (a.tab[i] > a.tab[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		j = 0;
		i++;
	}
	return(lis);
}
int *get_lis(s_data a)
{
	int i;
	int	*lis;
	
	i = look_for_smallest_num(a);
	if (i != 0)
		place_it_on_top(a, i);
	
	lis = test_lis(a);
	if (!lis)
		return (NULL);
	
	lis = get_sub_sequence(a, lis);
	i = 0;
	while (i < a.len)
	{
		printf("lis[%d] : %d\n", i, lis[i]);
		i++;
	}
	
	return (lis);
}
/*
int main()
{
	s_data a;
	s_data b;
	int i = 0;
	int *tab = malloc(sizeof(int) * 5);
	int *lis;

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
	lis = get_lis(a);
	if (!a.tab || !lis)
		return (1);
	int lis_len = lis[0] + 1;
	printf("lenlis : %d\n", lis_len);
	i = 0;
	while (i < a.len)
	{
		printf("a[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	i = 1;
	while (i < lis_len)
	{
		printf("lis[%d] : %d\n", i, lis[i]);
		i++;
	}
	return (0);
}
*/
