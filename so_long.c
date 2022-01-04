/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:20:17 by abayar            #+#    #+#             */
/*   Updated: 2022/01/04 10:49:20 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_data *data)
{
	int	l = 0;
	data->lmap = 0;
	char p;
	data->fd = open("map.ber", O_RDWR);

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
	data->fd = open("map.ber", O_RDWR);
	while (l < data->lmap)
	{
		data->s[l] = get_next_line(data->fd);
		l++;
	}
	data->cmap = ft_strlen(data->s[1]) - 1;
	data->s[l] = 0;
	return (data->s);
}

int	draw_img(t_data *data, char	*s)
{
	void *im;

	im = mlx_xpm_file_to_image(data->mlx, s, &data->x, &data->y);
	mlx_put_image_to_window(data->mlx, data->win, im, data->xi, data->yi);
	return 0;
}

void	pars_map(char **s, t_data *data)
{
	int i = 0, j;

	data->yi = 0;
	while (s[i])
	{	
		j = 0;
		data->xi = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				draw_img(data, data->path);
			else if (s[i][j] == '1')
				draw_img(data, data->paths);
			else if (s[i][j] == 'C')
				draw_img(data, data->pathc);
			else if (s[i][j] == 'E')
			{
				if (data->indexC2  == -1)
					draw_img(data, data->pathee);
				else
					draw_img(data, data->pathe);
			}
			j++;
			data->xi += 100;
		}
		data->yi += 100;
		i++;
	}
}

void	main_pos(t_data *data, char c)
{
	int	i = 0,j = 0;
	if (c == 'P')
	{
		data->index = 1,data->index2 = 0;

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
			data->indexC2 = -1;
		else if (c == 'E')
			data->indexC = -1;
	}
}

int	check(t_data *vars, char c)
{
	if (c  == '1' || c == 'E')
	{
		if (c == 'E' && vars->indexC2 == -1)
			return 1;
		return 0;
	}
	return 1;
}

int	key_hook(int keycode, t_data *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	main_pos(vars, 'P');
	if (keycode == 53)
	{
		exit (0);
	}
	else if (keycode == 2)
	{
		if (check(vars, vars->s[vars->index][vars->index2 + 1]))
		{
			vars->s[vars->index][vars->index2 + 1] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 0)
	{
		if (check(vars, vars->s[vars->index][vars->index2 - 1]))
		{
			vars->s[vars->index][vars->index2 - 1] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 1)
	{
		if (check(vars, vars->s[vars->index + 1][vars->index2]))
		{
			vars->s[vars->index + 1][vars->index2] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 13)
	{
		if (check(vars, vars->s[vars->index - 1][vars->index2]))
		{
			vars->s[vars->index - 1][vars->index2] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	main_pos(vars, 'E');
	main_pos(vars, 'C');
	if (vars->indexC != -1)
		pars_map(vars->s, vars);
	else{
		exit (0);
	}
	return (0);
}

int	destroy(t_data *data)
{

	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return 0;
}

int main()
{
	t_data	img;
	char	**s;

	img.xi = 0;
	img.yi = 0;
	img.x = 100;
	img.y = 100;
	img.mlx = mlx_init();

	img.path = "./rsz_main.xpm";
	img.paths = "./rsz_stone.xpm";
	img.pathc = "./rsz_pizza.xpm";
	img.pathe = "./bab.xpm";
	img.pathee = "./rsz_biban.xpm";
	s = read_map(&img);
	check_size_map(&img, s);
	check_error_wall(&img, s);
	check_char(s);
	img.win = mlx_new_window(img.mlx, (img.cmap) * 100, img.lmap * 100, "test");
	pars_map(s,&img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 0, destroy, &img);
	mlx_loop(img.mlx);
	return (0);
}