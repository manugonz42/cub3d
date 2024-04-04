/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:56:26 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:32:59 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structs.h"
# include "defines.h"
# include "../mlx/mlx.h"
# include <math.h>

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									INIT									 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

int		init_program(t_game *game, char *map);

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									PARSE									 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

int		parse_input(t_game *game);
void	check_line_map_format(char *line, t_game *game);
void	save_texture(char *line, t_game *game, int side, int i);
int		create_trgb(int t, int r, int g, int b);
void	parse_color(char *line, t_game *game, int side);
void	create_new_map_matrix(t_game *game);
void	check_wall_status(t_game *game);
char	next_token(char *line, int i);
int		last_token(char *line, int i);
int		check_first_or_last_row(char *line, t_game *game);
int		clean_row_size(char *line);
void	add_spcs(char *s, int j);
char	**realloc_to_tabs(char **matrix);
void	n_of_cols(t_game *game);
void	n_of_rows(t_game *game);
int		check_empty_map_line(char *line);
char	*save_texture_path(char *line, int i, t_game *game);
int		all_args_setted(t_game *game);
char	next_t(char *line, int i);
void	parse_map_line(char *line, t_game *game);
int	    parse_line(char *line, t_game *game);
int     check_nline(t_game *game, char *line, int *in_map);

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									FRAME									 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

void	print_frame(t_game *game);
void	create_player(t_game *game);
void	create_minimap(t_game *game);
void	create_background(t_game *game);

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									UPDATE									 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

int		draw_next_frame(t_game *game);
void	update_player_pos(t_game *game);
void	update_ray(t_game *game);
int		release_input(int keysym, t_game *game);
int		press_input(int keysym, t_game *game);

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									RAY_CASTING								 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

void	cast_rays(t_game *game);
void	render_ray(t_game *game, t_ray *ray, int n);
float	ray_dist(float ax, float ay, float bx, float by);
float	adjust_angle(float ra);

///////////////////////////////////////////////////////////////////////////////
//																			 //
//									UTILS									 //
//																			 //
///////////////////////////////////////////////////////////////////////////////

int		err(char *message, t_game *game);
void	set_player(t_game *game);
int		free_program(t_game *game);

#endif