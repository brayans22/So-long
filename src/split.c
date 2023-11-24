/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:53:10 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/09/15 21:29:05 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/game.h"

static int	get_total_words(char *s, char c)
{
	int	total;
	int	total_letters;

	total = 0;
	total_letters = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			total_letters++;
			s++;
			if (*s == '\0' || *s == c)
				total++;
		}
	}
	if (total == 0 && total_letters > 0)
		return (1);
	return (total);
}

static void	free_split_memory(char **split, unsigned int total_words)
{
	while (total_words-- > 0)
		free(split[total_words]);
	free(split);
}

static int	fill_split(char **split, char *s, char sep, \
		unsigned int total_words)
{
	unsigned int	len_word;
	unsigned int	i;

	i = 0;
	split[total_words] = NULL;
	while (total_words > 0)
	{
		len_word = 0;
		while (*s == sep && *s)
			s++;
		while (s[len_word] != sep && s[len_word])
			len_word++;
		split[i] = ft_substr(s, 0, len_word);
		if (!split[i])
		{
			free_split_memory(split, i);
			return (-1);
		}
		s += len_word;
		total_words--;
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		total_words;
	int		i;

	if (!s)
		return (NULL);
	total_words = get_total_words((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (total_words + 1));
	if (!split)
		return (NULL);
	i = 0;
	if (fill_split(split, (char *)s, c, total_words) == -1)
		return (NULL);
	return (split);
}
