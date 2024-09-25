/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_biggest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:18:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/25 15:11:30 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

size_t	get_biggest_index(long *list, size_t size)
{
	size_t	i;
	size_t	i_biggest;

	i = 1;
	i_biggest = 0;
	while (i < size)
	{
		if (list[i] > list[i_biggest])
		{
			i_biggest = i;
		}
		++i;
	}
	return (i_biggest);
}

static void	set_new_top_list_b(t_list_number *stack, size_t i_new_top)
{
	if (i_new_top < stack->size / 2)
	{
		while (i_new_top > 0)
		{
			rotate_b(stack->list, stack->size);
			--i_new_top;
		}
	}
	else
	{
		while (i_new_top < stack->size && i_new_top > 0)
		{
			reverse_rotate_b(stack->list, stack->size);
			++i_new_top;
		}
		if (i_new_top == stack->size - 1)
		{
			reverse_rotate_b(stack->list, stack->size);
			i_new_top = 0;
		}
	}
}

static void	set_new_top_list_a(t_list_number *stack, size_t i_new_top)
{
	if (i_new_top < stack->size / 2)
	{
		while (i_new_top > 0)
		{
			rotate_a(stack->list, stack->size);
			--i_new_top;
		}
	}
	else
	{
		while (i_new_top < stack->size && i_new_top > 0)
		{
			reverse_rotate_a(stack->list, stack->size);
			++i_new_top;
		}
		if (i_new_top == stack->size - 1)
		{
			reverse_rotate_a(stack->list, stack->size);
			i_new_top = 0;
		}
	}
}

static size_t	get_best_place_index(t_list_number *a, long nb)
{
	size_t	i;
	size_t	i_best;

	i = 1;
	i_best = 0;
	while (i < a->size)
	{
		if (a->list[i] > nb)
		{
			if (a->list[i] < a->list[i_best])
				i_best = i;
			else if (a->list[i_best] < nb)
				i_best = i;
		}
		++i;
	}
	if (a->list[i_best] < nb)
	{
		i_best = a->size - 1;
	}
	return (i_best);
}

static void	setup_stack_for_pop(t_list_number *a, long nb)
{
	size_t	i;

	i = get_best_place_index(a, nb);
	set_new_top_list_a(a, i);
}

void	sort_by_biggest(t_stacks *stack)
{
	size_t	i_biggest;

	while (stack->b->size > 0)
	{
		// print_list(stack->a->list, stack->a->size);
		// print_list(stack->b->list, stack->b->size);
		i_biggest = get_biggest_index(stack->b->list, stack->b->size);
		// printf("stack->b->size = %ld\n", stack->b->size);
		// printf("i_biggest = %ld\n", i_biggest);
		// printf("biggest = %ld\n", stack->b->list[i_biggest]);
		set_new_top_list_b(stack->b, i_biggest);
		// printf("biggest = %ld\n", stack->b->list[i_biggest]);
		setup_stack_for_pop(stack->a, stack->b->list[0]);
		push_a(stack->a->list, &stack->a->size,
			stack->b->list, &stack->b->size);
	}
}
