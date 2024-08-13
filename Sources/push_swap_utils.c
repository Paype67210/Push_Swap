/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:58 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	moves_init(t_node **stack, int n)
{
	t_node	*node;

	if (!stack)
		exit(EXIT_FAILURE);
	node = *stack;
	while (node->next != *stack)
	{
		node->sa = n;
		node->sb = n;
		node->ra = n;
		node->rb = n;
		node->rra = n;
		node->rrb = n;
		node->move = n;
		node = node->next;
	}
	node->sa = n;
	node->sb = n;
	node->ra = n;
	node->rb = n;
	node->rra = n;
	node->rrb = n;
	node->move = n;
}
