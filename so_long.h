/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:30:57 by abayar            #+#    #+#             */
/*   Updated: 2021/12/15 17:32:27 by abayar           ###   ########.fr       */
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
	int		indexC;
	int     indexC2;
	int		cmap;
	int		lmap;
	int		x;
	int		y;
	int		xi;
	int		yi;
	int		fd;
}	t_data;

#endif
