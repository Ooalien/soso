/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:06:32 by abayar            #+#    #+#             */
/*   Updated: 2022/01/05 17:17:38 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_path(t_data *img)
{
	img->path = "./rsz_main.xpm";
	img->paths = "./rsz_stone.xpm";
	img->pathc = "./rsz_pizza.xpm";
	img->pathe = "./bab.xpm";
	img->pathee = "./rsz_biban.xpm";
}

void	help_checker(int j)
{
	if (j == 1)
	{
		printf("Error\nmap invalide a sat!!\n");
		exit (0);
	}
}

int	check_error_wall(t_data *data, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[0][i] && s[data->lmap - 1][i])
	{
		if (s[0][i] != '1' || s[data->lmap - 1][i] != '1')
		{
			j = 1;
			break ;
		}
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1' || s[i][data->cmap - 1] != '1')
		{
			j = 1;
			break ;
		}
		i++;
	}
	help_checker(j);
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	draw_img(t_data *data, char	*s)
{
	void	*im;

	im = mlx_xpm_file_to_image(data->mlx, s, &data->x, &data->y);
	mlx_put_image_to_window(data->mlx, data->win, im, data->xi, data->yi);
	return (0);
}
