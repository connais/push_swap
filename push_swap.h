#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include "LIBFT/libft.h"
#include "command/command.h"
#include <stdlib.h>

void	get_lis(s_data *a);
void	test_lis(s_data *a);
void	get_sub_sequence(s_data *a);
void	place_it_on_top(s_data *a, int min_pos);
void	find_lis_max(s_data *a);
int	look_for_smallest_num(s_data a);
int     	valid_arg(char *str);                                                   
int		check_overflow(char *str);
int     	check_double(int *tab, int size, int nb);
int     	*get_tab(char **arg, int nb_arg);
int     	*get_tab_long(char **arg, int nb_arg);
int		found_position(s_data *a);
int		max(int *array, int len);
int      is_in_charset(char c, char charset); 
int      count_words(const char *str, char charset);
int      word_lenght(const char *str, char charset);
int      ft_strndup(char **dest, const char *src, unsigned int n);
int min(s_data a);
int maxi(s_data a);
int indice_min(s_data a);
int indice_max(s_data a);
int	*tabl_diff(int place, s_data a);
int	determine_place(int place, s_data a);
int	set_more(s_data *a, int argc, char **argv);
int	set_two(s_data *a, char **argv);
void	final_move(s_data *a);
void determine_coords_a(s_data a, s_data b, int **coords);
void	make_b(s_data *a, s_data *b);
void	big_sort(s_data *a, s_data *b);
void	found_best(int *found, int **tabl, s_data b);
void determine_coords_b(s_data b, int **coords);
int	sort_tab(int **tabl, int *found, s_data, s_data b);
char    	**ft_split(const char *str, char charset);

#endif
