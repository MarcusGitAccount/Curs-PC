CC = gcc
RM = rm

OBJDIR = obj
SRCDIR = src

# header paths are relative to the Makefile
CFLAGS = -lm -Wall -I.
STD = -std=c99
DEPS = header.h
# get all source files
SRC = $(wildcard $(SRCDIR)/*.c)
# for each .c file create an .o file and put it in the obj/
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: build

# creating the obj/ directory if doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# bulding th object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR) $(DEPS)
	$(CC) $(STD) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) $(STD) -o $@ $^ $(CFLAGS)

.PHONY:
	clean all fclean run

clean: fclean
	$(RM) -rf $(OBJDIR)
	
fclean: 
	$(RM) -f -- run