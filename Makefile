NAME := push_swap

### LIBFT ####################################################################

PATH_LIBFT := libft/

LIBFT = $(PATH_LIBFT)libft.a

### SRCS ######################################################################

PATH_SRCS += srcs/

# SRCS += main.c
SRCS += main_test_parsing.c

# srcs/parsing

PATH_SRCS += srcs/parsing/

SRCS += get_numbers_list.c
SRCS += is_valid_list.c
SRCS += is_valid_string.c

# srcs/algo

PATH_SRCS += srcs/algo/

SRCS += sort_numbers.c
SRCS += sorting_process.c

vpath %.c $(PATH_SRCS)

### HEADER ####################################################################

INCLUDES_PUSH_SWAP := includes/
INCLUDES_LIBFT := $(PATH_LIBFT)includes/
INCLUDES += -I $(INCLUDES_PUSH_SWAP)
INCLUDES += -I $(INCLUDES_LIBFT)

HEADERS += $(INCLUDES_PUSH_SWAP)push_swap.h
HEADERS += $(INCLUDES_PUSH_SWAP)parsing.h
HEADERS += $(INCLUDES_PUSH_SWAP)algo.h

### OBJS ######################################################################

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

### FLAGS ####################################################################

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g3

ifeq ($(debug), true)
	CFLAGS += -fsanitize=address,undefined
endif

### COLORS ####################################################################

BLUE := \033[0;34m
GREEN := \033[0;32m
WHITE := \033[0;37m

### RULES ####################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME) ...$(WHITE)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(INCLUDES)
	@echo "$(GREEN)$(NAME) Compiled !$(WHITE)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	@echo "$(BLUE)Compiling libft ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)libft Compiled !$(WHITE)"

clean:
	@echo "$(BLUE)Cleaning ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) clean
	@rm -rf $(PATH_OBJS)
	@echo "$(GREEN)Cleaned !$(WHITE)"

fclean: clean
	@echo "$(BLUE)Full Cleaning ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)Full Cleaned !$(WHITE)"

re: fclean all

.PHONY: all clean fclean re libft
.SILENT: all clean fclean re libft

