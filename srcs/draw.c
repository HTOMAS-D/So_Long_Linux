/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:10:06 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:11:17 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"

void	draw_p(t_win *win, int x, int y)
{
	win->p_x = x;
	win->p_y = y;
	if (!win->over)
		put_img(win, win->img->player, x, y);
	else
		put_img(win, win->img->mid, x, y);
}

void	draw_e(t_win *win, int x, int y)
{
	if (win->map->collect)
		put_img(win, win->img->exit_c, x, y);
	else
		put_img(win, win->img->exit_o, x, y);
}

void	draw_img(t_win *win)
{
	int	x;
	int	y;

	y = -1;
	while (win->mapstr[++y])
	{
		x = -1;
		while (win->mapstr[y][++x])
		{
			if (win->mapstr[y][x] == '1')
				put_img(win, win->img->wall, x, y);
			else if (win->mapstr[y][x] == '0')
				put_img(win, win->img->mid, x, y);
			else if (win->mapstr[y][x] == 'E')
				draw_e(win, x, y);
			else if (win->mapstr[y][x] == 'P')
				draw_p(win, x, y);
			else if (win->mapstr[y][x] == 'C')
				put_img(win, win->img->collect, x, y);
		}
	}
}
