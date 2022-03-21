/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/21 19:21:16 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	found_best(int *found, int **shot, s_data b)
{
	int		i;
	int		better;
	int		save_i;
	static int	*cpy = NULL;
	int		x;
	int		y;
//	i = 0;
//	printf("lenb%d\n", b.len);
//	while (i < b.len)
//	{
//		printf("found_pour %d : %d, %d\n", b.tab[i],shot[i][0], shot[i][1]);
//		i++;
//	}
	i = 0;
	if (!cpy)
	{
		cpy = malloc(sizeof(int) * b.len);
		if (!cpy)
			return ;
		while (i < b.len)
		{
			cpy[i] = 0;
			i++;
		}
	}
	i = 0;
	save_i = 0;
	x = shot[0][0];
	y = shot[0][1];
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	better =  x + y;
	while (i < b.len)
	{
		
		x = shot[i][0];
		y = shot[i][1];
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		if (better >= y + x && cpy[i] == 0)
		{
			better = y + x;
			save_i = i;
		}
		i++;
	}
	cpy[save_i] = 1;
	found[0] = save_i;
	found[1] = better; 
	return ;
}

int main(int argc, char **argv)
{
	s_data	a;
	s_data	b;
	int	i;
	int	j;
	char	**arg_long;
	int	x;
	if (argc == 1)
		return (printf("Invalid number of argument\n"));
	if (argc == 2)
	{
		arg_long = ft_split(argv[1], ' ');
		if (!arg_long)
			return (ft_printf("error of arguments\n"), 0);
		a.len = count_words(argv[1], ' ');
		a.tab = malloc(sizeof(int) * a.len);
		a.tab = get_tab_long(arg_long, a.len);
		if (!a.tab)
			return (ft_printf("error of arguments2\n"), 0);
	}
	if (argc > 2)
	{
		a.len = argc - 1;
		a.tab = malloc(sizeof(int) * a.len);
		a.tab = get_tab(argv, argc - 1);
		if (!a.tab)
			return (ft_printf("error of arguments3\n"), 0);
	}
	if (!a.lis || !a.sub)
		return (1);
	place_it_on_top(&a,min(a));
	get_lis(&a);
	printf("a.len : %d\n", a.len);
	printf("len_sub : %d\n", a.len_sub);
	b.len = a.len - a.len_sub;
	b.tab = malloc(sizeof(int) * b.len);
	printf("b.len : %d\n", b.len);
	i = 0;
	j = 0;
	while(i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	i = 0;
	while(i < a.len_sub)
	{
		printf("sub[%d] : %d\n", i, a.sub[i]);
		i++;
	}
	i = 0;
	int vu = 0;
	int indice = 0;
	while(i < a.len)
	{
		while (j < a.len_sub)
		{
			if (a.tab[i] == a.sub[j])
			{
				vu++;
			}
			j++;
		}
		if (vu == 0)
		{
			printf("pas vu : %d\n", a.tab[i]);
			place_it_on_top(&a, i);
			push_b(&a, &b);
		}
		else
		{
			printf("vu : %d\n", a.tab[i]);
			place_it_on_top(&a, i);
			rotate_ra(&a, &b);
		}
		vu = 0;
		i++;
		j = 0;
	}
	i = 0;
	while(i < b.len)
	{
		printf("b.tab[%d] : %d\n", i, b.tab[i]);
		i++;
	}
	i = 0;
	while (i < a.len_sub)
	{
		a.tab[i] = a.sub[i];
		i++;
	}
	free(a.sub);
	i = 0;
//	a.len = a.len_sub;
	int ** tabl = malloc(sizeof(int) * b.len);
	while(i < b.len) 
	{	
  	  	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	int *found = malloc(sizeof(int) * 2);
	determine_coords_b(b, tabl);
	determine_coords_a(a, b, tabl);
	i = 0;
	j = 0;
	int k = 0;
	while (b.len > 0)
	{
//		printf("ok\n");
		found_best(found, tabl, b);
//		printf("found[%d] : %d found[%d] %d\n", 0, found[0], 1, found[1]);
		while(k < a.len)
		{
			printf("->a.tab[%d] : %d\n", k, a.tab[k]);
			k++;
		}
		j = sort_tab(tabl, found, a, b);
		a.len++;
		b.len--;
		i++;
		k = 0;
		determine_coords_b(b, tabl);
		determine_coords_a(a, b, tabl);
	}
	a.len = argc - 1;
//	printf("a.len : %d\n", a.len);
	i = 0;
	while (i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
}
