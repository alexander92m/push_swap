/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_func1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:47:29 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:47:32 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	saB(t_arrs *arrs)
{
	int	temp;

	if (arrs->lenA > 1)
	{
		temp = arrs->a[0];
		arrs->a[0] = arrs->a[1];
		arrs->a[1] = temp;
	}
	return (0);
}

int	sbB(t_arrs *arrs)
{
	int	temp;

	if (arrs->lenB > 1)
	{
		temp = arrs->b[0];
		arrs->b[0] = arrs->b[1];
		arrs->b[1] = temp;
		return (0);
	}
	else
		return (-1);
}

int	ssB(t_arrs *arrs)
{
	int	resA;
	int	resB;

	resA = saB(arrs);
	resB = sbB(arrs);
	if (resA == -1 || resB == -1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

int	pbB(t_arrs *arrs)
{
	int	i;

	if (arrs->lenA < 1)
		return (-1);
	i = arrs->lenB - 1;
	while (i > -1)
	{
		arrs->b[i + 1] = arrs->b[i];
		i--;
	}
	arrs->b[0] = arrs->a[0];
	arrs->lenB++;
	i = 0;
	while (i < arrs->lenA - 1)
	{
		arrs->a[i] = arrs->a[i + 1];
		i++;
	}
	arrs->lenA--;
	return (0);
}

int	paB(t_arrs *arrs)
{
	int	i;

	if (arrs->lenB > 0)
	{
		if (arrs->lenB == 0)
			return (-1);
		i = arrs->lenA - 1;
		while (i > -1)
		{
			arrs->a[i + 1] = arrs->a[i];
			i--;
		}
		arrs->a[0] = arrs->b[0];
		arrs->lenA++;
		i = -1;
		while (++i < arrs->lenB - 1)
			arrs->b[i] = arrs->b[i + 1];
		arrs->lenB--;
		return (0);
	}
	return (-1);
}
