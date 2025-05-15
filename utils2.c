/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 17:16:53 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 17:16:53 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (!lst->next)
			return (i);
		lst = lst->next;
	}
	return (i);
}

long int	ft_atoi(const char *nptr)
{
	long int	res;
	int			i;
	int			sign;

	if (!nptr)
		return (0);
	sign = 1;
	i = 0;
	res = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1 + 0 * i++;
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '\0')
		return (res * sign);
	return (0);
}

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = (t_list *) malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->index = UINT_MAX;
	res->next = NULL;
	return (res);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
