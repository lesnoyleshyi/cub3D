/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 06:13:55 by drayl             #+#    #+#             */
/*   Updated: 2022/03/05 06:13:57 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../srcs/libft/libft.h"
# include "constants.h"
# include "strings.h"
# include "structs.h"
# include <sys/fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//   --- parser ---   //
int		up_atoi(const char *str);
int		get_index(const char *str, char delimiter);
int		check_side(const char *line);
int		check_surface(const char *line);
void	put_error_and_arg(char *arg, char *message, int error_status);
void	put_error(const char *message, int error_status);
void	validation_check_path(char *path);
void	validation_check_color(t_color *color);
void	check_valid_map(t_map *map);
char	*get_subline(const char *line);
char	*read_file(char *file_name);
t_map	*create_map(void);
t_map	*convert_line_to_map(char *line);
t_data	*create_data(void);
t_data	*convert_line_to_data(char *line);

//   --- xlam.c ---   //
void	print_string_array(char **arr);
void	print_data(t_data *data);

#endif
