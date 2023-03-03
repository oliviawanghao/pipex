CC= gcc
FLAGS= -Wall -Werror -Wextra
NAME= pipex
SRCS= pipex.c \
	pipex_utils.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strlen.c \
	ft_split.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strnstr.c \

OBJS= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	gcc  $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re