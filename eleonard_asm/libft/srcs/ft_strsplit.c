/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleonard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:44:07 by eleonard          #+#    #+#             */
/*   Updated: 2019/09/13 13:52:58 by eleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	def_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

static size_t	def_symbols(char const *s, char **arr, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (len > 0)
		{
			arr[count] = ft_strsub(s, (unsigned int)(i - len), len);
			if (arr[count] == NULL)
				return (0);
		}
		count++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words_nbr;
	char	**arr;
	size_t	res;

	res = 0;
	if (s)
	{
		words_nbr = def_words(s, c);
		arr = (char**)malloc(sizeof(char*) * (words_nbr + 1));
		if (arr == NULL)
			return (NULL);
		arr[words_nbr] = 0;
		if (words_nbr > 0)
			res = def_symbols(s, arr, c);
		if (res == 1 || words_nbr == 0)
			return (arr);
		while (words_nbr >= 0)
			ft_strdel(&arr[words_nbr--]);
		free(*arr);
		*arr = NULL;
		return (arr);
	}
	return (NULL);
}
