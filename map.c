/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:20:23 by abayar            #+#    #+#             */
/*   Updated: 2022/01/05 15:02:29 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_data *data, char *s)
{
	char	p;
	int		l;

	l = 0;
	data->lmap = 0;
	data->fd = open(s, O_RDWR);
	while (!(read(data->fd, &p, 1) == 0))
	{
		if (p == '\n')
		data->lmap++;
	}
	data->lmap++;
	data->s = malloc(sizeof(char *) * (data->lmap + 1));
	if (!(data->s))
		return (NULL);
	close(data->fd);
	data->fd = open(s, O_RDWR);
	while (l < data->lmap)
	{
		data->s[l] = get_next_line(data->fd);
		l++;
	}
	data->cmap = ft_strlen(data->s[1]) - 1;
	data->s[l] = 0;
	return (data->s);
}

void	help_pars(char **s, t_data *data, int i, int j)
{
	if (s[i][j] == 'P')
		draw_img(data, data->path);
	else if (s[i][j] == '1')
		draw_img(data, data->paths);
	else if (s[i][j] == 'C')
		draw_img(data, data->pathc);
	else if (s[i][j] == 'E')
	{
		if (data->indexc2 == -1)
			draw_img(data, data->pathee);
		else
			draw_img(data, data->pathe);
	}
}

void	pars_map(char **s, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->yi = 0;
	while (s[i])
	{	
		j = 0;
		data->xi = 0;
		while (s[i][j])
		{
			help_pars(s, data, i, j);
			j++;
			data->xi += 100;
		}
		data->yi += 100;
		i++;
	}
}

void	help_pos(t_data *data, char c, int i, int j)
{
	while (data->s[i])
	{
		if (ft_strchr(data->s[i], c) != -1)
		{
			j = ft_strchr(data->s[i], c);
			return ;
		}
		i++;
	}
	if (c == 'C')
		data->indexc2 = -1;
	else if (c == 'E')
		data->indexc = -1;
}

void	main_pos(t_data *data, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c == 'P')
	{
		data->index = 1;
		data->index2 = 0;
		while (data->s[data->index])
		{
			if (ft_strchr(data->s[data->index], c) != -1)
			{
				data->index2 = ft_strchr(data->s[data->index], c);
				return ;
			}
			data->index++;
		}
	}
	else
	{
		help_pos(data, c, i, j);
	}
}
