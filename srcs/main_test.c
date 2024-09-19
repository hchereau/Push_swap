/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:26:57 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/19 18:00:48 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	test_get_numbers_list(int ac, char **av, int *res, size_t test_number)
{
	t_list_number	list;
	size_t			i;

	list = get_numbers_list(ac, av);
	if (list.list == NULL)
	{
		printf("%zu : %sRED%s Error: list is NULL\n", test_number, RED, WHITE);
		return ;
	}
	i = 0;
	while (i < list.size - 1)
	{
		if (list.list[i] != res[i])
		{
			printf("%zu : %sRED%s Error: %c is not a digit\n", test_number,
				RED, WHITE, list.list[i]);
			return ;
		}
		++i;
	}
	printf("%zu : %sOK%s\n", test_number, GREEN, WHITE);
	i = 0;
	while (i < list.size)
	{
		printf("list[%zu] = %d\n", i, list.list[i]);
		++i;
	}
	free(list.list);
}

int	main(void)
{
	char	**av;
	int		*res;

	res = malloc(sizeof(int) * 10);
	for (size_t i = 0; i < 10; ++i)
		res[i] = i + 1;
	printf("TEST_GET_NUMBERS_LIST\n");
	av = malloc(sizeof(char *) * 2);
	av[0] = malloc(sizeof(char) * (ft_strlen("test") + 1));
	strcpy(av[0], "test");
	av[1] = malloc(sizeof(char) * (ft_strlen("1 2 3 4 5 6 7 8 9 10") + 1));
	strcpy(av[1], "1 2 3 4 5 6 7 8 9 10");
	test_get_numbers_list(2, av, res,1);
	free(res);
	free(av[1]);
	free(av[0]);
	free(av);
}
