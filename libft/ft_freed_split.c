/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freed_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:50:00 by pdeson            #+#    #+#             */
/*   Updated: 2024/01/09 15:58:38 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freed_split(char *s, char c)
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
	free(s);
	array[i] = NULL;
	return (array);
}
