.PHONY = all clean

SRC_DIR := .
OBJ_DIR := ../blech_gen

SRCS := $(wildcard $(SRC_DIR)/**/*.blc)
OBJS := $(patsubst $(SRC_DIR)/%.blc, $(OBJ_DIR)/%.h, $(SRCS))

all: $(OBJS)

$(OBJ_DIR)/%.h: $(SRC_DIR)/%.blc
	@blechc -od ../blech_gen $<

clean:
	rm -rf ../blech_gen/*
