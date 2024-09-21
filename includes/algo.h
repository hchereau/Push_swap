/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:12:38 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/21 17:57:02 by hucherea         ###   ########.fr       */
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

#endif
