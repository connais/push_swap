/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/17 15:39:36 by avaures          ###   ########.fr       */
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
	while (i < b.len)
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
//	printf("found[0] : %d\n", found[0]);
	found[1] = better; //pour push d'une stack a l'autre il faut un coup
	return ;
}
/*
int main()
{
	s_data a;
	s_data b;
	char **arg_long;
	if (argc == 2)
	{
		arg_long = ft_split(argv[1], ' ');
		if (!arg_long)
			return (ft_printf("error of arguments\n"), 0);
		a.len = count_words(argv[1], ' ');
//		ft_printf("taille arg : %d\n", a->len);
		a.tab = get_tab_long(arg_long, a.len);
		if (!a.tab)
			return (ft_printf("error of arguments2\n"), 0);
//		i = 0;
//		printf("premier elemtab ->%d\n", a->tab[0]);
//		while (i < 3)
//			printf("%d\n", a->tab[i++]);
//		sort_tab_3(a, b);
//		i = 0;
//		while (i < 3)
//			printf("%d\n", a->tab[i++]);
	}
//	printf("enter !! \n");
	if (argc > 2)
	{
		a.tab = get_tab(argv, argc - 1);
		a.len = argc;
		if (!a.tab || a.tab == NULL)
			return (ft_printf("error of arguments3\n"), 0);
//		printf("premier elemtab ->%d\n", a->tab[0]);
//		while (i < 3)
//			printf("%d\n", a->tab[i++]);
//		sort_tab_3(a, b);
//		i = 0;
//		while (i < 3)
//			printf("%d\n", a->tab[i++]);
	}
	
	a.tab = malloc(sizeof(int) * 10);
	b.tab = malloc(sizeof(int) * 4);
	a.tab[0] = 3;
	a.tab[1] = 8;
	a.tab[2] = 9;
	a.tab[3] = 10;
	a.tab[4] = 1;
	a.tab[5] = 2;

	b.tab[0] = -1;
	b.tab[1] = 6;
	b.tab[2] = 411;
	b.tab[3] = 7;
	a.len = 6;

	b.len = 4;
	

	int i = 0;
	int ** tabl = malloc(sizeof(int) * b.len);
	while(i < b.len) 
	{	
  	  	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	
	determine_coords_b(b, tabl);
	determine_coords_a(a, b, tabl);
	
//	i = 0;
//	while (i < b.len)
//	{
//		printf("pour %d : %d, %d\n", b.tab[i],tabl[i][0], tabl[i][1]);
//		i++;
//	}
	int *found = malloc(sizeof(int) * 2);
	i = 0;
	int j = 0;
	while (i < 4)
	{
//		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		found_best(found, tabl, b);
//		printf("found[0] : %d found[1] : %d\n", found[0], found[1]);
//		printf("%d %d\n", tabl[found[0]][0], tabl[found[0]][1]);
//		printf("pour l'elem %d l'indice est : %d et le nb de coup : %d\n",b.tab[found[0]], found[0], found[1]);
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

}*/
