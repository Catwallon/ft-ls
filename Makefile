NAME = ft_ls

CC = gcc
CFLAGS = -D_DEFAULT_SOURCE -Wall -Wextra -Werror -g
LD_FLAGS =

BIN_DIR = bin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

BIN = $(addprefix $(BIN_DIR)/, $(NAME))
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LD_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*

fclean: clean
	rm -f $(BIN)

re: fclean all

.PHONY: all clean fclean re
