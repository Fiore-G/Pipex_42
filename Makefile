NAME = pipex

SRC_DIR = src
SRCS = $(SRC_DIR)/pipex.c $(SRC_DIR)/pipex_utils.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I $(SRC_DIR) -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
    make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/pipex.h Makefile
    $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
    rm -f $(OBJS)
    make -C $(LIBFT_DIR) clean

fclean: clean
    rm -f $(NAME)
    make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
