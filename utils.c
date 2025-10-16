/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:51 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*peek(t_stack *stack)
{
	t_node	*top;

	if (stack != NULL)
	{
		top = stack->top;
		return (top);
	}
	return (NULL);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (stack != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(stack);
	}
	else
		return ;
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack != NULL && stack->top != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			ft_printf("%d", current->value);
			current = current->next;
		}
		ft_printf("\n");
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack != NULL && stack->size > 1)
	{
		current = stack->top;
		while (current->next != NULL)
		{
			if (current->value > current->next->value)
				return (0);
			current = current->next;
		}
		return (1);
	}
	else
		return (1);
}
