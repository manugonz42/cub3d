#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_image
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
	char	**tc_matrix;
	char	*raw_map;
	char	*path;
	int		rows;
	int		cols;
	int		pj;
}	t_map;

typedef struct	s_sprites
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
	float	aTan;
	float	disH;
	float	hx;
	float	hy;
	float	disV;
	float	vx;
	float	vy;
	float	disT;
	float	tx;
	float	ty;
	float	ty_step;
	float	ty_off;
	float	lineH;
	float	lineO;
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