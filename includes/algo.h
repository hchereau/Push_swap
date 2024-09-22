/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:12:38 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 16:51:47 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

# define LIMIT_RATIO 200
# define RATIO 0.1
# define RATIO_BIG_LIST 0.04
# define SMALL_STACK 3

typedef struct s_list_number	t_list_number;

typedef enum e_stack_id {stack_a, stack_b}	t_stack_id;

typedef struct s_window
{
	size_t	min;
	size_t	max;
}	t_window;

typedef struct s_stacks
{
	t_list_number	*a;
	t_list_number	*b;
}	t_stacks;

void	sort_numbers(const t_list_number *list);
void	sorting_process(t_list_number *index, t_window *window);
long	*get_index_list(const long *list, const size_t size);
void	sort_small(long *stack, const size_t size, const t_stack_id stack_name);


// Operations

void	swap_a(long *stack);
void	swap_b(long *stack);
void	ss(long *stack_a, long *stack_b);
void	push_a(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b);
void	rotate_a(long *stack_a, size_t size_a);
void	rotate_b(long *stack_b, size_t size_b);
void	rr(long *stack_a, size_t size_a, long *stack_b, size_t size_b);
void	reverse_rotate_a(long *stack_a, size_t size_a);
void	reverse_rotate_b(long *stack_b, size_t size_b);
void	rrr(long *stack_a, size_t size_a, long *stack_b, size_t size_b);

#endif
