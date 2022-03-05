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
	E_NORTH,
	E_SOUTH,
	E_WEST,
	E_EAST
};

enum e_surface
{
	E_FLOOR,
	E_CEILLING
};

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

typedef struct s_game_data
{
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	t_map	*map;
	t_color	*floor;
	t_color	*ceilling;
}	t_data;

#endif
