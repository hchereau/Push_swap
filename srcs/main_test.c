/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:26:57 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/20 16:50:57 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static void	print_list(long *list, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("list[%zu] = %ld\n", i, list[i]);
		++i;
	}
}

void	test_get_numbers_list(int ac, char **av, long *res, size_t test_number)
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
		if (list.list[i] != res[i] && list.state == not_sorted)
		{
			printf("%zu : %sRED%s Error: list[%zu] is not a digit\n", test_number,
				RED, WHITE, i);
			printf("list[%zu] = %ld\n", i, list.list[i]);
			return ;
		}
		++i;
	}
	free(list.list);
}

static void	test_get_numbers_list_errors(int ac, char **av, size_t test_number)
{
	t_list_number	list;

	list = get_numbers_list(ac, av);
	if (list.state != error)
	{
		printf("%zu : %sRED%s Error: state is not %d\n", test_number, RED, WHITE, error);
		print_list(list.list, list.size);
		free(list.list);
	}
	else
	{
		printf("%zu : %sOK%s\n", test_number, GREEN, WHITE);
	}
}

int	main(void)
{
	char	**av;
	char	**av2;
	long	*res;
	char	**av3;

	res = malloc(sizeof(long) * 10);
	for (size_t i = 0; i < 10; ++i)
		res[i] = i + 1;
	printf("TEST_GET_NUMBERS_LIST\n");

	av = malloc(sizeof(char *) * 2);
	av[0] = malloc(sizeof(char) * (ft_strlen("test") + 1));
	bzero(av[0], ft_strlen("test") + 1);
	strcpy(av[0], "test");
	av[1] = malloc(sizeof(char) * (ft_strlen("1 2 3 4 5 6 7 8 9 10") + 1));
	bzero(av[1], ft_strlen("1 2 3 4 5 6 7 8 9 10") + 1);
	strcpy(av[1], "1 2 3 4 5 6 7 8 9 10");

	av2 = malloc(sizeof(char *) * 2);
	av2[0] = malloc(sizeof(char) * (ft_strlen("test") + 1));
	bzero(av2[0], ft_strlen("test") + 1);
	strcpy(av2[0], "test");
	av2[1] = malloc(sizeof(char) * (ft_strlen("1 a 3 4 5 6 7 8 9 10") + 1));
	bzero(av2[1], ft_strlen("1 a 3 4 5 6 7 8 9 10") + 1);
	strcpy(av2[1], "1 a 3 4 5 6 7 8 9 10");

	av3 = malloc(sizeof(char *) * 2);
	av3[0] = malloc(sizeof(char) * (ft_strlen("test") + 1));
	bzero(av3[0], ft_strlen("test") + 1);
	strcpy(av3[0], "test");
	av3[1] = malloc(sizeof(char) * (ft_strlen("1 2 3 4 5 2147483649 7 8 9 10 11") + 1));
	bzero(av3[1], ft_strlen("1 2 3 4 5 2147483649 7 8 9 10 11") + 1);
	strcpy(av3[1], "1 2 3 4 5 2147483649 7 8 9 10 11");

	test_get_numbers_list(2, av, res, 1);
	test_get_numbers_list_errors(1, av2, 2);
	test_get_numbers_list_errors(2, av2, 3);
	test_get_numbers_list_errors(2, av3, 4);
	free(res);
	free(av[1]);
	free(av[0]);
	free(av);
	free(av2[0]);
	free(av2[1]);
	free(av2);
	free(av3[0]);
	free(av3[1]);
	free(av3);
}
