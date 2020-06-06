NAME = pathfinder

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

RMO = obj
DIR = ./libmx
LIB = ./libmx/libmx.a
COM = ./libmx.a
INC = ./inc/pathfinder.h

SRC = ./src/main.c\
	  ./src/mx_error_handler.c
INCS = ./pathfinder.h

SRCS = ./main.c\
	   ./mx_error_handler.c\

OBJ = ./main.o\
	./mx_error_handler.o

all: install uninstall
	
install:
	@cd $(DIR) && make
	@cp $(LIB) .
	@cp $(INC) $(SRC) .
	@clang $(CFLGS) $(SRCS) -c $(SRCS) -I$(INCS)
	@mkdir -p obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(SRCS) $(COM) -o $(NAME) -I$(INCS)
	@mv libmx.a ./obj
	@rm -rf $(INCS) $(SRCS)
clean:
	@rm -rf $(NAME)
	@rm -rf $(LIB)
uninstall:
	@rm -rf $(RMO)
	
reinstall: install uninstall
