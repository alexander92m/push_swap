/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:30:55 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:30:56 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortBubblesC(t_arrs *arrs)
{
	int	*a;
	int	i;
	int	j;
	int	temp;

	j = arrs->lenC - 1;
	a = arrs->c;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
			i++;
		}
		j--;
	}
	arrs->midA = arrs->c[arrs->lenC / 2];
	return (0);
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

int	ft_isminus(int c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	ft_rangeInt(char *s)
{
	int	i;

	i = -1;
	if (ft_strlen(s) == 11 && ft_isminus(s[0]) == 1)
	{
		while (s[++i])
			if (s[i] > "-2147483648"[i])
				return (0);
	}
	else if (ft_strlen(s) < 10 || (ft_strlen(s) == 10 && ft_isminus(s[0]) == 1))
		return (1);
	else if (ft_strlen(s) == 10 && ft_isminus(s[0]) == 0)
	{
		while (s[++i])
			if (s[i] > "2147483647"[i])
				return (0);
	}
	else if (ft_strlen(s) > 10)
		return (0);
	return (1);
}

/* its int? in range int? is doubles? if norm -> return 0 */
int	errorCheck(int argc, char **argv, t_arrs *arrs)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j]) || ft_isminus(argv[i][j])))
				return (1);
		if (!ft_rangeInt(argv[i++]))
			return (1);
		j = -1;
		while (++j < arrs->lenA)
		{
			k = -1;
			while (++k < arrs->lenA)
				if (arrs->a[j] == arrs->a[k] && j != k)
					return (1);
		}
	}
	return (0);
}
