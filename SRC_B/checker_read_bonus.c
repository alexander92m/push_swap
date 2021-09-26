/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:16 by wadina            #+#    #+#             */
/*   Updated: 2021/09/26 00:28:17 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	gnl(char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buf;

	rd = 1;
	i = 0;
	buf = malloc(10000);
	*line = buf;
	while (rd > 0)
	{
		rd = read(0, &ch, 1);
		if (ch == 10 && i == 0)
			err_exit();
		if (ch == '\n')
			break ;
		buf[i++] = ch;
	}
	buf[i] = 0;
	return (rd);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] != 0 && s2[i] != 0)
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			break ;
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
}

void	parse_cms(t_arrs *ars, char *s)
{
	if (ft_strncmp(s, "sa", 3) == 0)
		ars->cms[ars->cnt++] = 1;
	else if (ft_strncmp(s, "sb", 3) == 0)
		ars->cms[ars->cnt++] = 2;
	else if (ft_strncmp(s, "ss", 3) == 0)
		ars->cms[ars->cnt++] = 3;
	else if (ft_strncmp(s, "pa", 3) == 0)
		ars->cms[ars->cnt++] = 4;
	else if (ft_strncmp(s, "pb", 3) == 0)
		ars->cms[ars->cnt++] = 5;
	else if (ft_strncmp(s, "ra", 3) == 0)
		ars->cms[ars->cnt++] = 6;
	else if (ft_strncmp(s, "rb", 3) == 0)
		ars->cms[ars->cnt++] = 7;
	else if (ft_strncmp(s, "rr", 3) == 0)
		ars->cms[ars->cnt++] = 8;
	else if (ft_strncmp(s, "rra", 3) == 0)
		ars->cms[ars->cnt++] = 9;
	else if (ft_strncmp(s, "rrb", 3) == 0)
		ars->cms[ars->cnt++] = 10;
	else if (ft_strncmp(s, "rrr", 3) == 0)
		ars->cms[ars->cnt++] = 11;
	else
		err_exit();
}

void	init_cms(t_arrs *ars, int i)
{
	if (ars->cms[i] == 1)
		saB(ars);
	else if (ars->cms[i] == 2)
		sbB(ars);
	else if (ars->cms[i] == 3)
		ssB(ars);
	else if (ars->cms[i] == 4)
		paB(ars);
	else if (ars->cms[i] == 5)
		pbB(ars);
	else if (ars->cms[i] == 6)
		raB(ars);
	else if (ars->cms[i] == 7)
		rbB(ars);
	else if (ars->cms[i] == 8)
		rrB(ars);
	else if (ars->cms[i] == 9)
		rraB(ars);
	else if (ars->cms[i] == 10)
		rrbB(ars);
	else if (ars->cms[i] == 11)
		rrrB(ars);
}
