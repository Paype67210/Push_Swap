/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:54 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pointers_init_bonus(t_node **l, t_node **n, t_node **s, t_node **stack)
{
	*l = (*stack)->prev;
	*n = *stack;
	*s = (*stack)->next;
}

void	pa_bonus(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*last;
	t_node	*second;
	int		a;

	if (!(*stack_b))
		return ;
	a = 1;
	if ((*stack_b)->next == *stack_b && (*stack_b)->prev == *stack_b)
		a = 0;
	pointers_init_bonus(&last, &node, &second, stack_b);
	node->next = *stack_a;
	(*stack_a)->prev->next = node;
	node->prev = (*stack_a)->prev;
	(*stack_a)->prev = node;
	*stack_a = node;
	if (!a)
		*stack_b = NULL;
	else
	{
		*stack_b = second;
		(*stack_b)->prev = last;
		last->next = *stack_b;
	}
}

void	pb_bonus(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	if (!(*stack_a))
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = node->prev;
	(*stack_a)->prev->next = *stack_a;
	if (!(*stack_b))
	{
		node->prev = node;
		node->next = node;
		*stack_b = node;
	}
	else
	{
		node->next = *stack_b;
		node->prev = (*stack_b)->prev;
		*stack_b = node;
		(*stack_b)->prev->next = *stack_b;
		(*stack_b)->next->prev = *stack_b;
	}
}
