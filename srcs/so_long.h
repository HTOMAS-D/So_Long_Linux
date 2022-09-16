/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:50:13 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/16 12:29:44 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "../mlx/mlx.h"
#include "../libft/ft_printf.h"
#include <stdlib.h>


//LINUX KEYS
# define K_ESC					65307
# define K_W					119
# define K_A					97
# define K_D					100
# define K_S					115

typedef struct s_img
{
	void	*wall;
	void	*exit_o;
	void	*exit_c;
	void	*player;
	void	*collect;
	void	*mid;
}	t_img;

typedef struct s_map
{
	int	h;
	int	w;
	int	exit;
	int	collect;
	int	player;
}	t_map;

typedef struct s_win
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	char	**mapstr;	
	t_map	*map;
	t_img	*img;
	int	moves;
	int	over;
	int 	p_x;
	int	p_y;
}	t_win;

//so_long.c
int	check_file(char *file);
void	map_error(t_win *win);

//maps.c
//int	check_map(t_win *win);
char	**ft_read_map(char *av);

//error.c
int	error_check(char **mapstr, t_map *map, t_win *win);
int	check_wall(t_win win);
int	map_size(char **mapstr, t_map *map);
int	check_letters(char **mapstr, t_map *map);

//window.c
void	game_win(t_win *win);
void	get_img(t_win *win);
void	put_img(t_win *win, void *img, int x, int y);

//draw.c
void	draw_img(t_win *win);
void	draw_e(t_win *win, int x, int y);
void	draw_p(t_win *win, int x, int y);

//hooks.c
int	exit_game(t_win *win);
void	free_map(char **mapstr);
int	read_keys(int keycode, t_win *win);
int	cread_keys(int keycode, t_win *win);

//move.c
void	move_w(t_win *win);

#endif
