#include "../../includes/cub.h"

static void	init_screen(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	game->screen.img = mlx_new_image(game->mlx_ptr,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	game->screen.adr = mlx_get_data_addr(game->screen.img,
			&game->screen.bpp,
			&game->screen.len,
			&game->screen.endian);
}

static void	init_start_data(t_game *game, int x)
{
	t_param	*param;

	param = &game->params;
	param->camera_x = 2.0 * x / SCREEN_WIDTH - 1;
	param->ray_dir.x = game->dir.x + game->plane.x * param->camera_x;
	param->ray_dir.y = game->dir.y + game->plane.y * param->camera_x;
	param->map.x = (int) game->player.x;
	param->map.y = (int) game->player.y;
	param->del_dist.x = fabs(1 / param->ray_dir.x);
	param->del_dist.y = fabs(1 / param->ray_dir.y);
//	param->del_dist.x = sqrt(1 + (param->ray_dir.y * param->ray_dir.y) \
//	/ (param->ray_dir.x * param->ray_dir.x));
//	param->del_dist.x = sqrt(1 + (param->ray_dir.x * param->ray_dir.x) \
//	/ (param->ray_dir.y * param->ray_dir.y));
	param->step.x = (param->ray_dir.x >= 0) - (param->ray_dir.x < 0);
	param->step.y = (param->ray_dir.y >= 0) - (param->ray_dir.y < 0);
//	if (param->ray_dir.x < 0)
//		param->side_dist.x = (game->player.x - param->map.x) * param->del_dist.x;
//	else
//		param->side_dist.x = (param->map.x + 1.0 - game->player.x) * param->del_dist.x;
//	if (param->ray_dir.y < 0)
//		param->side_dist.y = (game->player.y - param->map.y) * param->del_dist.y;
//	else
//		param->side_dist.y = (param->map.y + 1.0 - game->player.y) * param->del_dist.y;
	param->side_dist.x = (param->map.x - game->player.x + (param->step.x > 0)) \
	* param->step.x * param->del_dist.x;
	param->side_dist.y = (param->map.y - game->player.y + (param->step.y > 0)) \
	* param->step.y * param->del_dist.y;
}

static void	get_hit(t_game *game)
{
	t_param	*param;

	param = &game->params;
	while (TRUE)
	{
		if (param->side_dist.x < param->side_dist.y)
		{
			param->side_dist.x += param->del_dist.x;
			param->map.x += param->step.x;
			param->side = E_HORIZONTAL;
		}
		else
		{
			param->side_dist.y += param->side_dist.y;
			param->map.y += param->step.y;
			param->side = E_VERTICAL;
		}
		if (game->map[param->map.y][param->map.x] == BLOCK)
			return ;
	}
}

static void	get_limiter_draw(t_game *game)
{
	t_param	*param;

	param = &game->params;
	if (param->side == E_HORIZONTAL)
		param->dist_to_hit = param->side_dist.x - param->del_dist.x;
	else
		param->dist_to_hit = param->side_dist.y - param->del_dist.y;
	param->tex_height = (int) (SCREEN_HEIGHT / param->dist_to_hit);
	param->draw_start = (SCREEN_HEIGHT - param->tex_height) / 2;
	if (param->draw_start < 0)
		param->draw_start = 0;
	param->draw_end = (SCREEN_HEIGHT + param->tex_height) / 2;
	if (param->draw_end >= SCREEN_HEIGHT)
		param->draw_end = SCREEN_HEIGHT - 1;
}

static void	get_texture_pos(t_game *game)
{
	t_param	*param;

	param = &game->params;
	if (param->side == E_HORIZONTAL)
		param->wall_x = game->player.y + param->dist_to_hit + param->ray_dir.y;
	else
		param->wall_x = game->player.x + param->dist_to_hit + param->ray_dir.x;
	param->wall_x -= floor(param->wall_x);
	param->tex.x = (int) (param->wall_x * TEX_WIDTH);
	if ((param->side == E_HORIZONTAL && param->ray_dir.x > 0)
		|| (param->side == E_VERTICAL && param->ray_dir.y < 0))
		param->tex.x = TEX_WIDTH - param->tex.x - 1;
	param->step_len = 1.0 * TEX_HEIGHT / param->tex_height;
	param->tex_pos = (param->draw_start \
	- (1.0 * SCREEN_HEIGHT - param->tex_height) / 2) * param->step_len;
}

int	recasting(t_game *game)
{
	int	x;

	init_screen(game);
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		init_start_data(game, x);
		get_hit(game);
		get_limiter_draw(game);
		get_texture_pos(game);
		print_param(game->params);
		draw_line(game, x);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->screen.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->screen.img);
	return (OK);
}
