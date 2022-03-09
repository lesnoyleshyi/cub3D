#include "../../includes/cub.h"

static void	file_to_img(t_tex *tex, void *mlx, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx,path,&tex->width,&tex->height);
	if (tex->img == NULL)
		put_error(INVALID_INIT_IMG, ERR_INIT_IMG);
}

static void get_addr(t_tex *tex)
{
	tex->adr = mlx_get_data_addr(tex->img, &tex->bpp,
								&tex->len, &tex->endian);
	if (tex->adr == NULL)
		put_error(INVALID_INIT_IMG, ERR_INIT_IMG);
}

static void	init_texture(t_game *game, t_data *data)
{
	t_tex	*tex;

	tex = (t_tex *) malloc(sizeof (t_tex) * TEXTURE_COUNT);
	if (tex == NULL)
		put_error(INVALID_MEMORY, ERR_MEMORY);
	file_to_img(&(tex[E_NORTH]), game->win_ptr, data->path_north);
	file_to_img(&(tex[E_SOUTH]), game->win_ptr, data->path_south);
	file_to_img(&(tex[E_WEST]), game->win_ptr, data->path_west);
	file_to_img(&(tex[E_EAST]), game->win_ptr, data->path_east);
	get_addr(&(tex[E_NORTH]));
	get_addr(&(tex[E_SOUTH]));
	get_addr(&(tex[E_WEST]));
	get_addr(&(tex[E_EAST]));
	game->texture = tex;
}

void	init_mlx(t_game *game, t_data *data)
{
	if (data != NULL)
		{};
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		put_error(INVALID_MLX_PTR, ERR_MLX);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
								   SCREEN_WIDTH, SCREEN_HEIGHT, NAME);
	if (game->win_ptr == NULL)
		put_error(INVALID_MLX_PTR, ERR_MLX);
	init_texture(game, data);
}
