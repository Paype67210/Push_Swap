/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:50 by pdeson            #+#    #+#             */
/*   Updated: 2024/08/13 12:58:27 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct node
{
	int			nb;
	int			index;
	struct node	*next;
	struct node	*prev;
	int			value;
	int			sa;
	int			sb;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			move;
}	t_node;

typedef struct seq
{
	int	curr_len;
	int	max_len;
	int	index;
	int	max_index;
	int	start;
}	t_seq;

typedef struct max
{
	int	nb;
	int	size;
}	t_max;

t_node	*stack_a_init(t_node *stack, char **array);
t_node	*create_node(int value);
void	pile_down(t_node *stack, t_node *node);
int		stack_size(t_node *stack);
int		*stack_dup(int *array, t_node *stack);
void	quicksort(t_node *stack, int *array, int start, int end);
void	index_init(t_node *stack);
void	printer(t_node *stack);
void	array_printer(int *array, int size);
void	index_printer(t_node *stack);
void	sa(t_node **stack, int a);
void	sb(t_node **stack, int a);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack, int a);
void	rb(t_node **stack, int a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack, int a);
void	rrb(t_node **stack, int a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	sort_three_numbers(t_node **stack);
void	sort_five_numbers(t_node **stack_a, t_node **stack_b);
void	big_sort(t_node **stack_a, t_node **stack_b);
t_seq	*sequence(t_node **stack);
void	moves_printer(t_node **stack);
void	moves_init(t_node **stack, int n);
void	sort_three_numbers(t_node **stack);
void	markup(t_node **stack_a, t_seq *seq);
int		is_max(t_node *stack_a, t_node *b);
void	do_moves(t_node **stack_a, t_node **stack_b, t_node **node);
void	find_best_push(t_node **stack_a, t_node **stack_b);
void	prepare_stack_a(t_node **stack_a, t_node **b);
void	ft_free_stack(t_node **stack, int size);
int		ft_error(int code);
void	ft_verif_array(char **array);
int		ft_check_overflow(char *str);
char	**ft_create_array(int *argc, char **argv, int i);
int		ft_check_digit(char **array, int i, int j);
int		ft_isint(char **array, int i, int verif);
int		ft_unics(char **array, int i, int verif);
/* ----- BONUS CHECKER -----*/
void	do_moves_bonus(char *str, t_node **stack_a, t_node **stack_b);
void	do_moves_bonus1(char *str, t_node **stack_a, t_node **stack_b);
char	*get_next_line(int fd);
void	ss_bonus(t_node **stack_a, t_node **stack_b);
void	rr_bonus(t_node **stack_a, t_node **stack_b);
void	rrr_bonus(t_node **stack_a, t_node **stack_b);
void	pb_bonus(t_node **stack_a, t_node **stack_b);
void	pa_bonus(t_node **stack_a, t_node **stack_b);

#endif
