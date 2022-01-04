/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:10:08 by abayar            #+#    #+#             */
/*   Updated: 2022/01/04 10:56:53 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_error_wall(t_data *data, char **s)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
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
    if (j == 1)
    {
        printf("Error\nmap invalide a sat!!\n");
        exit (1);
    }
    return (0);
}

int check_size_map(t_data *data, char **s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if ((ft_strlen(s[i]) != ft_strlen(s[0])) && i < data->lmap - 1)
        {
            printf("Error\ninvalide map a sat!!\n");
            exit (1);
        }
        i++;
    }
    return (0);
}

int    check_p(char *s)
{
    int i;
    int t;
    
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

int check_char(char **s)
{
    int i;
    int c;
    int p;
    int e;

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
    if (p != 1 || c == 0 || e == 0)
    {
        printf("Error\nchihaja mahiyach hh\n");
        exit (0);
    }
    return 0;
}