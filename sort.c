/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 16:04:28 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 16:04:28 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*list_to_array(t_list *list)
{
	int	size;
	int	*array;
	int	i;

	size = ft_lstsize(list);
	if (size < 1)
		return (NULL);
	array = (int *) malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = list->content;
		list = list->next;
		i++;
	}
	return (array);
}

void	insertion_sort(int *array, int size)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

void	indexer(t_list *stack, int *array, int size)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (!flag && j < size)
		{
			if (stack->content == array[j])
			{
				stack->index = j;
				flag = 1;
			}
			j++;
		}
		flag = 0;
		stack = stack->next;
		i++;
	}
}

void	ksort_range_in_b(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	unsigned int	i;
	unsigned int	range;

	i = 0;
	range = ft_sqrt(size) * 1.4;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b', 1);
			if (*stack_a && (*stack_a)->index > i + range)
				double_move(stack_a, stack_b, 1, 'r');
			else
				rotate(stack_b, 'b', 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, 'b', 1);
			i++;
		}
		else
			rotate(stack_a, 'a', 1);
	}
}

void	ksort_back_to_a(t_list **stack_a, t_list **stack_b, unsigned int size)
{
	int	rb_count;
	int	rrb_count;
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		rb_count = count_rotations(stack_b, i);
		rrb_count = i + 1 - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stack_b)->index != (unsigned int) i)
				rotate(stack_b, 'b', 1);
		}
		else
		{
			while ((*stack_b)->index != (unsigned int) i)
				reverse_rotate(stack_b, 'b', 1);
		}
		push(stack_b, stack_a, 'a', 1);
		i--;
	}
}
