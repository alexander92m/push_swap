/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:25:34 by wadina            #+#    #+#             */
/*   Updated: 2021/09/26 00:26:12 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_arrs	*initS(int ac, char **av)
{
	t_arrs	*ars;

	ars = NULL;
	ars = malloc(sizeof(t_arrs));
	if (ars == NULL)
		return (NULL);
	init_arrA(ars, ac, av);
	ars->lenA = ac - 1;
	ars->lenB = 0;
	ars->cnt = 0;
	return (ars);
}

void	init_arrA(t_arrs *ars, int ac, char **av)
{
	int	size;

	size = ac;
	while (size-- > 1)
	{
		ars->a[size - 1] = ft_atoi(av[size]);
	}
}

int	checkSort(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (i < arrs->lenA - 1)
	{
		if (arrs->a[i] > arrs->a[i + 1])
		{
			if (i >= arrs->lenA - i - 1)
				return (-1);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		r;
	char	*s;
	t_arrs	*ars;
	int		i;

	ars = initS(ac, av);
	r = 1;
	if (errorCheck(ac, av, ars))
		err_exit();
	while (r > 0)
	{
		r = gnl(&s);
		if (s[0] != 0)
			parse_cms(ars, s);
		free(s);
	}
	i = 0;
	while (i < ars->cnt)
		init_cms(ars, i++);
	i = -1;
	if (!checkSort(ars))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
