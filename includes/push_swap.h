/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:24:34 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/19 15:55:53 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"


# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

typedef enum e_list_state{error = -1, not_sorted, sorted}	t_list_state;
typedef enum e_number_state{valid_number, unvalid_number}	t_number;

typedef struct s_list_number
{
	int				*list;
	size_t			size;
	t_list_state	state;
}	t_list_number;

// parsing/

t_list_number	get_numbers_list(int ac, char **av);

#endif
