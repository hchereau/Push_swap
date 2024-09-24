/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:49:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 17:08:51 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "parsing.h"
# include "algo.h"

typedef enum e_list_state{error = -1, not_sorted, sorted}	t_list_state;

typedef struct s_list_number
{
	long			*list;
	size_t			size;
	t_list_state	state;
}	t_list_number;

t_list_state	is_sorted(const long *stack, size_t size);
void			free_list(t_list_number *list);
void			print_list(const long *list, const size_t size);

#endif
