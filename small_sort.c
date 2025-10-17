/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:31:36 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->index;
	s = a->top->next->index;
	t = a->top->next->next->index;
	if (f > s && s < t && f < t)
		(sa(a), ft_printf("sa\n"));
	else if (f > s && s > t)
		(sa(a), ft_printf("sa\n"), rra(a), ft_printf("rra\n"));
	else if (f > s && s < t && f > t)
		(ra(a), ft_printf("ra\n"));
	else if (f < s && s > t && f < t)
		(sa(a), ft_printf("sa\n"), ra(a), ft_printf("ra\n"));
	else if (f < s && s > t && f > t)
		(rra(a), ft_printf("rra\n"));
}

static int	find_min_index(t_stack *a)
{
	t_node	*tmp;
	int		min;

	tmp = a->top;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

static void	rotate_min_to_top(t_stack *a, int min)
{
	t_node	*tmp;
	int		pos;

	tmp = a->top;
	pos = 0;
	while (tmp && tmp->index != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= a->size / 2)
		while (a->top->index != min)
			(ra(a), ft_printf("ra\n"));
	else
		while (a->top->index != min)
			(rra(a), ft_printf("rra\n"));
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min;

	while (a->size > 3)
	{
		min = find_min_index(a);
		rotate_min_to_top(a, min);
		(pb(a, b), ft_printf("pb\n"));
	}
	sort_three(a);
	while (b->size > 0)
		(pa(a, b), ft_printf("pa\n"));
}
