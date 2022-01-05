/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:30:57 by abayar            #+#    #+#             */
/*   Updated: 2022/01/05 17:17:51 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	char	*path;
	char	*paths;
	char	*pathc;
	char	*pathe;
	char	*pathee;
	char	**s;
	int		index;
	int		index2;
	int		indexc;
	int		indexc2;
	int		cmap;
	int		lmap;
	int		x;
	int		y;
	int		xi;
	int		yi;
	int		fd;
	int		mv;
}	t_data;

int		check_error_wall(t_data *data, char **s);
int		check_size_map(t_data *data, char **s);
int		check_char(char **s);
void	help_checker(int j);
int		check_p(char *s);
void	help_check_char(int p, int c, int e);
int		destroy(t_data *data);
int		draw_img(t_data *data, char	*s);
int		check(t_data *vars, char c);
char	**read_map(t_data *data, char *s);
void	pars_map(char **s, t_data *data);
void	help_pos(t_data *data, char c, int i, int j);
void	main_pos(t_data *data, char c);
void	help_pars(char **s, t_data *data, int i, int j);
void	check_other_char(char **s);
void	so_path(t_data *img);

#endif
