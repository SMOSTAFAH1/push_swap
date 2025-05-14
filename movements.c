/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 16:00:14 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 16:00:14 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_list **stack, char name, int output)
{
	t_list	*first;
	t_list	*second;
	int		value_aux;
	int		index_aux;

	if (ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	value_aux = second->content;
	index_aux = second->index;
	second->content = first->content;
	second->index = first->index;
	first->content = value_aux;
	first->index = index_aux;
	if (output)
	{
		write(STDOUT_FILENO, "s", 1);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	push(t_list **from, t_list **to, char to_name, int output)
{
	t_list	*aux;

	if (ft_lstsize(*from) < 1)
		return ;
	aux = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, aux);
	if (output)
	{
		write(STDOUT_FILENO, "p", 1);
		write(STDOUT_FILENO, &to_name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	rotate(t_list **stack, char name, int output)
{
	t_list	*aux;
	t_list	*it;

	if (ft_lstsize(*stack) < 2)
		return ;
	aux = *stack;
	*stack = aux->next;
	it = *stack;
	while (it->next)
		it = it->next;
	it->next = aux;
	aux->next = NULL;
	if (output)
	{
		write(STDOUT_FILENO, "r", 1);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	reverse_rotate(t_list **stack, char name, int output)
{
	t_list	*last;
	t_list	*new_front;
	t_list	*stack_iter;

	if (ft_lstsize(*stack) < 2)
		return ;
	stack_iter = *stack;
	last = stack_iter;
	while (last->next)
		last = last->next;
	new_front = ft_lstclone_and_delete_last(stack, last);
	ft_lstadd_front(stack, new_front);
	if (output)
	{
		write(STDOUT_FILENO, "rr", 2);
		write(STDOUT_FILENO, &name, 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

int	is_sorted(t_list **stack)
{
	t_list	*iter;

	iter = *stack;
	while (iter->next)
	{
		if (!(iter->content < iter->next->content))
			return (0);
		iter = iter->next;
	}
	return (1);
}
