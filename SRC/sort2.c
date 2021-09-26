/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:58:06 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:58:08 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxA(t_arrs *arrs)
{
	int	i;
	int	max;
	int	iMax;

	iMax = -1;
	max = -2147483648;
	i = 0;
	while (i < arrs->lenA)
	{
		if (arrs->a[i] > max)
		{
			max = arrs->a[i];
			iMax = i;
		}
		i++;
	}
	return (max);
}

int	minA(t_arrs *arrs)
{
	int	i;
	int	min;
	int	iMin;

	iMin = -1;
	min = 2147483647;
	i = 0;
	while (i < arrs->lenA)
	{
		if (arrs->a[i] < min)
		{
			min = arrs->a[i];
			iMin = i;
		}
		i++;
	}
	return (min);
}

int	semiSort(t_arrs *arrs)
{
	int	i;

	arrs->minAl = minA(arrs);
	arrs->maxAl = maxA(arrs);
	i = 0;
	while (i < arrs->lenA - 1)
	{
		if (arrs->a[i] == arrs->maxAl && arrs->a[i + 1] == arrs->minAl)
		{
		}
		else if (arrs->a[i] > arrs->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	done1(t_arrs *arrs)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (!flag && ++i < arrs->lenA)
	{
		if (arrs->a[i] > arrs->minA && arrs->a[i] < arrs->midA)
		{
			flag = 1;
			break ;
		}
	}
	return (flag);
}

void	pushB(t_arrs *arrs)
{
	while (done1(arrs))
	{
		if (arrs->a[0] > arrs->minA && arrs->a[0] < arrs->midA)
			pb(arrs);
		else
			ra(arrs);
	}
}
