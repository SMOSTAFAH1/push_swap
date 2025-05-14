/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 16:13:14 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 16:13:14 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*ft_lstclone_and_delete_last(t_list **stack, t_list *node)
{
	t_list	*res;
	t_list	*list;

	if (!node)
		return (NULL);
	res = ft_lstnew(node->content);
	res->index = node->index;
	list = *stack;
	while (list && list->next && list->next->content != node->content)
		list = list->next;
	if (list)
		list->next = NULL;
	if (node)
		free(node);
	return (res);
}

void	*free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !matrix[0])
		return (NULL);
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

int	has_repeated(t_list **stack)
{
	t_list	*iter;
	t_list	*iter_aux;
	int		value;

	if (!stack || !*stack)
		return (0);
	iter = *stack;
	while (iter)
	{
		value = iter->content;
		iter_aux = iter->next;
		while (iter_aux)
		{
			if (value == iter_aux->content)
				return (1);
			iter_aux = iter_aux->next;
		}
		iter = iter->next;
	}
	return (0);
}

int	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 0 || nb == 1)
		return (nb);
	else if (nb >= 2)
	{
		while (i * i < nb)
			i++;
		return (i);
	}
	return (0);
}
