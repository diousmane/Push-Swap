/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:50 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack_a;

	stack_a = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (stack_a != NULL)
	{
		stack_a->top = NULL;
		stack_a->size = 0;
		return (stack_a);
	}
	else
		return (NULL);
}

void	push(t_stack *stack, int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node != NULL)
	{
		new_node->value = value;
		new_node->index = index;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
	}
	else
		return ;
}

int	pop(t_stack *stack)
{
	t_node	*node_remove;
	int		val;

	val = 0;
	if (stack != NULL && stack->top != NULL)
	{
		node_remove = stack->top;
		val = node_remove->value;
		stack->top = stack->top->next;
		stack->size--;
		free(node_remove);
		return (val);
	}
	else
		return (0);
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (stack != NULL && stack->top != NULL)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		node->next = NULL;
		return (node);
	}
	else
		return (NULL);
}
