/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:00:15 by avaures           #+#    #+#             */
/*   Updated: 2022/03/15 19:38:27 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_tab(int **tabl, int *found, s_data a, s_data b)
{
	int		i;
	static int	cpt = 0;

	i = 0;
	while (found[1] > 0)
	{
		if (tabl[found[0]][1] >= 0)
			while (tabl[found[0]][1] >= 0)
			{
				rotate_rb(&a, &b);
				cpt++;
				tabl[found[0]][1]--;
				found[1]--;
			}
		else
			while (tabl[found[0]][1] >= 0)
			{
				reverse_rrb(&a, &b);
				cpt++;
				tabl[found[0]][1]++;
				found[1]--;
			}
		if (tabl[found[0]][0] >= 0)
			while (tabl[found[0]][0] >= 0)
			{
				rotate_ra(&a, &b);
				cpt++;
				tabl[found[0]][0]--;
				found[1]--;
			}
		else
			while (tabl[found[0]][0] >= 0)
			{
				reverse_rrb(&a, &b);
				cpt++;
				tabl[found[0]][0]++;
				found[1]--;
			}		
	}
	push_a(&a, &b);
	printf("nbr total : %d\n", cpt);
	return;
}
