NAME = fillit

SRC_PATH = src/

OBJ_PATH = obj/

INCLUDE_PATH = src/

LIBFT_PATH = libft/

LIBFT_NAME = ft

SRC_NAME =  main.c \
            read.c \
						bit.c \
						tetrimino.c \
						standard.c \
						solve.c \
						print.c \
						parsing.c \
						init.c \
						result.c \
						deadrange.c \
						deadcells.c

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = $(SRC_NAME:%.c=$(SRC_PATH)%.c)

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_PATH)libft.a
	$(CC) -o $@ $(OBJ) -L$(LIBFT_PATH) -l$(LIBFT_NAME)

$(LIBFT_PATH)libft.a:
	make -C $(LIBFT_PATH)
	make -C $(LIBFT_PATH) clean

$(OBJ_PATH)%.o: $(SRC_PATH)%.c libft/libft.a
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< -I$(INCLUDE_PATH) $(CFLAGS)

clean:
	rm -rf $(OBJ_PATH)
	rm -rf $(LIBFT_PATH)$(OBJ_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)libft.a

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INCLUDE_PATH)*.h

.PHONY: all, clean, fclean, re, norme
