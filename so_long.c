/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:20:17 by abayar            #+#    #+#             */
/*   Updated: 2022/01/05 17:18:29 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(t_data *vars, char c)
{
	if (c == '1' || c == 'E')
	{
		if (c == 'E' && vars->indexc2 == -1)
			return (1);
		return (0);
	}
	return (1);
}

void	help_keyss(int keycode, t_data *vars)
{
	if (keycode == 1)
	{
		if (check(vars, vars->s[vars->index + 1][vars->index2]))
		{
			vars->s[vars->index + 1][vars->index2] = \
			vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
			vars->mv++;
			printf("->%d\n", vars->mv);
		}
	}
	else if (keycode == 13)
	{
		if (check(vars, vars->s[vars->index - 1][vars->index2]))
		{
			vars->s[vars->index - 1][vars->index2] = \
			vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
			vars->mv++;
			printf("->%d\n", vars->mv);
		}
	}
}

void	help_keys(int keycode, t_data *vars)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 2)
	{
		if (check(vars, vars->s[vars->index][vars->index2 + 1]))
		{
			vars->s[vars->index][vars->index2 + 1] = \
			vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
			vars->mv += 1;
			printf("->%d\n", vars->mv);
		}
	}
	else if (keycode == 0)
	{
		if (check(vars, vars->s[vars->index][vars->index2 - 1]))
		{
			vars->s[vars->index][vars->index2 - 1] = \
			vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
			vars->mv++;
			printf("->%d\n", vars->mv);
		}
	}
	help_keyss(keycode, vars);
}

int	key_hook(int keycode, t_data *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	main_pos(vars, 'P');
	help_keys(keycode, vars);
	main_pos(vars, 'E');
	main_pos(vars, 'C');
	if (vars->indexc != -1)
		pars_map(vars->s, vars);
	else
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	img;
	char	**s;

	if (ac == 2)
	{
		img.mv = 0;
		img.xi = 0;
		img.yi = 0;
		img.x = 100;
		img.y = 100;
		img.mlx = mlx_init();
		so_path(&img);
		s = read_map(&img, av[1]);
		check_size_map(&img, s);
		check_error_wall(&img, s);
		check_char(s);
		img.win = mlx_new_window(img.mlx, img.cmap * 100, img.lmap * 100, "t");
		pars_map(s, &img);
		mlx_key_hook(img.win, key_hook, &img);
		mlx_hook(img.win, 17, 0, destroy, &img);
		mlx_loop(img.mlx);
	}
	else
		printf("Error\n error argment\n");
	return (0);
}
