/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:23:08 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:25 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	**ft_create_array(int *argc, char **argv, int i)
{
	char	**array;

	if (*argc == 2)
	{
		array = ft_split(argv[1], ' ');
		*argc = ft_array_size(array);
	}
	else
	{
		array = malloc(sizeof(char *) * (*argc));
		if (!array)
			exit(ft_error(0));
		while (++i < *argc)
			array[i - 1] = ft_strdup(argv[i]);
		array[i - 1] = NULL;
		(*argc)--;
	}
	if (!array)
	{
		ft_free_array(array);
		exit(ft_error(0));
	}
	ft_verif_array(array);
	return (array);
}

void	ft_verif_array(char **array)
{
	int	verif;

	verif = 0;
	if (!ft_check_digit(array, 0, 0))
		verif = 99;
	if (!ft_isint(array, 0, verif) && verif != 99)
		verif = 2;
	if (!ft_unics(array, 0, verif) && verif != 2)
		verif = 1;
	if (verif != 0)
	{
		ft_free_array(array);
		exit(ft_error(verif));
	}
}

int	ft_check_digit(char **array, int i, int j)
{
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (j == 0 && (array[i][j] == '-' || array[i][j] == '+'))
				j++;
			else if (ft_isdigit(array[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_isint(char **array, int i, int verif)
{
	int	len;

	if (verif == 99)
		return (0);
	while (array[i])
	{
		len = ft_strlen(array[i]);
		if ((array[i][0] != '-' && len > 10) || \
				(array[i][0] == '-' && len > 11))
			return (0);
		else if (((array[i][0] != '-' && len == 10) || \
				(array[i][0] == '-' && len == 11)) && \
				ft_check_overflow(array[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_unics(char **array, int i, int verif)
{
	int	j;

	if (verif == 2)
		return (0);
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (array[i][0] == '0' || (array[i][0] == '-' && \
				array[i][1] == '0') || (array[i][0] == '+' && \
				array[i][1] == '0'))
			{
				if (array[j][0] == '0' || (array[j][0] == '-' && \
				array[j][1] == '0') || (array[j][0] == '+' && \
				array[j][1] == '0'))
					return (0);
			}	
			else if (ft_strcmp(array[i], array[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
