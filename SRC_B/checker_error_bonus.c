/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wadina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:27:53 by wadina            #+#    #+#             */
/*   Updated: 2021/09/26 00:27:56 by wadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	err_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
