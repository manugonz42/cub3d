#ifndef DEFINES_H
# define  DEFINES_H

// COLORS
# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define INT_MAX	__INT_MAX__
# define INT_MIN	-2147483648

// MAP CONFIG
# define IMG_BITS			32
# define WALL				'1'
# define SPACE 				'0'
# define PLAYER				'P'
# define NO					0
# define SO					1
# define EA					2
# define WE					3
# define F					4
# define C					5
# define B					6
# define W					7

// KEYBOARD CONFIG
# define AHEAD				1
# define BACK				2
# define LEFT				4
# define RIGHT				8
# define ROT_LEFT			16
# define ROT_RIGHT			32

// LINUX KEYS
# ifdef __linux__
#  define W_KEY				119
#  define A_KEY				97
#  define S_KEY				115
#  define D_KEY				100
#  define ESC_KEY			65307
#  define Q_KEY				113
#  define R_ARROW			65363
#  define L_ARROW			65361
# endif

// MAC KEYS
# ifdef __APPLE__
#  define W_KEY				13
#  define A_KEY				0
#  define S_KEY				1
#  define D_KEY				2
#  define ESC_KEY			53
#  define Q_KEY				12
#  define R_ARROW			124
#  define L_ARROW			123
# endif

// ERROR MESSAGES
# define INVALID_MAP		"Invalid map"
# define NO_MAP				"No map found"
# define INVALID_TEXTURE	"Invalid texture path"
# define INVALID_COLOR		"Invalid color value"
# define INVALID_LINE		"Invalid line in .cub file"
# define INVALID_ARG		"Invalid argument"
# define INVALID_FILE		"Invalid file"
# define REPIATED_ARG		"Repiated argument"
# define MISSING_NL			"New line missing in map"
# define MALLOC_ERROR		"Malloc error"
# define INVALID_ARGS		"Invalid number of arguments"
# define INVALID_FORMAT		"Invalid format of .cub file"
# define NOT_WALL_SR_MAP 	"Map must be surrounded by walls"
# define EMPTY_LINE			"Empty line in map"
# define MLX_ERROR			"MLX error"

// VALUES
# define DR                 M_PI / 180
# define M_PI_2             M_PI / 2
# define M_PI_3             3 * M_PI / 2
# define TILE_SIZE          8
# define TILE_BITS          3
# define FPS_30				33333
# define FPS_60				16667
# define FOV				60
# define GAME_WIDTH			960
# define GAME_HEIGHT		600
# define NO_RAYS			120

#endif