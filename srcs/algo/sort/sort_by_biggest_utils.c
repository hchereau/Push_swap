/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_biggest_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:14:29 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/25 17:16:49 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	set_new_top_list_a(t_list_number *stack, size_t i_new_top)
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

void	set_new_top_list_b(t_list_number *stack, size_t i_new_top)
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
