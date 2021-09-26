/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:41:02 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 17:41:04 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotater(t_arrs *arrs)
{
	if (arrs->aRot > 0 && arrs->bRot > 0)
		dAdB(arrs);
	else if (arrs->aRot > 0 && arrs->bRot < 0)
		dAuB(arrs);
	else if (arrs->aRot < 0 && arrs->bRot < 0)
		uAuB(arrs);
	else if (arrs->aRot < 0 && arrs->bRot > 0)
		uAdB(arrs);
	else if (arrs->aRot > 0 && arrs->bRot == 0)
		dA0B(arrs);
	else if (arrs->aRot < 0 && arrs->bRot == 0)
	{
		rra(arrs);
		arrs->aRot++;
	}
	else if (arrs->aRot == 0 && arrs->bRot > 0)
	{
		rb(arrs);
		arrs->bRot--;
	}
	else if (arrs->aRot == 0 && arrs->bRot < 0)
	{
		rrb(arrs);
		arrs->bRot++;
	}
}

int	rotate(t_arrs *arrs)
{
	int	i;
	int	j;
	int	min;

	min = 100500;
	j = -1;
	while (++j < arrs->lenB)
	{
		i = -1;
		while (++i < arrs->lenA)
			if (arrs->b[j] > arrs->a[i] && arrs->b[j] < arrs->a[i + 1])
				break ;
		choose_opt(arrs, i, j, &min);
	}
	while (arrs->aRot != 0 || arrs->bRot != 0)
	{
		rotater(arrs);
	}
	return (0);
}
