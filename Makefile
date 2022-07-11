NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a

LDLIBS	= -lreadline \
			./libft/libft.a

CRLDIR	= ~/.brew/opt/readline
RLDIR	= $(CRLDIR)
RLINC	= $(RLDIR)/include

LIBDIR	= -L $(RLDIR)/lib \
		  -L./libft

INCDIR	= -I ./srcs \
		  -I $(RLINC)

SHDIR	= ./srcs
SRC_PARSE = parsing/
SRC_BULITIN = builtin/
SRC_EXCUTE = execute/
SRC_UTILS = utils/
SOURCES = main.c \
		$(SRC_UTILS)utils.c \
		$(SRC_UTILS)utils_env.c \
		$(SRC_UTILS)utils_free.c \
		$(SRC_UTILS)utils_replace.c \
		$(SRC_UTILS)utils_replace2.c \
		$(SRC_UTILS)utils_termios.c \
		$(SRC_UTILS)utils_print.c \
		$(SRC_UTILS)utils_clear.c \
		$(SRC_PARSE)tokenize.c \
		$(SRC_PARSE)init.c \
		$(SRC_PARSE)list.c \
		$(SRC_PARSE)chk_input.c \
		$(SRC_PARSE)syntax.c \
		$(SRC_PARSE)syntax2.c \
		$(SRC_PARSE)tree.c \
		$(SRC_PARSE)insert.c \
		$(SRC_PARSE)env_list.c \
		$(SRC_PARSE)replace_env.c \
		$(SRC_EXCUTE)excute.c \
		$(SRC_EXCUTE)redir.c \
		$(SRC_EXCUTE)heredoc.c \
		$(SRC_EXCUTE)pipe.c \
		$(SRC_BULITIN)cd.c \
		$(SRC_BULITIN)echo.c \
		$(SRC_BULITIN)env.c \
		$(SRC_BULITIN)exit.c \
		$(SRC_BULITIN)export.c \
		$(SRC_BULITIN)pwd.c \
		$(SRC_BULITIN)unset.c \

SRCS	= $(addprefix $(SHDIR)/, $(SOURCES))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) $(LIBDIR) $(LDLIBS) -o $(NAME)

$(LIB)	:
	make bonus -C libft

clean	:
	rm -rf $(OBJS)
	make -C libft clean

fclean	: clean
	rm -rf $(NAME)
	make -C libft fclean

re		: fclean all

.PHONY	: all clean fclean re

# CC = gcc
# # CFLAGS = -g3 -fsanitize=address
# # CFLAGS = -fsanitize=thread -g
# # CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror
# # LDFLAGS = -lncurses -lreadline -L/Users/byahn/.brew/opt/readline/lib
# # CPPFLAGS = -I/Users/byahn/.brew/opt/readline/include
# # LDFLAGS = -lncurses -lreadline -L/usr/local/opt/readline/lib
# # CPPFLAGS = -I/usr/local/opt/readline/include

# LDFLAGS = -lncurses -lreadline -L/Users/junylee/.brew/opt/readline/lib
# CPPFLAGS = -I/Users/junylee/.brew/opt/readline/include

# INC = ./includes
# NAME = minishell
# MAKE = make
# LIB_NAME = libft.a
# LIB_DIR = ./libft
# FOLDER = ./srcs/
# SRC_PARSE = parsing/
# SRC_BULITIN = builtin/
# SRC_EXCUTE = execute/
# SRC_UTILS = utils/
# SOURCES = main.c \
# 		$(SRC_UTILS)utils.c \
# 		$(SRC_UTILS)utils_env.c \
# 		$(SRC_UTILS)utils_free.c \
# 		$(SRC_UTILS)utils_replace.c \
# 		$(SRC_UTILS)utils_replace2.c \
# 		$(SRC_UTILS)utils_termios.c \
# 		$(SRC_UTILS)utils_print.c \
# 		$(SRC_UTILS)utils_clear.c \
# 		$(SRC_PARSE)tokenize.c \
# 		$(SRC_PARSE)init.c \
# 		$(SRC_PARSE)list.c \
# 		$(SRC_PARSE)chk_input.c \
# 		$(SRC_PARSE)syntax.c \
# 		$(SRC_PARSE)syntax2.c \
# 		$(SRC_PARSE)tree.c \
# 		$(SRC_PARSE)insert.c \
# 		$(SRC_PARSE)env_list.c \
# 		$(SRC_PARSE)replace_env.c \
# 		$(SRC_EXCUTE)excute.c \
# 		$(SRC_EXCUTE)redir.c \
# 		$(SRC_BULITIN)cd.c \
# 		$(SRC_BULITIN)echo.c \
# 		$(SRC_BULITIN)env.c \
# 		$(SRC_BULITIN)exit.c \
# 		$(SRC_BULITIN)export.c \
# 		$(SRC_BULITIN)pwd.c \
# 		$(SRC_BULITIN)unset.c \

# SRCS =  $(addprefix $(FOLDER), $(SOURCES))

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# # %.o:%.c
# # 	@$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -I$(INC) -c $^ -o $@

# $(NAME): $(OBJS)
# 	$(MAKE) bonus -C $(LIB_DIR)/
# 	mv $(LIB_DIR)/$(LIB_NAME) $(LIB_NAME)
# 	$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -I$(INC) -o $(NAME) $(OBJS) $(LIB_NAME)

# clean:
# 	$(MAKE) clean -C $(LIB_DIR)/
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME) $(LIB_NAME)

# re: fclean all

# .PHONY: all clean fclean re
