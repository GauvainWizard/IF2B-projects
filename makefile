SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm
CC 		 := gcc

ifeq ($(OS), Windows_NT)
	CLEANCMD = rd /s /q $(OBJ_DIR) ${BIN_DIR}
	MKDIR = md
else
	CLEANCMD = rm -rv $(BIN_DIR) $(OBJ_DIR)
	MKDIR = mkdir -p
endif

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	${MKDIR} $@

clean:
	${CLEANCMD}

-include $(OBJ:.o=.d)