/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shashemi <shashemi@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-14 15:55:25 by shashemi          #+#    #+#             */
/*   Updated: 2025-05-14 15:55:25 by shashemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	int					content;
	unsigned int		index;
	struct s_list		*next;
}	t_list;

t_list			*parse_numbers(int argc, char **argv);
t_list			*ft_lstclone_and_delete_last(t_list **stack, t_list *node);
int				has_repeated(t_list **stack);
int				ft_sqrt(int nb);
void			*free_matrix(char **matrix);
int				print_error(void);
void			swap(t_list **stack, char name, int output);
void			push(t_list **from, t_list **to, char to_name, int output);
void			rotate(t_list **stack, char name, int output);
void			reverse_rotate(t_list **stack, char name, int output);
void			double_move(t_list **stack_a, t_list **stack_b, int output,
					char move);
int				*list_to_array(t_list *list);
void			insertion_sort(int *array, int size);
void			indexer(t_list *stack, int *array, int size);
void			sort_stack(t_list **stack_a, t_list **stack_b,
					unsigned int size);
void			ksort_range_in_b(t_list **stack_a, t_list **stack_b,
					unsigned int size);
void			ksort_back_to_a(t_list **stack_a, t_list **stack_b,
					unsigned int size);
int				count_rotations(t_list **stack, unsigned int index);
int				is_sorted(t_list **stack);
int				ft_strlen(const char *s);
void			copy_string_from_index(const char *src, char *dst, int i);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				count_words(char const *s, char c);
long int		ft_atoi(const char *nptr);
t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst);
int				ft_lstsize(t_list *lst);
char			*ft_strchr(const char *s, int c);
char			*extract_line_from_stash(char *stash, int bytes_read);
char			*delete_line_from_stash(char *stash, int bytes_read);
int				read_into_buffer(int fd, char *buffer);

#endif
