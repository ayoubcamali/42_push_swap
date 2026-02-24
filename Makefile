NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

HEADER      = push_swap.h
RM          = rm -rf

COMMON_SRCS = parse.c split.c stack.c stack_utils.c \
             ops_swap.c ops_push.c ops_rotate.c ops_rev_rotate.c \
             index.c sort_small.c sort_radix.c index_utils.c \
             sort_chunk.c sort_chunk_utils.c parse_utils.c split_utils.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

PUSH_SRCS = main.c
PUSH_OBJS = $(PUSH_SRCS:.c=.o)


BONUS_SRCS = checker_main.c checker_exec.c checker_read.c checker_read_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(COMMON_OBJS) $(PUSH_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PUSH_OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(COMMON_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(COMMON_OBJS) $(PUSH_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus