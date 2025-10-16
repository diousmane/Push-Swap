/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:38:47 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:56 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_max_bits(t_stack *stack)
{
	int		max_index;
	int		bits;
	t_node	*current;

	max_index = 0;
	current = stack->top;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

void	process_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			pb(a, b);
			ft_printf("pb\n");
		}
		i++;
	}
	while (b->size > 0)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit);
		bit++;
	}
}
