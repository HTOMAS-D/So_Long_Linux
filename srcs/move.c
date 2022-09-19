/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:41:39 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:43:23 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_win *win)
{
	img_w(win);
	if (win->mapstr[win->p_y - 1][win->p_x] != '1'
		&& (win->mapstr[win->p_y - 1][win->p_x] != 'E'
		|| !win->map->collect))
	{
		if (win->mapstr[win->p_y - 1][win->p_x] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if (win->mapstr[win->p_y - 1][win->p_x] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void	move_s(t_win *win)
{
	img_s(win);
	if (win->mapstr[win->p_y + 1][win->p_x] != '1'
		&& (win->mapstr[win->p_y + 1][win->p_x] != 'E'
		|| !win->map->collect))
	{
		if (win->mapstr[win->p_y + 1][win->p_x] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if (win->mapstr[win->p_y + 1][win->p_x] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void	move_a(t_win *win)
{
	img_a(win);
	if (win->mapstr[win->p_y][win->p_x - 1] != '1'
		&& (win->mapstr[win->p_y][win->p_x - 1] != 'E'
		|| !win->map->collect))
	{
		if (win->mapstr[win->p_y][win->p_x - 1] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_x--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if (win->mapstr[win->p_y][win->p_x - 1] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_x--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void	move_d(t_win *win)
{
	img_d(win);
	if (win->mapstr[win->p_y][win->p_x + 1] != '1'
		&& (win->mapstr[win->p_y][win->p_x + 1] != 'E'
		|| !win->map->collect))
	{
		if (win->mapstr[win->p_y][win->p_x + 1] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_x++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if (win->mapstr[win->p_y][win->p_x + 1] == '0')
		{
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_x++;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}
