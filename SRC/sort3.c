/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:00:35 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 15:00:37 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_arrs *arrs)
{
	pushB(arrs);
	while (arrs->lenA != 3)
	{
		if (arrs->a[0] > arrs->midA && arrs->a[0] < arrs->maxA)
			pb(arrs);
		else
			ra(arrs);
	}
	if (semiSort(arrs) != 0)
		sa(arrs);
	while (arrs->lenB > 0)
	{
		if (arrs->b[0] < arrs->a[0] && arrs->b[0] > arrs->a[arrs->lenA - 1])
			pa(arrs);
		else
			rotate(arrs);
	}
	while (checkSort(arrs) != 0)
	{
		if (checkSort(arrs) == 1)
			ra(arrs);
		else
			rra(arrs);
	}
	return (0);
}

void	pushA(t_arrs *arrs)
{
	while (arrs->lenB > 0)
	{	
		arrs->minAl = minA(arrs);
		arrs->maxAl = maxA(arrs);
		if (arrs->b[0] < arrs->a[0])
		{
			if (arrs->b[0] < arrs->minAl && arrs->a[0] == arrs->minAl)
				pa(arrs);
			else if (arrs->b[0] > arrs->a[arrs->lenA - 1])
				pa(arrs);
			else
				ra(arrs);
		}
		else if (arrs->b[0] > arrs->maxAl && arrs->a[0] == arrs->minAl)
		{
			pa(arrs);
		}
		else
			ra(arrs);
	}
}

int	Sort5(t_arrs *arrs)
{
	while (arrs->lenA > 3)
		pb(arrs);
	if (semiSort(arrs) != 0)
		sa(arrs);
	pushA(arrs);
	while (checkSort(arrs) != 0)
	{
		if (checkSort(arrs) == 1)
			ra(arrs);
		else
			rra(arrs);
	}
	return (0);
}

void	choose_opt1(t_arrs *arrs, int i, int j, int *min)
{
	*min = i + arrs->lenB - j;
	arrs->bRot = j - arrs->lenB;
	if (arrs->lenB < 3)
		arrs->bRot = arrs->bRot + 3;
	arrs->aRot = i + 1;
}

void	choose_opt(t_arrs *arrs, int i, int j, int *min)
{
	if (i < arrs->lenA - i && j < arrs->lenB - j && i + j < *min)
	{
		*min = i + j;
		arrs->bRot = j;
		arrs->aRot = i + 1;
	}
	else if (i < arrs->lenA - i && j > arrs->lenB - j && i
		+ arrs->lenB - j < *min)
		choose_opt1(arrs, i, j, min);
	else if (i >= arrs->lenA - i && j > arrs->lenB - j && arrs->lenA - i
		+ arrs->lenB - j < *min)
	{
		*min = arrs->lenA - i + arrs->lenB - j;
		arrs->bRot = j - arrs->lenB;
		arrs->aRot = i - arrs->lenA + 1;
	}
	else if (i >= arrs->lenA - i && j < arrs->lenB - j && arrs->lenA - i
		+ j < *min)
	{
		*min = arrs->lenA - i + j;
		arrs->bRot = j;
		arrs->aRot = i - arrs->lenA + 1;
	}
}
