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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *)s)[i] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			tam;
	unsigned char	*res;

	tam = size * count;
	res = malloc((int)tam);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, tam);
	return (res);
}
