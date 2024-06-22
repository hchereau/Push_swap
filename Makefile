NAME = push_swap

### SRCS ######################################################################

PATH_SRCS = srcs/

SRCS += main.c

vpath %.c $(PATH_SRCS)

### HEADER ####################################################################

PATH_INCLUDES = includes/

HEADER += push_swap.h

### OBJS ######################################################################

PATH_OBJS = objs/

OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### LIBFT ####################################################################

PATH_LIBFT = libft/

LIBFT = $(PATH_LIBFT)libft.a

### FLAGS ####################################################################

CC = clang

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined -g3
endif

### RULES ####################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(PATH_INCLUDES)
$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	rm -rf $(PATH_OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re


