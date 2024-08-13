/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:00:18 by pdeson            #+#    #+#             */
/*   Updated: 2024/01/09 16:00:52 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncpy(char *array, int pos, char *s, char c)
{
	int	i;

	i = 0;
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
	{
		array[i] = s[pos];
		i++;
		pos++;
	}
	array[i] = '\0';
	return (pos);
}
