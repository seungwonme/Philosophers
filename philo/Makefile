.SUFFIXES : .c .o

NAME   := philo
CC     := cc
PRINTF := printf
CFLAGS := -Werror -Wall -Wextra -pthread
DEBUG  := -g
THREAD := -g3 -fsanitize=thread
MEMORY := -g3 -fsanitize=address

INCLUDE := -I./include
SRC_DIR := ./src

SRCS   := main.c \
					init.c \
					routine.c \
					mornitor.c \
					utils.c \
					cleanup.c \
					print.c
OBJS   := $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

# Color Aliases
BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
MAGENTA := \033[35m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m

ASCII_ART := "\
..............................................................\n\
. \n\
.        :::::::::  :::    ::: ::::::::::: :::        ::::::::\n\
.       :+:    :+: :+:    :+:     :+:     :+:       :+:    :+:\n\
.      +:+    +:+ +:+    +:+     +:+     +:+       +:+    +:+\n\
.     +\#++:++\#+  +\#++:++\#++     +\#+     +\#+       +\#+    +:+\n\
.    +\#+        +\#+    +\#+     +\#+     +\#+       +\#+    +\#+\n\
.   \#+\#        \#+\#    \#+\#     \#+\#     \#+\#       \#+\#    \#+\#\n\
.  \#\#\#        \#\#\#    \#\#\# \#\#\#\#\#\#\#\#\#\#\# \#\#\#\#\#\#\#\#\#\# \#\#\#\#\#\#\#\#\n\
. \n\
..............................................................\
"

all: clear $(NAME)
	@echo "$(GREEN)$(NAME) created successfully$(RESET)"

clear:
	clear
	@echo "$(CYAN)"
	@echo $(ASCII_ART)
	@echo "$(RESET)"

$(NAME): $(OBJS)	
	@echo "$(WHITE)Creating $@$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
	@echo "$(CYAN)Compiled:$(RESET) $< -> $@"

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)Cleaned up object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)Cleaned up executable and library$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

th:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(THREAD)"

mem:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(MEMORY)"

lldb:
	@$(MAKE) fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) $(DEBUG)"

.PHONY: all clean fclean re mem th lldb
