/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 16:00:45 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 16:00:45 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	input_not_valid(long content, char *original)
{
	if ((content == 0 && (original[0] != '0' || original[1] != '\0'))
		|| (content > INT_MAX || content < INT_MIN))
		return (print_error());
	return (0);
}

char	**get_input_as_char_matrix(int argc, char **argv)
{
	char	*base;
	char	*append;
	char	**res;
	int		i;

	base = ft_strdup(argv[1]);
	if (!base)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		append = ft_strjoin((const char *)base, (const char *)" ");
		free(base);
		if (!append)
			return (NULL);
		base = ft_strjoin((const char *)append, (const char *)argv[i]);
		free(append);
		if (!base)
			return (NULL);
		i++;
	}
	res = ft_split(base, ' ');
	free(base);
	return (res);
}

int	get_matrix_rows(char **matrix)
{
	int	res;

	res = 0;
	while (matrix[res])
		res++;
	return (res);
}

t_list	*create_stack_root(char **num_matrix, int i)
{
	t_list		*stack;
	long		content;

	content = ft_atoi(num_matrix[i]);
	if (input_not_valid(content, num_matrix[i]))
		return (NULL);
	stack = ft_lstnew(content);
	return (stack);
}

t_list	*parse_numbers(int argc, char **argv)
{
	int			i;
	t_list		*stack;
	char		**num_matrix;
	t_list		*new_node;

	num_matrix = get_input_as_char_matrix(argc, argv);
	if (!num_matrix)
		return (NULL);
	i = get_matrix_rows(num_matrix) - 1;
	stack = create_stack_root(num_matrix, i--);
	if (!stack)
		return (free_matrix(num_matrix));
	while (i >= 0)
	{
		new_node = ft_lstnew((int)ft_atoi(num_matrix[i]));
		ft_lstadd_front(&stack, new_node);
		if (input_not_valid(ft_atoi(num_matrix[i]), num_matrix[i]) || !new_node)
		{
			ft_lstclear(&stack);
			return (free_matrix(num_matrix));
		}
		i--;
	}
	free_matrix(num_matrix);
	return (stack);
}
