/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:26:13 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:20:48 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	choose_sort_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->top->index > stack_a->top->next->index)
		{
			sa(stack_a);
			ft_printf("sa\n");
		}
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

static int	init_and_parse(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = init_stack();
	*b = init_stack();
	if (!*a || !*b)
		return (0);
	if (argc == 2)
	{
		if (!parse_single_arg(*a, argv[1]))
			return (0);
	}
	else
	{
		if (!parse_multiple_args(*a, argc, argv))
			return (0);
	}
	if (has_duplicates(*a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!init_and_parse(&stack_a, &stack_b, argc, argv))
	{
		print_error();
		if (stack_a)
			free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		return (1);
	}
	assign_indexes(stack_a);
	if (!is_sorted(stack_a))
		choose_sort_algorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
