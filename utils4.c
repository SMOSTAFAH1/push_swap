/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 17:07:10 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 17:07:10 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		tam;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	tam = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(tam);
	if (res == NULL)
		return (NULL);
	if (s1 != NULL)
		copy_string_from_index(s1, res, 0);
	if (s2 != NULL)
		copy_string_from_index(s2, res, ft_strlen(s1));
	res[tam - 1] = '\0';
	return (res);
}

int	count_words(char const *s, char c)
{
	int	res;
	int	i;
	int	lock;

	i = 0;
	res = 0;
	lock = 0;
	while (s[i])
	{
		if (s[i] != c && !lock)
		{
			res++;
			lock = 1;
		}
		else if (s[i] == c)
			lock = 0;
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		flag;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		flag = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * (i - flag + 1));
		if (!res[j])
			return (free_matrix(res));
		ft_strlcpy(res[j], s + flag, i - flag + 1);
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!s)
		return (NULL);
	while (!found && s[i])
	{
		if (s[i] == (char)c)
			found = 1;
		else
			i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		found = 1;
	if (found)
		return ((char *)(s + i));
	return (NULL);
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
