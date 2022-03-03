/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:09:30 by avaures           #+#    #+#             */
/*   Updated: 2022/03/03 12:00:20 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_charset(char c, char charset)
{
	if (charset == c)
		return (1);
	return (0);
}

int	count_words(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_in_charset(str[i], charset))
			i++;
	}
	return (count);
}

int	word_lenght(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && !is_in_charset(str[i], charset))
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_strndup(char **dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	*dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!*dest)
		return (0);
	while (i < n && src[i])
	{
		(*dest)[i] = src[i];
		i++;
	}
	while (i < n)
	{
		(*dest)[i] = '\0';
		i++;
	}
	(*dest)[i] = '\0';
	return (n);
}

char	**ft_split(const char *str, char charset)
{
	int			i;
	int			j;
	int			number_word;
	int			word_len;
	char		**tab;

	i = 0;
	j = -1;
	if (!str)
		return (NULL);
	number_word = count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (number_word + 1));
	if (!tab)
		return (NULL);
	while (++j < number_word)
	{
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		word_len = word_lenght(str + i, charset);
		i += ft_strndup(&tab[j], str + i, word_len);
		if (!tab[j])
			return (NULL);
	}
	tab[j] = NULL;
	return (tab);
}
