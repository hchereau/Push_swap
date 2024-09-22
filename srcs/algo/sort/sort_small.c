/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:16:52 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 16:37:47 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	sort_two_a(long *stack)
{
	if (stack[0] > stack[1])
		swap_a(stack);
}

static void	sort_two_b(long *stack)
{
	if (stack[0] > stack[1])
		swap_b(stack);
}

static void	sort_three_a(long *stack)
{
	if (stack[0] > stack[1] && stack[1] > stack[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack, 3);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
	{
		rotate_a(stack, 3);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
	{
		swap_a(stack);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
	{
		reverse_rotate_a(stack, 3);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		swap_a(stack);
		rotate_a(stack, 3);
	}
}

static void	sort_three_b(long *stack)
{
	if (stack[0] < stack[1] && stack[1] < stack[2])
	{
		swap_b(stack);
		reverse_rotate_b(stack, 3);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] < stack[2])
	{
		rotate_b(stack, 3);
	}
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[0] > stack[2])
	{
		swap_b(stack);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] < stack[2])
	{
		reverse_rotate_b(stack, 3);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[0] > stack[2])
	{
		swap_b(stack);
		rotate_b(stack, 3);
	}
}

void	sort_small(long *stack, const size_t size, const t_stack_id stack_name)
{
	if (size == 2)
	{
		if (stack_name == stack_a)
		{
			sort_two_a(stack);
		}
		else
		{
			sort_two_b(stack);
		}
	}
	else if (size == 3)
	{
		if (stack_name == stack_a)
		{
			sort_three_a(stack);
		}
		else
		{
			sort_three_b(stack);
		}
	}
}
