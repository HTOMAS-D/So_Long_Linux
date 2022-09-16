#include "so_long.h"
#include "../mlx/mlx.h"

void	move_w(t_win *win)
{
	if(win->mapstr[win->p_y - 1][win->p_x] != '1'
		&& win->mapstr[win->p_y - 1][win->p_x != 'E']
		|| !win->map->collect)
	{
		if(win->mapstr[win->p_y - 1][win->p_x] == 'C')
		{
			win->map->collect--;
			win->mapstr[win->p_y][win->p_x] = '0';
			win->p_y--;
			win->mapstr[win->p_y][win->p_x] = 'P';
		}
		else if(win->mapstr[win->p_y - 1][win->p_x] == '0')
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
