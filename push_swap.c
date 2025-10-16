/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:26:13 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/16 13:10:56 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_single_arg(t_stack *stack_a, char *arg)
{
	char	**split_args;
	int		count;
	int		i;
	int		value;

	split_args = ft_split(arg, ' ');
	count = 0;
	while (split_args[count] != NULL)
		count++;
	i = count - 1;
	while (i >= 0)
	{
		value = ft_atoi(split_args[i]);
		push(stack_a, value, 0);
		i--;
	}
	i = 0;
	while (split_args[i] != NULL)
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	handle_multiple_args(t_stack *stack_a, int argc, char **argv)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i >= 1)
	{
		value = ft_atoi(argv[i]);
		push(stack_a, value, 0);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (argc == 2)
		handle_single_arg(stack_a, argv[1]);
	else
		handle_multiple_args(stack_a, argc, argv);
	assign_indexes(stack_a);
	if (!is_sorted(stack_a))
		radix_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		i;

	if (stack != NULL && stack->top != NULL)
	{
		current = stack->top;
		while (current != NULL)
		{
			i = 0;
			compare = stack->top;
			while (compare != NULL)
			{
				if (compare->value < current->value)
					i++;
				compare = compare->next;
			}
			current->index = i;
			current = current->next;
		}
	}
	else
		return ;
}
