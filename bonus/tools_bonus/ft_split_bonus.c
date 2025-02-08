/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:09:13 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/03 14:34:27 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		*p1;

	i = 0;
	if (dst == src)
		return (dst);
	p = (const unsigned char *)src;
	p1 = (unsigned char *)dst;
	while (i < n)
	{
		p1[i] = p [i];
		i++;
	}
	return (dst);
}

static char	**free_split_reserve(char **split, size_t j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	**split_string(const char *s, char c, char **split, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < n)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start;
		split[j] = (char *)malloc(len + 1);
		if (!split[j])
			return (free_split_reserve(split, j));
		ft_memcpy(split[j], &s[start], len);
		split[j][len] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	int		word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (split_string(s, c, result, word_count));
}
