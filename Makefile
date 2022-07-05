CC = gcc
# CFLAGS = -g3 -fsanitize=address
# CFLAGS = -fsanitize=thread -g
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror
# LDFLAGS = -lncurses -lreadline -L/Users/byahn/.brew/opt/readline/lib
# CPPFLAGS = -I/Users/byahn/.brew/opt/readline/include
# LDFLAGS = -lncurses -lreadline -L/usr/local/opt/readline/lib
# CPPFLAGS = -I/usr/local/opt/readline/include

LDFLAGS = -lncurses -lreadline -L/Users/junylee/.brew/opt/readline/lib
CPPFLAGS = -I/Users/junylee/.brew/opt/readline/include

INC = ./includes
NAME = minishell
MAKE = make
LIB_NAME = libft.a
LIB_DIR = ./libft
FOLDER = ./srcs/
SRC_PARSE = parsing
SOURCES = main.c \
		$(SRC_PARSE)/tokenize.c \
		$(SRC_PARSE)/utils.c \
		$(SRC_PARSE)/init.c \
		$(SRC_PARSE)/list.c \
		$(SRC_PARSE)/utils_print.c \
		$(SRC_PARSE)/chk_input.c \
		$(SRC_PARSE)/utils_clear.c \
		$(SRC_PARSE)/syntax.c \
		$(SRC_PARSE)/syntax2.c \
		$(SRC_PARSE)/tree.c \
		$(SRC_PARSE)/insert.c

SRCS =  $(addprefix $(FOLDER), $(SOURCES))

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
