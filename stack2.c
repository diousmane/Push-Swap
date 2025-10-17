/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:20:48 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (stack && stack->top)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}
