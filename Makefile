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
	./src/mx_number_of_unique_cities.c\
	./src/mx_make_unique_cities_array.c\
	./src/mx_make_matrix.c\
	./src/mx_algorithm.c\
	./src/mx_array_extender.c\
	./src/mx_array_filler.c\
	./src/mx_array_garbager.c\
	./src/mx_array_printer.c\
	./src/mx_array_recursion_editor.c\
	./src/mx_big_array_printer.c\
	./src/mx_copy_r_list.c\
	./src/mx_create_route_node.c\
	./src/mx_elements_of_line.c\
	./src/mx_int_array_extender.c\
	./src/mx_is_in_list.c\
	./src/mx_list_value_validator.c\
	./src/mx_outer_array_recursion_editor.c\
	./src/mx_output.c\
	./src/mx_push_route_back.c\
	./src/mx_push_route_front.c\
	./src/mx_r_list_reverse.c\
	./src/mx_sort_route_list.c\
	./src/mx_sort_route_list2.c\
	./src/mx_printer.c\

INCS = ./pathfinder.h

SRCS = ./main.c\
	   ./mx_error_handler.c\
	   ./mx_error_0.c\
	   ./mx_error_1.c\
	   ./mx_error_2.c\
	   ./mx_error_3.c\
	   ./mx_error_4.c\
	   ./mx_error_5.c\
	   ./mx_number_of_unique_cities.c\
	   ./mx_make_unique_cities_array.c\
	   ./mx_make_matrix.c\
	   ./mx_algorithm.c\
	   ./mx_array_extender.c\
	   ./mx_array_filler.c\
	   ./mx_array_garbager.c\
	   ./mx_array_printer.c\
	   ./mx_array_recursion_editor.c\
	   ./mx_big_array_printer.c\
	   ./mx_copy_r_list.c\
	   ./mx_create_route_node.c\
	   ./mx_elements_of_line.c\
	   ./mx_int_array_extender.c\
	   ./mx_is_in_list.c\
	   ./mx_list_value_validator.c\
	   ./mx_outer_array_recursion_editor.c\
	   ./mx_output.c\
	   ./mx_push_route_back.c\
	   ./mx_push_route_front.c\
	   ./mx_r_list_reverse.c\
	   ./mx_sort_route_list.c\
	   ./mx_sort_route_list2.c\
	   ./mx_printer.c\

OBJ = ./main.o\
	./mx_error_handler.o\
	./mx_error_0.o\
	./mx_error_1.o\
	./mx_error_2.o\
	./mx_error_3.o\
	./mx_error_4.o\
	./mx_error_5.o\
	./mx_number_of_unique_cities.o\
	./mx_make_unique_cities_array.o\
	./mx_make_matrix.o\
	./mx_algorithm.o\
	./mx_array_extender.o\
	./mx_array_filler.o\
	./mx_array_garbager.o\
	./mx_array_printer.o\
	./mx_array_recursion_editor.o\
	./mx_big_array_printer.o\
	./mx_copy_r_list.o\
	./mx_create_route_node.o\
	./mx_elements_of_line.o\
	./mx_int_array_extender.o\
	./mx_is_in_list.o\
	./mx_list_value_validator.o\
	./mx_outer_array_recursion_editor.o\
	./mx_output.o\
	./mx_push_route_back.o\
	./mx_push_route_front.o\
	./mx_r_list_reverse.o\
	./mx_sort_route_list.o\
	./mx_sort_route_list2.o\
	./mx_printer.o\

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
