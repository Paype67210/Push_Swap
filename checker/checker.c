/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 10:42:22 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!str)
		return ;
	if (!ft_strcmp(str, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr_bonus(stack_a, stack_b);
	else
		do_moves_bonus1(str, stack_a, stack_b);
}

void	do_moves_bonus1(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strcmp(str, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		pa_bonus(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		pb_bonus(stack_a, stack_b);
	else
		exit(ft_error(0));
}

int	check_good_sort(t_node *stack_a, t_node *stack_b)
{
	t_node	*node;

	if (stack_b)
	{
		ft_free_stack(&stack_b, stack_size(stack_b));
		return (0);
	}
	node = stack_a;
	while (node->next->next != stack_a)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	if (node->nb > node->next->nb)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**array;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (1);
	array = ft_create_array(&argc, argv, 0);
	stack_a = NULL;
	stack_a = stack_a_init(stack_a, array);
	stack_b = NULL;
	str = "";
	while (str)
	{
		str = get_next_line(0);
		do_moves_bonus(str, &stack_a, &stack_b);
		free(str);
	}
	if (check_good_sort(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_array(array);
	ft_free_stack(&stack_a, stack_size(stack_a));
}
