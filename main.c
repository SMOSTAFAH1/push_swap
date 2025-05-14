/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 16:00:21 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 16:00:21 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	small_sort(t_list **stack_a)
{
	t_list			*aux;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	if (is_sorted(stack_a))
		return ;
	aux = *(stack_a);
	a = aux->index;
	b = aux->next->index;
	c = aux->next->next->index;
	if (a > b && a > c)
		rotate(stack_a, 'a', 1);
	else if (a > b && a < c)
		swap(stack_a, 'a', 1);
	else if (b > a && b > c)
		reverse_rotate(stack_a, 'a', 1);
	else if (b > a && b > c)
		swap(stack_a, 'a', 1);
	small_sort(stack_a);
}

void	medium_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;

	i = 0;
	while (i < (size - 3))
	{
		if ((*stack_a)->index >= 3)
		{
			push(stack_a, stack_b, 'b', 1);
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
	if (!is_sorted(stack_a))
		small_sort(stack_a);
	if ((*stack_b)->index == 4)
		swap(stack_b, 'b', 1);
	while (ft_lstsize(*stack_b) != 0)
	{
		push(stack_b, stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	if (size == 2)
		swap(stack_a, 'a', 1);
	else if (size == 3)
		small_sort(stack_a);
	else if (size <= 5)
		medium_sort(stack_a, stack_b, size);
	else
	{
		ksort_range_in_b(stack_a, stack_b, size);
		ksort_back_to_a(stack_a, stack_b, size);
	}
}

void	double_move(t_list **stack_a, t_list **stack_b, int output, char move)
{
	if (move == 's')
	{
		swap(stack_a, 'a', 0);
		swap(stack_b, 'b', 0);
		if (output)
			write(STDOUT_FILENO, "ss\n", 3);
	}
	else if (move == 'r')
	{
		rotate(stack_a, 'a', 0);
		rotate(stack_b, 'b', 0);
		if (output)
			write(STDOUT_FILENO, "rr\n", 3);
	}
	else if (move == 'R')
	{
		reverse_rotate(stack_a, 'a', 0);
		reverse_rotate(stack_b, 'b', 0);
		if (output)
			write(STDOUT_FILENO, "rrr\n", 4);
	}
}

int	main(int argc, char **argv)
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*array;
	unsigned int	size;

	if (argc < 2 || !argv[1][0])
		return (print_error());
	stack_a = parse_numbers(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		return (print_error());
	if (has_repeated(&stack_a))
		return (ft_lstclear(&stack_a), print_error());
	if (is_sorted(&stack_a))
		return (ft_lstclear(&stack_a), 1);
	size = ft_lstsize(stack_a);
	array = list_to_array(stack_a);
	insertion_sort(array, size);
	indexer(stack_a, array, size);
	free(array);
	sort_stack(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
