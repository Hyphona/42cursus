/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:04:02 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/22 10:03:53 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	long			nb;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	add_node(t_stack **s, t_stack *new);
void	butterfly(t_stack **s_a, t_stack **s_b, int size);
int		check_args(char **av);
t_stack	*create_node(long nb);
void	five_sort(t_stack **s_a, t_stack **s_b);
void	free_stack(t_stack *s);
long	ft_atoi(const char *str, t_stack **s);
char	*ft_joinchar(char *s1, char const s2);
int		get_max(t_stack *s, int max);
int		has_space(char *str);
int		is_empty(char *str);
int		is_sorted(t_stack *s);
int		is_space(char c);
t_stack	*get_last(t_stack *s);
t_stack	*parse(char **av, t_stack **s_a);
void	push_a(t_stack **s_a, t_stack **s_b);
void	push_b(t_stack **s_a, t_stack **s_b);
void	rev_rotate_a(t_stack **s);
void	rev_rotate_b(t_stack **s);
void	rev_rotate_r(t_stack **s_a, t_stack **s_b);
void	rotate_a(t_stack **s);
void	rotate_b(t_stack **s);
void	rotate_r(t_stack **s_a, t_stack **s_b);
void	set_index(t_stack *s);
void	sort(t_stack **s_a, t_stack **s_b);
void	sort_selector(t_stack **s_a, t_stack **s_b);
int		stack_size(t_stack *s);
void	swap_a(t_stack **s);
void	swap_b(t_stack **s);
void	swap_s(t_stack **s_a, t_stack **s_b);
void	three_sort(t_stack **s);

#endif