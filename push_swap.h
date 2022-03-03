#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/ft_printf.h"
#include "LIBFT/libft.h"
#include "command/command.h"
#include <stdlib.h>

int     	valid_arg(char *str);                                                   
int		check_overflow(char *str);
int     	check_double(int *tab, int size, int nb);
int     	*get_tab(char **arg, int nb_arg);
int     	*get_tab_long(char **arg, int nb_arg);
int      is_in_charset(char c, char charset); 
int      count_words(const char *str, char charset);
int      word_lenght(const char *str, char charset);
int      ft_strndup(char **dest, const char *src, unsigned int n);
char    	**ft_split(const char *str, char charset);

#endif
