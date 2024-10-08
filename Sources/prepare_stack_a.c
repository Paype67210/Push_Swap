/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:51 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	find_spot(t_max **max, int i, t_node **b, t_node *a)
{
	int	curr_max;

	if ((*b)->nb < a->nb)
	{
		curr_max = a->index - (*b)->index;
		if (curr_max < (*max)->nb)
		{
			(*max)->nb = curr_max;
			if (i <= (*max)->size / 2)
			{
				(*b)->move = 1;
				(*b)->ra = i;
			}
			else
			{
				(*b)->move = 2;
				(*b)->rra = (*max)->size - i;
			}
		}
	}
}

void	t_max_init(t_max **max, t_node **stack_a)
{
	*max = malloc(sizeof(t_max));
	if (!(*max))
		exit(EXIT_FAILURE);
	(*max)->nb = 2147483647;
	(*max)->size = stack_size(*stack_a);
}

void	find_spot_in_loop(t_node **stack_a, t_node **b, t_max **max)
{
	t_node	*a;
	int		i;

	a = *stack_a;
	i = 0;
	while (a->next != *stack_a)
	{
		find_spot(max, i, b, a);
		a = a->next;
		i++;
	}
	find_spot(max, i, b, a);
}

void	prepare_stack_a(t_node **stack_a, t_node **b)
{
	t_max	*max;
	int		i;

	t_max_init(&max, stack_a);
	i = is_max(*stack_a, (*b));
	if (i <= max->size / 2 && i >= 0)
	{
		(*b)->move = 1;
		(*b)->ra = i + 1;
		free(max);
		return ;
	}
	else if (i > max->size / 2 && i >= 0)
	{
		(*b)->move = 2;
		(*b)->rra = max->size - i - 1;
		free(max);
		return ;
	}
	find_spot_in_loop(stack_a, b, &max);
	free(max);
}
