/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:26:13 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/08 11:04:39 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_stack *stack_a;
	t_stack *stack_b;

	i = 0;
	if(argc > 1)
	{
		stack_a = init_stack();
		stack_b = init_stack();

		if(argc == 2)
		{
			char **split_args;
			split_args = ft_split(argv[1], ' ');

			int count = 0;
			while(split_args[count] != NULL)
				count++;

			i = count - 1;
			while(i >= 0)
			{
				int value = ft_atoi(split_args[i]);
				push(stack_a, value, 0);
				i--;
			}
		}
		else
		{
			i = argc - 1;
			while(i >= 1)
			{
				int value = ft_atoi(argv[i]);
				push(stack_a, value, 0);
				i--;
			}
		}

		// Logique de tri commune
		assign_indexes(stack_a);
		if (!is_sorted(stack_a))
			radix_sort(stack_a, stack_b);

		// Libération mémoire
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
