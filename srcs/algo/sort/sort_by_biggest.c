/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_biggest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:18:27 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/25 17:16:45 by hucherea         ###   ########.fr       */
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
		i_biggest = get_biggest_index(stack->b->list, stack->b->size);
		set_new_top_list_b(stack->b, i_biggest);
		setup_stack_for_pop(stack->a, stack->b->list[0]);
		push_a(stack->a->list, &stack->a->size,
			stack->b->list, &stack->b->size);
	}
}
