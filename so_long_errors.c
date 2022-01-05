/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:10:08 by abayar            #+#    #+#             */
/*   Updated: 2022/01/05 17:16:45 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_other_char(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '0' && s[i][j] != '1' && s[i][j] != 'E' && \
				s[i][j] != 'C' && s[i][j] != 'P' && s[i][j] != '\n')
			{
				printf("Error\nThere is invalid char in the map\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	check_size_map(t_data *data, char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((ft_strlen(s[i]) != ft_strlen(s[0])) && i < data->lmap - 1)
		{
			printf("Error\ninvalide map a sat!!\n");
			exit (0);
		}
		i++;
	}
	return (0);
}

int	check_p(char *s)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] == 'P')
			t++;
		i++;
	}
	return (t);
}

void	help_check_char(int p, int c, int e)
{
	if (p != 1 || c == 0 || e == 0)
	{
		printf("Error\nchihaja mahiyach hh\n");
		exit (0);
	}
}

int	check_char(char **s)
{
	int	i;
	int	c;
	int	p;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (s[i])
	{
		if (check_p(s[i]) > 1)
			p += 2;
		if (ft_strchr(s[i], 'P') != -1)
			p += 1;
		if (ft_strchr(s[i], 'C') != -1)
			c += 1;
		if (ft_strchr(s[i], 'E') != -1)
			e += 1;
		i++;
	}
	help_check_char(p, c, e);
	check_other_char(s);
	return (0);
}
