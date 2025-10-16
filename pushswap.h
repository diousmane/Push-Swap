/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:41:17 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:56 by ousdiall         ###   ########.fr       */
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
void	handle_single_arg(t_stack *stack_a, char *arg);
void	handle_multiple_args(t_stack *stack_a, int argc, char **argv);
int		get_max_bits(t_stack *stack);
void	print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
