/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:29:58 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:30:00 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initC(t_arrs *arrs)
{
	int	i;

	i = 0;
	while (i < arrs->lenA)
	{
		arrs->c[i] = arrs->a[i];
		i++;
	}
	arrs->lenC = arrs->lenA;
	sortBubblesC(arrs);
}

t_arrs	*initS(int argc, char **argv)
{
	t_arrs	*arrs;

	arrs = NULL;
	arrs = malloc(sizeof(t_arrs));
	if (arrs == NULL)
		return (NULL);
	arrs->argc = argc;
	while (argc-- > 1)
		arrs->a[argc - 1] = ft_atoi(argv[argc]);
	arrs->lenA = arrs->argc - 1;
	arrs->lenB = 0;
	argc = arrs->argc;
	while (argc--)
		arrs->b[argc] = 0;
	arrs->cnts = 0;
	arrs->maxA = maxA(arrs);
	arrs->minA = minA(arrs);
	initC(arrs);
	return (arrs);
}

int	main(int argc, char **argv)
{
	t_arrs	*arrs;
	int		i;

	arrs = NULL;
	i = 0;
	arrs = initS(argc, argv);
	if (errorCheck(argc, argv, arrs))
	{
		write(1, "Error\n", 6);
	}
	else if (argc != 1 && checkSort(arrs) != 0)
	{
		if (arrs->lenA > 5)
			sort(arrs);
		else
			Sort5(arrs);
	}
	i = 0;
	free(arrs);
	arrs = NULL;
	return (0);
}
