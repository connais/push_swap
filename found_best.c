/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/17 20:50:02 by avaures          ###   ########.fr       */
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
	int	*lis;
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
		a.len = argc;
		a.tab = malloc(sizeof(int) * a.len);
		a.tab = get_tab(argv, argc - 1);
		if (!a.tab)
			return (ft_printf("error of arguments3\n"), 0);
	}

	lis = get_lis(a);
	if (!lis)
		return (1);

	b.len = lis[0];
	a.len -= b.len;
	i = 0;
	int ** tabl = malloc(sizeof(int) * b.len);
	while(i < b.len) 
	{	
  	  	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	printf("ok\n");
	i = 0;
	j = 1;
	while (i < a.len)
	{
		while (j < b.len)
		{
			if (a.tab[i] == lis[j])
			{
				x = i;
				while (x > 0)
				{
					rotate_ra(&a, &b);
					ft_printf("ra\n");
					x--;
				}
					push_b(&a, &b);
				j++;
			}
		}
		j = 1;

		i++;
	}
	determine_coords_b(b, tabl);
	determine_coords_a(a, b, tabl);
	int *found = malloc(sizeof(int) * 2);
	i = 0;
	j = 0;
	while (i < 4)
	{
		found_best(found, tabl, b);
		j = sort_tab(tabl, found, a, b);
		a.len++;
		b.len--;
		determine_coords_b(b, tabl);
		determine_coords_a(a, b, tabl);
		i++;
	}
	ft_printf("%d\n", j);
	i = 0;
	while (i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
	i = 0;
	while (i < b.len)
	{
		printf("b.tab[%d] : %d\n", i, b.tab[i]);
		i++;
	}
}
