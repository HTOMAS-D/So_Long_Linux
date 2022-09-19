/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:50:13 by htomas-d          #+#    #+#             */
/*   Updated: 2022/09/19 10:40:34 by htomas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>

//LINUX KEYS
# define K_ESC					65307
# define K_W					119
# define K_A					97
# define K_D					100
# define K_S					115

//macOS KEYS
//# define K_ESC					53
//# define K_W					13
//# define K_A					0
//# define K_D					2
//# define K_S					1

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
	void	*mlx_ptr;
	void	*win_ptr;
	char	**mapstr;	
	t_map	*map;
	t_img	*img;
	int		moves;
	int		over;
	int		p_x;
	int		p_y;
}	t_win;

//so_long.c
int		check_file(char *file);
void	map_error(t_win *win);

//maps.c
char	**ft_read_map(char *av);

//error.c
int		error_check(char **mapstr, t_map *map, t_win *win);
int		check_wall(t_win win);
int		map_size(char **mapstr, t_map *map);
int		check_letters(char **mapstr, t_map *map);

//window.c
void	game_win(t_win *win);
void	get_img(t_win *win);
void	put_img(t_win *win, void *img, int x, int y);

//draw.c
void	draw_img(t_win *win);
void	draw_e(t_win *win, int x, int y);
void	draw_p(t_win *win, int x, int y);

//hooks.c
int		exit_game(t_win *win);
void	free_map(char **mapstr);
int		read_keys(int keycode, t_win *win);
int		cread_keys(int keycode, t_win *win);

//move.c
void	move_w(t_win *win);
void	move_s(t_win *win);
void	move_a(t_win *win);
void	move_d(t_win *win);

//images.c
void	img_d(t_win *win);
void	img_a(t_win *win);
void	img_s(t_win *win);
void	img_w(t_win *win);

#endif
