/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousou <ousou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:00 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/17 08:43:27 by ousou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>

void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	is_valid_number(char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	i = (str[0] == '-' || str[0] == '+');
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	if (sign * num > INT_MAX || sign * num < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	parse_single_arg(t_stack *stack_a, char *arg)
{
	char	**args;
	int		i;
	int		j;

	args = ft_split(arg, ' ');
	if (!args)
		return (0);
	i = 0;
	while (args[i] && is_valid_number(args[i]))
		i++;
	if (args[i])
	{
		j = 0;
		while (args[j])
			free(args[j++]);
		return (free(args), 0);
	}
	while (--i >= 0)
		push(stack_a, ft_atoi(args[i]), 0);
	j = 0;
	while (args[j])
		free(args[j++]);
	return (free(args), 1);
}

int	parse_multiple_args(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	while (--i >= 1)
		push(stack_a, ft_atoi(argv[i]), 0);
	return (1);
}
