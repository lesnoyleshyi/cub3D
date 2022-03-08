#include "../../includes/cub.h"

double	up_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * -1);
}

int	get_pixel_color(t_tex *tex, double x0, double y0)
{
	int x;
	int	y;
	int	*color;

	x = (int) x0;
	y = (int) y0;
	color = (void *) tex->adr + (y * tex->len) + (x * tex->bpp / 8);
	return (*color);
}

void	put_pixel(t_tex *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->len) + (x * img->bpp / 8);
	*(int *)dst = color;
}