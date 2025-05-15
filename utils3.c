/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 17:07:16 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 17:07:16 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	copy_string_from_index(const char *src, char *dst, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	if (!dstsize)
		dst = NULL;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	tam;

	tam = ft_strlen(s1) + 1;
	res = (char *)malloc(tam);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, tam);
	return (res);
}

int	count_rotations(t_list **stack, unsigned int index)
{
	t_list	*original;
	int		res;
	int		flag;

	res = 0;
	flag = 0;
	if (!*stack)
		return (0);
	original = *stack;
	while (*stack && (*stack)->next && !flag)
	{
		if ((*stack)->index == index)
			flag = 1;
		else
			res++;
		*stack = (*stack)->next;
	}
	*stack = original;
	return (res);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (*lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			if (*lst)
				free(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
}
