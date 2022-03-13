#include "../includes/cub.h"

void	print_string_array(char **arr)
{
	while (*arr)
		printf("%s\n", *(arr++));
}

void	print_data(t_data *data)
{
	printf("   --- DATA START ---   \n");
	printf("path_north - %s\n", data->path_north);
	printf("path_south - %s\n", data->path_south);
	printf("path_west - %s\n", data->path_west);
	printf("path_east - %s\n", data->path_east);
	printf("color F - %d %d %d\n", data->floor->r, data->floor->g, data->floor->b);
	printf("color C - %d %d %d\n", data->ceilling->r, data->ceilling->g, data->ceilling->b);
	printf("   --- MAP START ---   \n");
	printf("wight - %d\n", data->map->width);
	printf("height - %d\n", data->map->height);
	printf("player side - %c\n", data->map->player_side);
	printf("player x - %d\n", data->map->player_x);
	printf("player y - %d\n", data->map->player_y);
	print_string_array(data->map->map);
	printf("   --- MAP END ---   \n");
	printf("   --- DATA END ---   \n");
}

void	print_ray(t_ray ray)
{
	printf("ray.ray_pos.x = %f, ray.ray_pos.y = %f\n", ray.ray_pos.x,  ray.ray_pos.y);
	printf("ray.camera_x = %f\n", ray.camera_x);
	printf("ray.map_pos.x = %d, ray.map_pos.y = %d\n", ray.map_pos.x,  ray.map_pos.y);
	printf("ray.ray_dir.x = %f, ray.ray_dir.y = %f\n", ray.ray_dir.x,  ray.ray_dir.y);
	printf("ray.step.x = %d, ray.step.y = %d\n", ray.step.x,  ray.step.y);
	printf("ray.delta_dist.x = %f, ray.delta_dist.y = %f\n", ray.delta_dist.x,  ray.delta_dist.y);
	printf("ray.side_dist.x = %f, ray.side_dist.y = %f\n", ray.side_dist.x,  ray.side_dist.y);
	printf("ray.side = %d\n", ray.side);
	printf("ray.distance = %f\n", ray.distance);
	printf("ray.direction = %d\n", ray.direction);
	printf("ray.height = %d\n", ray.height);
	printf("ray.wall_x = %f\n", ray.wall_x);
//	exit(0);
}

void	print(char *mes)
{
	printf("%s\n", mes);
}
