NAME = pathfinder

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

RMO = obj
DIR = ./libmx
LIB = ./libmx/libmx.a
COM = ./libmx.a
INC = ./inc/pathfinder.h

SRC = ./src/main.c\
	  ./src/mx_error_handler.c\
	  ./src/mx_error_0.c\
	./src/mx_error_1.c\
	./src/mx_error_2.c\
	./src/mx_error_3.c\
	./src/mx_error_4.c\
	./src/mx_error_5.c\

INCS = ./pathfinder.h

SRCS = ./main.c\
	   ./mx_error_handler.c\
	   ./mx_error_0.c\
	   ./mx_error_1.c\
	   ./mx_error_2.c\
	   ./mx_error_3.c\
	   ./mx_error_4.c\
	   ./mx_error_5.c\

OBJ = ./main.o\
	./mx_error_handler.o\
	./mx_error_0.o\
	./mx_error_1.o\
	./mx_error_2.o\
	./mx_error_3.o\
	./mx_error_4.o\
	./mx_error_5.o\

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
