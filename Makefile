CC = gcc
# CFLAGS = -g3 -fsanitize=address
# CFLAGS = -fsanitize=thread -g
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lncurses -lreadline -L/Users/byahn/.brew/opt/readline/lib
CPPFLAGS = -I/Users/byahn/.brew/opt/readline/include
# LDFLAGS = -lncurses -lreadline -L/usr/local/opt/readline/lib
# CPPFLAGS = -I/usr/local/opt/readline/include

# LDFLAGS = -lncurses -lreadline -L/Users/junylee/.brew/opt/readline/lib
# CPPFLAGS = -I/Users/junylee/.brew/opt/readline/include

INC = ./includes
NAME = minishell
MAKE = make
LIB_NAME = libft.a
LIB_DIR = ./libft
SRC_DIR = .
SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/tokenize.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/list.c \
		$(SRC_DIR)/utils_print.c \
		$(SRC_DIR)/chk_input.c \
		$(SRC_DIR)/utils_clear.c \
		$(SRC_DIR)/syntax.c \
		$(SRC_DIR)/syntax2.c \
		$(SRC_DIR)/tree.c \
		$(SRC_DIR)/insert.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

# %.o:%.c
# 	@$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -I$(INC) -c $^ -o $@

$(NAME): $(OBJS)
	$(MAKE) bonus -C $(LIB_DIR)/
	mv $(LIB_DIR)/$(LIB_NAME) $(LIB_NAME)
	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIB_NAME)

clean:
	$(MAKE) clean -C $(LIB_DIR)/
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
