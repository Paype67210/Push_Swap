/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:43:27 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pile_down(t_node *stack, t_node *node)
{
	t_node	*head;

	head = stack;
	while (head->next != stack)
	{
		if (head->nb == node->nb)
			exit(ft_error(1));
		head = head->next;
	}
	if (head->nb == node->nb)
		exit(ft_error(1));
	if (stack->next == stack && stack->prev == stack)
	{
		stack->next = node;
		stack->prev = node;
		node->prev = stack;
		node->next = stack;
		return ;
	}
	head = stack;
	node->prev = head->prev;
	head->prev->next = node;
	head->prev = node;
	node->next = head;
}

int	*stack_dup(int *array, t_node *stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack;
	array = malloc(sizeof(int) * stack_size(stack));
	if (!array)
		exit(EXIT_FAILURE);
	while (node->next != stack)
	{
		array[i++] = node->nb;
		node = node->next;
	}
	array[i] = node->nb;
	return (array);
}

int	stack_size(t_node *stack)
{
	t_node	*list;
	int		i;

	if (!stack)
		return (0);
	if (stack->next == stack && stack->prev == stack)
		return (1);
	if (stack->next->next == stack || stack->prev == stack)
		return (2);
	list = stack;
	i = 1;
	while (list->next != stack)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->nb = value;
	node->ra = 0;
	node->rb = 0;
	node->rra = 0;
	node->rrb = 0;
	return (node);
}

t_node	*stack_a_init(t_node *stack, char **array)
{
	int		i;

	if (!array)
		exit(EXIT_FAILURE);
	stack = create_node(ft_atoi(array[0]));
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (array[i])
		pile_down(stack, create_node(ft_atoi(array[i++])));
	return (stack);
}
