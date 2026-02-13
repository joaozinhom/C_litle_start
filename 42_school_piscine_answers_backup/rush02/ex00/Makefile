NAME        = rush-02
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./includes

SRCS_DIR    = srcs/

SRCS_FILES  = validation.c \
              number_conversion.c \
              dict_utils.c \
              parsing.c \
			  parsing_utils.c \
              utils.c \
			  check_input_in_dict.c \
			  convert_main.c \
			  convert_utils.c \
			  input_output.c \
              main.c \

SRCS        = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re