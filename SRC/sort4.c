/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:50:36 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 15:50:38 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dAdB(t_arrs *arrs)
{
	rr(arrs);
	arrs->aRot--;
	arrs->bRot--;
}

void	dAuB(t_arrs *arrs)
{
	ra(arrs);
	rrb(arrs);
	arrs->aRot--;
	arrs->bRot++;
}

void	uAuB(t_arrs *arrs)
{
	rrr(arrs);
	arrs->aRot++;
	arrs->bRot++;
}

void	uAdB(t_arrs *arrs)
{
	rra(arrs);
	rb(arrs);
	arrs->aRot++;
	arrs->bRot--;
}

void	dA0B(t_arrs *arrs)
{
	ra(arrs);
	arrs->aRot--;
}
