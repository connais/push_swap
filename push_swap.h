/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:27:51 by avaures           #+#    #+#             */
/*   Updated: 2022/03/24 17:57:00 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "LIBFT/libft.h"
# include "command/command.h"
# include <stdlib.h>

typedef struct s_coords
{
	int	x;
	int	y;
	int	better;
	int	save_i;
	int	i;
}t_coords;

char	**ft_split(const char *str, char charset);
void	get_lis(t_data *a);
void	test_lis(t_data *a);
void	get_sub_sequence(t_data *a);
void	place_it_on_top(t_data *a, int min_pos);
void	find_lis_max(t_data *a);
void	final_move(t_data *a);
void	determine_coords_a(t_data a, t_data b, int **coords);
void	make_b(t_data *a, t_data *b);
void	big_sort(t_data *a, t_data *b);
void	found_best(int *found, int **tabl, t_data b);
void	determine_coords_b(t_data b, int **coords);
int		is_little_tab(t_data *a, t_data *b);
int		look_for_smallest_num(t_data a);
int		valid_arg(char *str);
int		check_overflow(char *str);
int		check_double(int *tab, int size, int nb);
int		check_if_sort(t_data a);
int		*get_tab(char **arg, int nb_arg);
int		*get_tab_long(char **arg, int nb_arg);
int		found_position(t_data *a);
int		max(int *array, int len);
int		is_in_charset(char c, char charset);
int		count_words(const char *str, char charset);
int		word_lenght(const char *str, char charset);
int		ft_strndup(char **dest, const char *src, unsigned int n);
int		min(t_data a);
int		maxi(t_data a);
int		indice_min(t_data a);
int		indice_max(t_data a);
int		**set_tab_sort(int **tabl, t_data *b);
int		*tabl_diff(int place, t_data a);
int		determine_place(int place, t_data a);
int		set_more(t_data *a, int argc, char **argv);
int		set_two(t_data *a, char **argv);
int		sort_tab(int **tabl, int *found, t_data, t_data b);

#endif
