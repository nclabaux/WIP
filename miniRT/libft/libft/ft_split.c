/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:47:03 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:16:38 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	word_counter(char const *s, char c, int *nb_word)
{
	int	in_word;
	int	i;

	i = -1;
	in_word = 0;
	while (s[++i])
	{
		if (in_word)
		{
			if (s[i] == c)
			{
				in_word = 0;
				(*nb_word)++;
			}
		}
		else
		{
			if (s[i] != c)
				in_word = 1;
		}
	}
	if (i > 1 && s[i - 1] != c)
		(*nb_word)++;
}

static void	init(int *count, unsigned long *i, int *in_word, int *word)
{
	*count = 0;
	*i = -1;
	*in_word = 0;
	*word = 0;
}

static int	word_size(char const *s, char c, char **res)
{
	int		in_word;
	size_t	i;
	int		count;
	int		word;

	init(&count, &i, &in_word, &word);
	while (++i <= ft_strlen(s))
	{
		if (in_word)
		{
			if (s[i] == c || s[i] == 0)
			{
				in_word = 0;
				if (!(res[word++] = malloc(sizeof(char) * (count + 2))))
					return (word);
				count = 0;
			}
			else
				count++;
		}
		else if (s[i] != c)
			in_word = 1;
	}
	return (-1);
}

static void	filling(char const *s, char c, char **res)
{
	int		in_word;
	size_t	i;
	int		j;
	int		word;

	init(&word, &i, &in_word, &j);
	while (++i <= ft_strlen(s))
	{
		if (in_word)
		{
			if (s[i] == c || s[i] == 0)
			{
				in_word = 0;
				res[word++][j] = 0;
				j = 0;
			}
			else
				res[word][j++] = s[i];
		}
		else if (s[i] != c && s[i] != 0)
		{
			in_word = 1;
			res[word][j++] = s[i];
		}
	}
}

char		**ft_split(char const *s, char c)
{
	int		nb_word;
	char	**res;
	int		i;
	int		error;

	if (!s)
		return (NULL);
	nb_word = 0;
	word_counter(s, c, &nb_word);
	if (!(res = malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	res[nb_word] = NULL;
	error = word_size(s, c, res);
	if (error != -1)
	{
		i = 0;
		while (i < error)
			free(res[i++]);
		free(res);
	}
	filling(s, c, res);
	return (res);
}
