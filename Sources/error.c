/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:37:11 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:31 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_error(int code)
{
	if (code == 0)
		write(1, "Error\n", 6);
	else if (code == 1)
		write(1, "Error\n", 6);
	else if (code == 2)
		write(1, "Error\n", 6);
	else if (code == 99)
		write(1, "Error\n", 6);
	else
		write(1, "Error\n", 6);
	return (1);
}

int	ft_check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	else if (ft_atoi(str) < 0)
		return (1);
	return (0);
}
