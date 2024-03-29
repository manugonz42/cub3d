.SILENT:
MAKEFLAGS += -s

# Colors
CYAN = \033[0;36m
RESET = \033[0M
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
WHITE = \033[0;37m

# Paths
INC = inc
SRC_DIR = src/
OBJ_DIR = obj/

# Target file
TARGET = cub3D

# Source files
SRC =	$(SRC_DIR)frame/create_background.c					\
		$(SRC_DIR)frame/create_minimap.c					\
		$(SRC_DIR)frame/create_player.c						\
		$(SRC_DIR)frame/print_frame.c						\
		$(SRC_DIR)init/init_game.c							\
		$(SRC_DIR)parse/check_walls_utils.c					\
		$(SRC_DIR)parse/check_walls.c						\
		$(SRC_DIR)parse/clean_matrix_utils.c				\
		$(SRC_DIR)parse/clean_matrix.c						\
		$(SRC_DIR)parse/color.c								\
		$(SRC_DIR)parse/parse_utils.c						\
		$(SRC_DIR)parse/parse.c								\
		$(SRC_DIR)parse/textures.c							\
		$(SRC_DIR)parse/check_args.c						\
		$(SRC_DIR)ray_casting/ray_utils.c					\
		$(SRC_DIR)ray_casting/render.c						\
		$(SRC_DIR)ray_casting/start_ray.c					\
		$(SRC_DIR)update/draw_next_frame.c					\
		$(SRC_DIR)update/update.c							\
		$(SRC_DIR)utils/error.c								\
		$(SRC_DIR)utils/free_program.c						\
		$(SRC_DIR)utils/set_player.c						\
		$(SRC_DIR)cub3d.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


# Compiler
CC = gcc

# Oompiler flags
CFLAGS = -Wall -Wextra -Werror -I$(INC)

LIBMLX = mlx_mac/libmlx.a
MLXDIR = mlx_mac
LIBS = -lmlx -framework OpenGL -framework AppKit

ifeq ($(UNAME), Linux)
MLXDIR = mlx
LIBMLX = mlx/libmlx_Linux.a
LIBS = -lXext -lX11 -lm
endif

# Libraries
LIBFT  = libft/libft.a
LIBFTDIR = libft/

# Rules
all: $(TARGET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(LIBMLX): 
	@make -C $(MLXDIR) > /dev/null 2>&1

$(TARGET): $(OBJ) $(LIBFT) $(LIBMLX)
	@echo -e "$(CYAN)--Compiling $(YELLOW)cub$(GREEN)3$(YELLOW)d$(RESET)"
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBFT) $(LIBMLX) $(LIBS)
	@echo -e "$(CYAN)--Ready$(WHITE)"
# Clean rules
clean:
	@echo -e "$(MAGENTA)--Deleting .o archives$(RESET)"
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo -e "$(MAGENTA)--Deleting .a archives$(RESET)"
	$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f $(TARGET)
re:	fclean all
	@echo -e "$(BLUE)--Remaking all...$(WHITE)"

