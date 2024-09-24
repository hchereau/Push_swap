/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:33:04 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 15:41:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	push_min_windows(t_stacks *stack, t_window *window)
{
	push_b(stack->a->list, &stack->a->size, stack->b->list, &stack->b->size);
	++stack->b->size;
	--stack->a->size;
	++window->min;
	++window->max;
	rotate_b(stack->b->list, stack->b->size);
}

void	push_in_window(t_stacks *stack, t_window *window)
{
	push_b(stack->a->list, &stack->a->size, stack->b->list, &stack->b->size);
	++stack->b->size;
	--stack->a->size;
	++window->min;
	++window->max;

}

static bool	is_in_window(const size_t number, const t_window *window)
{
	return (number >= window->min && number <= window->max);
}

void	sort_by_window(t_stacks *stack, t_window *window)
{
	while (stack->a->size > SMALL_STACK)
	{
		if (is_in_window(stack->a->list[0], window) == true)
		{
			push_in_window(stack, window);
		}
		else if ((size_t)(stack->a->list[0]) < window->min)
		{
			push_min_windows(stack, window);
		}
		else
		{
			if ((size_t)(stack->a->list[stack->a->size - 1]) <= window->max)
				reverse_rotate_a(stack->a->list, stack->a->size);
			else
				rotate_a(stack->a->list, stack->a->size);
		}
	}
}
