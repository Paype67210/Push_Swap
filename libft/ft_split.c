/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:04:55 by pdeson            #+#    #+#             */
/*   Updated: 2024/01/09 16:16:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char *s, char c)
{
	int	init;
	int	i;
	int	word_count;

	init = 0;
	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			init = 0;
		else if (!init)
		{
			init = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

int	word_len(int pos, char *s, char c)
{
	int	i;

	i = 0;
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
	{
		i++;
		pos++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		len;
	int		pos;
	int		i;
	int		count;

	count = word_count((char *)s, c);
	pos = 0;
	array = malloc ((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		len = word_len(pos, (char *)s, c);
		array[i] = malloc ((len + 1) * sizeof(char));
		if (!array[i])
			return (NULL);
		pos = ft_strncpy(array[i], pos, (char *)s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
