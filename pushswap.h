/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:41:17 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:43:27 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*init_stack(void);
void	push(t_stack *stack, int value, int index);
int		pop(t_stack *stack);
t_node	*pop_node(t_stack *stack);
t_node	*peek(t_stack *stack);
void	free_stack(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);
void	assign_indexes(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	print_error(void);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
int		parse_single_arg(t_stack *stack_a, char *arg);
int		parse_multiple_args(t_stack *stack_a, int argc, char **argv);

#endif
