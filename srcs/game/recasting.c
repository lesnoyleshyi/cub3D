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

static void init_start_param(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / SCREEN_WIDTH - 1;
	ray->ray_pos.x = game->player.x;
	ray->ray_pos.y = game->player.y;
	ray->map_pos.x = (int) game->player.x;
	ray->map_pos.y = (int) game->player.y;
	ray->ray_dir.x = game->dir.x + game->plane.x * ray->camera_x;
	ray->ray_dir.y = game->dir.y + game->plane.y * ray->camera_x;
	ray->step.x = (ray->ray_dir.x >= 0) - (ray->ray_dir.x < 0);
	ray->step.y = (ray->ray_dir.y >= 0) - (ray->ray_dir.y < 0);
	ray->delta_dist.x = fabs(1.0 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1.0 / ray->ray_dir.y);
	ray->side_dist.x = (ray->map_pos.x - ray->ray_pos.x + (ray->step.x >= 0)) \
	* ray->step.x * ray->delta_dist.x;
	ray->side_dist.y = (ray->map_pos.y - ray->ray_pos.y + (ray->step.y >= 0)) \
	* ray->step.y * ray->delta_dist.y;
}

static void	init_other_info(t_game *game, t_ray *ray)
{
	int next_side;

	while (TRUE)
	{
		next_side = (ray->side_dist.x < ray->side_dist.y);
		ray->side_dist.x += (ray->delta_dist.x * next_side);
		ray->side_dist.y += (ray->delta_dist.y * !next_side);
		ray->map_pos.x += (ray->step.x * next_side);
		ray->map_pos.y += (ray->step.y * !next_side);
		ray->side = !next_side;
		if (game->map[ray->map_pos.y][ray->map_pos.x] == BLOCK)
			break ;
	}
	if (ray->side)
		ray->distance = fabs((ray->map_pos.y - game->player.y \
		+ (1.0 - ray->step.y) / 2) / ray->ray_dir.y);
	else
		ray->distance = fabs((ray->map_pos.x - game->player.x \
		+ (1.0 - ray->step.x) / 2) / ray->ray_dir.x);
	if (ray->side)
		ray->direction = E_NORTH + (ray->ray_dir.y >= 0);
	else
		ray->direction = E_WEST + (ray->ray_dir.x >= 0);
	ray->height = (int) fabs(SCREEN_HEIGHT / ray->distance);
}



static void	init_tex_pos(t_ray *r, t_tex *tex, t_icoord *tex_pos)
{
	if (r->side)
		r->wall_x = r->ray_pos.x + ((r->map_pos.y - r->ray_pos.y \
		+ (1.0 - r->step.y) / 2) / r->ray_dir.y) * r->ray_dir.x;
	else
		r->wall_x = r->ray_pos.y + ((r->map_pos.x - r->ray_pos.x \
		+ (1.0 - r->step.x) / 2) / r->ray_dir.x) * r->ray_dir.y;
	r->wall_x -= floor(r->wall_x);
	tex_pos->x = (int) (r->wall_x * tex->width);
	if (r->side == E_HORIZONTAL && r->ray_dir.x > 0)
		tex_pos->x = tex->width - tex_pos->x - 1;
	if (r->side == E_VERTICAL && r->ray_dir.y < 0)
		tex_pos->x = tex->width - tex_pos->x - 1;
}

static void	draw_wall(t_game *game, t_ray *r, int x)
{
	t_tex		*tex;
	t_icoord	pix;
	t_icoord	tex_pos;
	int 		tex_end;

	tex = &game->texture[r->direction];
	pix.x = x;
	pix.y = (int) ((SCREEN_HEIGHT - r->height) / 2.0 * ((SCREEN_HEIGHT - r->height) > 0));
	tex_end = (int) ((SCREEN_HEIGHT + r->height) / 2.0);
	if (tex_end > SCREEN_HEIGHT)
		tex_end = SCREEN_HEIGHT;
	draw_line(game, pix, tex_end);
	init_tex_pos(r, tex, &tex_pos);
	--pix.y;
	while (++pix.y < tex_end)
	{
		tex_pos.y = (int) ((pix.y * 2.0 - SCREEN_HEIGHT + r->height) \
		* ((tex->height / 2.0) / r->height));
		draw_pixel(&game->screen, pix, get_tex_color(tex, tex_pos));
	}
}

int	recasting(t_game *game)
{
	int		x;
	t_ray	ray;

	init_screen(game);
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		init_start_param(game, &ray, x);
		init_other_info(game, &ray);
		draw_wall(game, &ray, x);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->screen.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->screen.img);
	return (OK);
}
