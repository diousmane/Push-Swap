/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:38:47 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:31:36 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_max_bits(t_stack *a)
{
	int		max_bits;
	int		max_index;
	t_node	*tmp;

	tmp = a->top;
	max_index = 0;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	max_bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits && !is_sorted(a))
	{
		size = a->size;
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				(pb(a, b), ft_printf("pb\n"));
			else
				(ra(a), ft_printf("ra\n"));
			i++;
		}
		while (b->size > 0)
			(pa(a, b), ft_printf("pa\n"));
		bit++;
	}
}
