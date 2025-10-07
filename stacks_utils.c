/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousdiall <ousdiall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:05:08 by ousdiall          #+#    #+#             */
/*   Updated: 2025/10/07 13:19:23 by ousdiall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *init_stack(void)
{
	t_stack *stack_a ;

	stack_a = NULL ;
	stack_a = malloc(sizeof(t_stack));

	if(stack_a != NULL)
	{
		stack_a ->top = NULL;
		stack_a ->size = 0;
		return (stack_a);
	}
	else
		return NULL;

}
void push(t_stack *stack, int value, int index)
{
	t_node *new_node;
	new_node = malloc(sizeof(t_node));

	if(new_node != NULL)
	{
		new_node->value = value;
		new_node->index = index ;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
	}
	else
		return;
}
int pop(t_stack *stack)
{
	t_node *node_remove;
	int value;
	if(stack !=NULL)
	{
		if(stack->top != NULL)
		{
			node_remove = stack->top;
			value = node_remove->value;
			stack->top = stack->top->next;
			free(node_remove);
			stack->size--;
			return(value);
		}
		else
			return(-1);
	}
	else
		return(-1);
}
void	swap(t_stack *stack)
{
	if(stack != NULL)
	{
		if(stack->size >= 2)
		{
			t_node *first = stack->top;
			t_node *second = stack->top->next;

			first->next = second->next;
			second->next = first;
			stack->top = second;
		}
		else
			return;
	}
	else
		return;
}
void	sa(t_stack *a)
{
	swap(a);
}
void	sb(t_stack *b)
{
	swap(b);
}
void ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
t_node *pop_node(t_stack *stack)
{
	t_node *node;
	if(stack !=NULL)
	{
		if(stack->top != NULL)
		{
			node = stack->top;
			stack->top = stack->top->next;
			stack->size--;
			node->next = NULL;
			return(node);
		}
		else
			return(NULL);
	}
	else
		return(NULL);
}
void pa(t_stack *a, t_stack *b)
{

	t_node *node= pop_node(b);
	if(node)
	{
		push(a, node->value, node->index);
		free(node);
	}
}
void pb(t_stack *a, t_stack *b)
{
	t_node *node;

	node = pop_node(a);
	if(node)
	{
		push(b, node->value, node->index);
		free(node);
	}
}
void	ra(t_stack *a)
{
	t_node *first;
	t_node *second;
	t_node *last;
	if(a != NULL && a->size > 1)
	{
		first = a->top;
		last = a->top;
		while(last-> next != NULL)
			last = last->next;

		second = a->top->next;
		a->top = second;
		last->next = first;
		first->next = NULL;

	}
	else
		return;
}
void	rb(t_stack *b)
{
	t_node *first;
	t_node *second;
	t_node *last;
	if(b != NULL && b->size > 1)
	{
		first = b->top;
		last = b->top;
		while(last-> next != NULL)
			last = last->next;

		second = b->top->next;
		b->top = second;
		last->next = first;
		first->next = NULL;

	}
	else
		return;
}
void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
