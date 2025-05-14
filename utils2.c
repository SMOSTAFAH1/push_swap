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

char	*extract_line_from_stash(char *stash, int bytes_read)
{
	char	*res;
	int		tam;
	int		i;

	if (!stash)
		return (NULL);
	if (bytes_read)
		tam = ft_strchr(stash, '\n') - stash + 1;
	else
		tam = ft_strlen(stash);
	if (ft_strlen(stash) == 0)
		return (NULL);
	res = (char *) malloc(tam + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < tam)
	{
		res[i] = *stash;
		i++;
		stash++;
	}
	res[tam] = '\0';
	return (res);
}

char	*delete_line_from_stash(char *stash, int bytes_read)
{
	char	*res;
	char	*remnants;
	int		tam;

	if (!stash)
		return (NULL);
	if (bytes_read)
		remnants = ft_strchr(stash, '\n') + 1;
	else
		remnants = stash;
	tam = ft_strlen(remnants);
	if (tam == 0)
	{
		free(stash);
		return (NULL);
	}
	res = (char *) malloc(tam + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, remnants, tam + 1);
	free(stash);
	return (res);
}

int	read_into_buffer(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	return (bytes_read);
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
