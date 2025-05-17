# Nom de l'exécutable final
TARGET = adam_tools

# Répertoires
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -I$(INC_DIR)

# Fichiers sources et objets
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Règle par défaut
all: $(TARGET)

# Lien final
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compilation des .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
