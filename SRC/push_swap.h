/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:26:39 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:26:42 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_arrs
{
	int		a[10000000];
	int		lenA;
	int		argc;
	int		b[10000000];
	int		c[10000000];
	int		lenB;
	int		lenC;
	int		cnts;
	int		bRot;
	int		aRot;
	int		maxA;
	int		minA;
	int		midA;
	int		minAl;
	int		maxAl;
}				t_arrs;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		sa(t_arrs *arrs);
int		sb(t_arrs *arrs);
int		ss(t_arrs *arrs);
int		pb(t_arrs *arrs);
int		pa(t_arrs *arrs);
int		ra(t_arrs *arrs);
int		rb(t_arrs *arrs);
int		rr(t_arrs *arrs);
int		rra(t_arrs *arrs);
int		rrb(t_arrs *arrs);
int		rrr(t_arrs *arrs);
int		sort(t_arrs *arrs);
int		checkSort(t_arrs *arrs);
int		semiSort(t_arrs *arrs);
int		sortBubblesC(t_arrs *arrs);
int		rotate(t_arrs *arrs);
int		maxA(t_arrs *arrs);
int		maxB(t_arrs *arrs);
int		minA(t_arrs *arrs);
int		minB(t_arrs *arrs);
int		midA(t_arrs *arrs);
int		done1(t_arrs *arrs);
int		Sort5(t_arrs *arrs);
int		errorCheck(int argc, char **argv, t_arrs *arrs);
int		ft_rangeInt(char *s);
int		ft_isminus(int c);
void	pushA(t_arrs *arrs);
void	pushB(t_arrs *arrs);
void	choose_opt(t_arrs *arrs, int i, int j, int *min);
void	choose_opt1(t_arrs *arrs, int i, int j, int *min);
void	dAdB(t_arrs *arrs);
void	dAuB(t_arrs *arrs);
void	uAuB(t_arrs *arrs);
void	uAdB(t_arrs *arrs);
void	dA0B(t_arrs *arrs);
void	rotater(t_arrs *arrs);
t_arrs	*initS(int argc, char **argv);
void	initC(t_arrs *arrs);

#endif
