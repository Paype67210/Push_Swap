/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:27 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	do_moves_2(t_node **stack_a, t_node **stack_b, t_node **node)
{
	while ((*node)->rra && (*node)->rrb)
	{
		rrr(stack_a, stack_b);
		(*node)->rra--;
		(*node)->rrb--;
	}
	while ((*node)->rra)
	{
		rra(stack_a, 1);
		(*node)->rra--;
	}
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}
	pa(stack_a, stack_b);
}

void	do_moves_1(t_node **stack_a, t_node **stack_b, t_node **node)
{
	while ((*node)->ra && (*node)->rb)
	{
		rr(stack_a, stack_b);
		(*node)->ra--;
		(*node)->rb--;
	}
	while ((*node)->ra)
	{
		ra(stack_a, 1);
		(*node)->ra--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	pa(stack_a, stack_b);
}

void	do_moves(t_node **stack_a, t_node **stack_b, t_node **node)
{
	if ((*node)->move == 1)
		do_moves_1(stack_a, stack_b, node);
	else if ((*node)->move == 2)
		do_moves_2(stack_a, stack_b, node);
}
