/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:26:39 by wadina            #+#    #+#             */
/*   Updated: 2021/09/25 14:26:42 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_arrs
{
	int		a[1000];
	int		lenA;
	int		b[1000];
	int		lenB;
	int		cms[10000];
	int		cnt;
}				t_arrs;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		saB(t_arrs *arrs);
int		sbB(t_arrs *arrs);
int		ssB(t_arrs *arrs);
int		pbB(t_arrs *arrs);
int		paB(t_arrs *arrs);
int		raB(t_arrs *arrs);
int		rbB(t_arrs *arrs);
int		rrB(t_arrs *arrs);
int		rraB(t_arrs *arrs);
int		rrbB(t_arrs *arrs);
int		rrrB(t_arrs *arrs);
int		checkSort(t_arrs *arrs);
int		errorCheck(int argc, char **argv, t_arrs *arrs);
int		ft_rangeInt(char *s);
int		ft_isminus(int c);
t_arrs	*initS(int argc, char **argv);
void	init_arrA(t_arrs *ars, int ac, char **av);
void	parse_cms(t_arrs *ars, char *s);
void	init_cms(t_arrs *ars, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	err_exit(void);
int		gnl(char **line);

#endif
