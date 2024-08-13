/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:43:01 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	order_checker(t_node *stack, char **array)
{
	t_node	*node;

	node = stack;
	while (node->next != stack)
	{
		if (node->nb > node->next->nb)
			return ;
		node = node->next;
	}
	ft_free_stack(&stack, stack_size(stack));
	ft_free_array(array);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	else if (argv[1] && !argv[1][0])
		exit(ft_error(0));
	array = ft_create_array(&argc, argv, 0);
	stack_a = NULL;
	stack_a = stack_a_init(stack_a, array);
	order_checker(stack_a, array);
	stack_b = NULL;
	if (argc <= 3)
		sort_three_numbers(&stack_a);
	else if (argc <= 5)
		sort_five_numbers(&stack_a, &stack_b);
	else
	{
		index_init(stack_a);
		big_sort(&stack_a, &stack_b);
	}
	ft_free_array(array);
	ft_free_stack(&stack_a, stack_size(stack_a));
}
