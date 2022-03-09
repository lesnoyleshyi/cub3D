/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:14:07 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:14:09 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_side
{
	E_NORTH = 0,
	E_SOUTH = 1,
	E_WEST = 2,
	E_EAST = 3
};

enum e_surface
{
	E_FLOOR,
	E_CEILLING
};

typedef int t_bool;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map_data
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	player_side;
	char	**map;
}	t_map;

typedef struct s_file_data
{
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	t_map	*map;
	t_color	*floor;
	t_color	*ceilling;
}	t_data;

typedef struct s_coordination
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_texture
{
	void	*img;
	char	*adr;
	int		width;
	int		height;
	int 	endian;
	int 	len;
	int		bpp;
}	t_tex;



typedef struct s_game_data
{
	int 	f_color;
	int 	c_color;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_tex	*texture;
	t_tex	*screen;
	t_coord	player;
	t_coord	plane;
	t_coord	dir;
}	t_game;

#endif
