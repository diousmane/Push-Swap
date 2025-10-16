/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:51 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack != NULL)
	{
		if (stack->size >= 2)
		{
			first = stack->top;
			second = stack->top->next;
			first->next = second->next;
			second->next = first;
			stack->top = second;
		}
		else
			return ;
	}
	else
		return ;
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
