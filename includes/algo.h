/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:12:38 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 11:58:50 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

# define LIMIT_RATIO 200
# define RATIO 0.1
# define RATIO_BIG_LIST 0.04

typedef struct s_window
{
	size_t	start;
	size_t	end;
}	t_window;

void	sort_numbers(const t_list_number *list);
void	sorting_process(t_list_number *index, t_window *window);
long	*get_index_list(const long *list, const size_t size);

// Operations

void	swap_a(long *stack, const size_t size);
void	swap_b(long *stack, const size_t size);
void	push_a(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b);

#endif
