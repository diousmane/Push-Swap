/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:20:48 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->top = NULL;
		stack->size = 0;
	}
	return (stack);
}

void	push(t_stack *stack, int value, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->value = value;
		new_node->index = index;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (stack)
	{
		current = stack->top;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(stack);
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		i = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}
