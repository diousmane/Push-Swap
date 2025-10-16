/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:04:51 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (a != NULL && a->size > 1)
	{
		first = a->top;
		last = a->top;
		while (last->next != NULL)
			last = last->next;
		second = a->top->next;
		a->top = second;
		last->next = first;
		first->next = NULL;
	}
	else
		return ;
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (b != NULL && b->size > 1)
	{
		first = b->top;
		last = b->top;
		while (last->next != NULL)
			last = last->next;
		second = b->top->next;
		b->top = second;
		last->next = first;
		first->next = NULL;
	}
	else
		return ;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
