NAME			=	bsq

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDES		=	-Iinclude

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/

SRCS			=	$(wildcard $(SRCS_DIR)*.c)
OBJS			=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))


all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				@mkdir -p $(OBJS_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				rm -rf $(OBJS_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re