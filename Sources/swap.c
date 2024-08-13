/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:43:31 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sa(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	node = *stack;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack, int a)
{
	t_node	*node;
	int		tmp;

	node = *stack;
	if (!node)
		return ;
	tmp = node->nb;
	node->nb = node->next->nb;
	node->next->nb = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write (1, "ss\n", 3);
}
