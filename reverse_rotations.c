/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:51 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack *a)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (a != NULL && a->size > 1)
	{
		first = a->top;
		last = a->top;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = first;
		second_last->next = NULL;
		a->top = last;
	}
}

void	rrb(t_stack *b)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (b != NULL && b->size > 1)
	{
		first = b->top;
		last = b->top;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = first;
		second_last->next = NULL;
		b->top = last;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
