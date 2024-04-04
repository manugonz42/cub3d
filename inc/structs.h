/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:56:26 by jimmy             #+#    #+#             */
/*   Updated: 2024/03/18 14:32:59 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			rgb;	
	int			bitsinpixel;	
	int			line_bytes;	
	int			endian;
	int			setted;
	int			height;
	int			width;
}	t_image;

typedef struct s_player
{
	double	x;
	double	y;
	double	ray;
	int		fov;
	int		mov_speed;
	double	rot_speed;
	int		moving;
	int		rotating;
}	t_player;

typedef struct s_map
{
	char	**matrix;
	char	*raw_map;
	char	*path;
	int		rows;
	int		cols;
	int		pj;
}	t_map;

typedef struct s_sprites
{
	t_image	*no;
	t_image	*so;
	t_image	*ea;
	t_image	*we;
	t_image	*f;
	t_image	*c;
}	t_sprites;

typedef struct s_ray
{
	float	x;
	float	y;
	float	xo;
	float	yo;
	float	ra;
	float	atan;
	float	dish;
	float	hx;
	float	hy;
	float	disv;
	float	vx;
	float	vy;
	float	dist;
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;
	float	lineh;
	float	lineo;
}	t_ray;

typedef struct s_game
{
	void		*mlx_server;
	void		*mlx_window;
	int			width;
	int			height;
	t_image		*frame;
	t_map		*map;
	t_sprites	*sprites;
	t_player	*player;
}				t_game;

#endif