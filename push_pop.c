/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:40:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:51 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop_node(b);
	if (node != NULL)
	{
		node->next = a->top;
		a->top = node;
		a->size++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = pop_node(a);
	if (node != NULL)
	{
		node->next = b->top;
		b->top = node;
		b->size++;
	}
}
