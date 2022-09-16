/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:46:31 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/12 15:18:33 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

int	map_size(char **mapstr, t_map *map)
{
	int	h;
	int	w;
	int	comp_w;

	h = 0;
	w = 0;
	comp_w = 0;
	while (mapstr[h])
	{
		w = 0;
		while (mapstr[h][w])
			w++;
		if(h && comp_w != w)
			return (0);
		comp_w = w;
		h++;
	}
	if (h < 3 || (h && h == w))
		return (0);
	map->h = h;
	map->w = w;
	return (1);
}

int	check_letters(char **mapstr, t_map *map)
{
	int	i;
	int	j;

	map->player = 0;
	map->collect = 0;
	map->exit = 0;
	i = -1;
	while (++i < map->h)
	{
		j = -1;
		while(++j < map->w)
		{
			if(mapstr[i][j] == 'P')
				map->player++;
			else if (mapstr[i][j] == 'C')
				map->collect++;
			else if(mapstr[i][j] == 'E')
				map->exit++;
		}
	}
	if(!map->exit || !map->collect || map->player != 1)
		return (0);
	return (1);
}

int	check_wall(t_win win)
{
	int	i;
	
	i = 0;
	while(i < win.map->w)
	{
		if(win.mapstr[0][i] != '1' || win.mapstr[win.map->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(i < win.map->h)
	{
		if(win.mapstr[i][0] != '1' || win.mapstr[1][win.map->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	error_check(char **mapstr, t_map *map, t_win *win)
{
	int i;
	int j;
	
	if(!mapstr)
		return (0);
	i = 0;
	while(mapstr[i])
	{
		j = 0;
		while(mapstr[i][j])
		{
			if(mapstr[i][j] != 'P' && mapstr[i][j] != 'C'
				&& mapstr[i][j] != 'E' && mapstr[i][j] != '1'
				&& mapstr[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if(map_size(mapstr, map) && check_wall(*win)
		&& check_letters(mapstr, map))
		return (1);
	return (0);
}	
