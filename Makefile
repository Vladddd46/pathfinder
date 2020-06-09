NAME	=	pathfinder

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/$(INCD)

INC		=	pathfinder.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	main.c\
			mx_algorithm.c\
			mx_array_extender.c\
			mx_array_filler.c\
			mx_array_garbager.c\
			mx_array_printer.c\
			mx_array_recursion_editor.c\
			mx_big_array_printer.c\
			mx_copy_r_list.c\
			mx_create_route_node.c\
			mx_elements_of_line.c\
			mx_error_0.c\
			mx_error_1.c\
			mx_error_2.c\
			mx_error_3.c\
			mx_error_4.c\
			mx_error_5.c\
			mx_error_handler.c\
			mx_int_array_extender.c\
			mx_is_in_list.c\
			mx_list_value_validator.c\
			mx_make_matrix.c\
			mx_make_unique_cities_array.c\
			mx_number_of_unique_cities.c\
			mx_outer_array_recursion_editor.c\
			mx_output.c\
			mx_printer.c\
			mx_push_route_back.c\
			mx_push_route_front.c\
			mx_r_list_reverse.c\
			mx_sort_route_list.c\
			mx_sort_route_list2.c\

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: $(LMXD) $(NAME)

$(FILE:a/%=%)

#install: $(LMXA) $(NAME)

$(NAME): $(LMXA) $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXD): $(LMXA)

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all