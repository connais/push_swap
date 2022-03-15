/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:38:55 by avaures           #+#    #+#             */
/*   Updated: 2022/03/15 19:39:38 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	set_found(int **shot, int i, int better, int *found)
{

//	printf("short[i][1] : %d\n", shot[0][0]);
//	printf("ooookkk\n");
	found[0] = i;
	found[1] = better;
}
void	found_best(int *found, int **shot, int len)
{
	int		i;
	int		better;
	int		save_i;
	static int	*cpy = NULL;
	int		x;
	int		y;

	i = 0;
	if (!cpy)
	{
		cpy = malloc(sizeof(int) * len);
		if (!cpy)
			return ;
		while (i < len)
		{
			cpy[i] = 0;
			i++;
		}
	}
	i = -1;
	save_i = 0;
	better =  shot[0][0] + shot[0][1];
	while (++i < len)
	{
		
		x = shot[i][0];
		y = shot[i][1];
		if (x < 0 || y < 0)
		{
			if (x < 0)
				x *= -1;
			y *= -1;
		}
		if (better >= y + x && cpy[i] == 0)
		{
			better = y + x;
			save_i = i;
		}
	}
	cpy[save_i] = 1;
	set_found(shot, save_i, better, found);
	return ;
}
int main()
{
	s_data a;
	s_data b;
	int ** tabl = malloc(sizeof(int) * 10);
	int i = 0;
	while(i < 10) 
	{	
    	tabl[i] = malloc(sizeof(int) * 2);
		i++;
	}
	a.tab = malloc(sizeof(int) * 10);
	b.tab = malloc(sizeof(int) * 4);
	a.tab[0] = 3;
	a.tab[1] = 8;
	a.tab[2] = 9;
	a.tab[3] = 0;
	a.tab[4] = 1;
	a.tab[5] = 2;
	b.tab[0] = 10;
	b.tab[1] = 6;
	b.tab[2] = 4;
	b.tab[3] = 7;
	a.len = 10;
	b.len = 4;
	determine_coords_b(b, tabl);
	determine_coords_a(a, b, tabl);
	i = 0;
//	while (i < b.len)
//	{
//		printf("pour %d : %d, %d\n", b.tab[i],tabl[i][0], tabl[i][1]);
//		i++;
//	}
	int *found = malloc(sizeof(int) * 2);
	i = 0;
	while (i < b.len)
	{
		found_best(found, tabl, b.len);
		printf("%d %d\n", tabl[i][0], tabl[i][1]);
		printf("pour l'elem %d l'indice est : %d et le nb de coup : %d\n",b.tab[i], found[0], found[1]);
		sort_tab(tabl, found, a, b);
		i++;
	}
	i = 0;
	while (i < a.len)
	{
		printf("a.tab[%d] : %d\n", i, a.tab[i]);
		i++;
	}
}
