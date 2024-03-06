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
TARGET = cub3d

# Source files
SRC =	$(SRC_DIR)pars/check_walls_utils.c					\
		$(SRC_DIR)pars/check_walls.c						\
		$(SRC_DIR)pars/clean_matrix_utils.c					\
		$(SRC_DIR)pars/clean_matrix.c						\
		$(SRC_DIR)pars/color.c								\
		$(SRC_DIR)pars/pars_utils.c							\
		$(SRC_DIR)pars/parse_map.c							\
		$(SRC_DIR)pars/textures.c							\
		$(SRC_DIR)print/create_background.c					\
		$(SRC_DIR)print/draw_pj.c							\
		$(SRC_DIR)print/print_map.c							\
		$(SRC_DIR)ray_casting/ray_utils.c					\
		$(SRC_DIR)ray_casting/render.c						\
		$(SRC_DIR)ray_casting/start_ray.c					\
		$(SRC_DIR)update/draw_next_frame.c					\
		$(SRC_DIR)update/update.c							\
		$(SRC_DIR)utils/error.c								\
		$(SRC_DIR)utils/exit.c								\
		$(SRC_DIR)utils/handle_input.c						\
		$(SRC_DIR)utils/init_pj.c							\
		$(SRC_DIR)utils/init.c								\
		$(SRC_DIR)cub3d.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


# Compiler
CC = gcc

# Oompiler flags
CFLAGS = -Wall -Wextra -Werror -I$(INC)

# Libraries
LIBMLX = mlx/libmlx_Linux.a

LIBFT  = libft/libft.a
LIBFTDIR = libft/

MLXDIR = mlx

# System libraries to link
LIBS = -lXext -lX11 -lm

# Rules
all: $(TARGET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(LIBMLX): 
	@make -C mlx > /dev/null 2>&1

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

