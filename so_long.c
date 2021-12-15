/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 03:20:17 by abayar            #+#    #+#             */
/*   Updated: 2021/12/15 03:32:02 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_draw(t_data *data,int x, int y, int i, int j)
  {
  int xx = 1920,yy = 1080;
  unsigned int color = mlx_get_color_value(data->mlx, 0x0000FF00);
  while (x < xx && y < yy)
  {
  if (x >= 100 && y >= 100)
  {
  if (equa(x, y, i, j))
  {
  mlx_pixel_put(data->mlx, data->win, x, y, color);
  }
  }
  x++;
  if (x == xx)
  {
  x = 100;
  y++;
  }
  }
  }*/
char	**read_map(t_data *data)
{
	int	l = 0;
	data->lmap = 0;
	char p;
	data->fd = open("map.ber", O_RDWR);

	while (!(read(data->fd, &p, 1) == 0))
	{//get_next_line(data->fd) != NULL)
		if (p == '\n')
			data->lmap++;
	}
	data->s = malloc(sizeof(char *) * (data->lmap + 1));
	close(data->fd);
	data->fd = open("map.ber", O_RDWR);
	while (l < data->lmap)
	{
		data->s[l] = get_next_line(data->fd);
		l++;
	}
	data->cmap = ft_strlen(data->s[1]);
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
		//data->indexC = 1,data->indexC2 = 0;
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

int	check(char c)
{
	if (c  == '1' || c == 'E')
			\\\\\\\\\\\\\\\\\\\\\\\\\\\\asdsdsad\asd\\\\\\\\\\\\\\\	
}

int	key_hook(int keycode, t_data *vars)
{
	char	c;
	mlx_clear_window(vars->mlx, vars->win);
	main_pos(vars, 'P');
	if (keycode == 53)
	{
		exit (0);
	}
	else if (keycode == 2)
	{
		if (vars->s[vars->index][vars->index2 + 1] != '1')
		{
			vars->s[vars->index][vars->index2 + 1] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 0)
	{
		if (vars->s[vars->index][vars->index2 - 1] != '1')
		{
			vars->s[vars->index][vars->index2 - 1] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 1)
	{
		if (vars->s[vars->index + 1][vars->index2] != '1')
		{
			vars->s[vars->index + 1][vars->index2] = vars->s[vars->index][vars->index2];
			vars->s[vars->index][vars->index2] = '0';
		}
	}
	else if (keycode == 13)
	{
		if (vars->s[vars->index - 1][vars->index2] != '1')
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


/*int	count_l(char **s, int fd)
  {
  int	i;

  i = 0;
  while (get_next_line(fd) != '\0')
  {

  }
  }*/
/*void f(void *l, void *d)
  {
  t_data *data =(t_data *) d;
  char *str = (char *) l;
  data->s[data->index] = l;
  data->index++;
  }

  void lst_iter(t_list *head, void (*f)(void *, void *), void *ptr)
  {
  t_list *h = head;

  while (h != NULL)
  {
  f(h->content, ptr);
  h  = h->next;
  }
  }*/

int main()
{
	t_data	img;
	char	**s;
	void	*im;

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
	//put_main(&img);
	s = read_map(&img);
	/*int i = 0;
	while (s[i] != 0)
		printf("%s\n", s[i++]);*/
	img.win = mlx_new_window(img.mlx, (img.cmap - 1) * 100, img.lmap * 100, "test");

	//img.win = mlx_new_window(img.mlx, 1920, 1080, "test");
	pars_map(s,&img);
	//img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	//ft_draw(&img, img.x, img.y, img.xi, img.yi);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
	return (0);
}
