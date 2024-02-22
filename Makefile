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
INCLUDES = include
SRC_PATH = source/

# Target file
TARGET = cub3d

# Source files
PRINT_MAP = print_map.c
PARS = check_walls_utils.c check_walls.c clean_matrix_utils.c \
		clean_matrix.c color.c pars_utils.c parse_map.c
FILES = draw_window.c error.c exit.c handle_input.c \
		init.c
SOURCES = cub3d.c $(addprefix $(SRC_PATH), $(FILES)) \
		$(addprefix $(SRC_PATH)/pars/, $(PARS)) \
		$(addprefix $(SRC_PATH)/print_map/, $(PRINT_MAP))
# Compiler
CC = gcc

# Oompiler flags
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

# Libraries
LIBMLX = mlx/libmlx_Linux.a

LIBFT  = libft/libft.a
LIBFTDIR = libft/

MLXDIR = mlx

# System libraries to link
LIBS = -lXext -lX11 -lm

# Objets
OBJECTS = $(SOURCES:.c=.o)

# Rules
all: $(TARGET)

$(LIBFT):
	make -C libft

$(LIBMLX): 
	@make -C mlx > /dev/null 2>&1

$(TARGET): $(OBJECTS) $(LIBFT) $(LIBMLX)
	@echo -e "$(CYAN)--Compiling $(YELLOW)cub$(GREEN)3$(YELLOW)d$(RESET)"
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBFT) $(LIBMLX) $(LIBS)
	@echo -e "$(CYAN)--Ready$(WHITE)"
# Clean rules
clean:
	@echo -e "$(MAGENTA)--Deleting .o archives$(RESET)"
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	@rm -f $(OBJECTS) /objs

fclean: clean
	@echo -e "$(MAGENTA)--Deleting .a archives$(RESET)"
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	@rm -f $(TARGET)
re:	fclean all
	@echo -e "$(BLUE)--Remaking all...$(WHITE)"
	$(MAKE) all -C $(LIBFTDIR)
	$(MAKE) all -C $(MLXDIR)
	$(MAKE) all

