SHELL =		/bin/sh
NAME =		so_long

.SUFFIXES =	.c .o .h .dylib

SRCDIR =	src
INCDIR =	inc
LIBDIR =	lib\
			.
OBJDIR =	.obj

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			$(addprefix exception/,\
				exception\
				bad_alloc\
				invalid_arguments\
				invalid_map\
				runtime_error)\
			$(addprefix parsing/,\
				get_map)\
			$(addprefix rendering/,\
				render_map)\
			$(addprefix utils/,\
				init_image\
				make_color)\
			$(addprefix cleaning/,\
				mlx_clear)\
			$(addprefix get_next_line/,\
				get_next_line\
				get_next_line_utils)\
			main)
INC =		$(addsuffix $(word 3, $(.SUFFIXES)),\
			get_next_line\
			mlx\
			exception\
			so_long)
LIB =		mlx\
			ft
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 2, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -I $(INCDIR) -fsanitize=address -g3
LCFLAGS =	$(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIB))

####    COLORS    ####
KNRM =		\x1B[0m
KRED =		\x1B[31m
KGRN =		\x1B[32m
KYEL =		\x1B[33m
KBLU =		\x1B[34m
KMAG =		\x1B[35m
KCYN =		\x1B[36m
KWHT =		\x1B[37m
######################

all: $(OBJDIR) $(NAME)
	@printf "$(KGRN)\`$(NAME)\` is up to date.\n$(KNRM)"

$(OBJDIR):
	@printf "$(KYEL)➤ "
	mkdir -p $@/exception $@/parsing $@/rendering $@/utils $@/cleaning $@/get_next_line
	@printf "$(KNRM)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@printf "$(KCYN)[  Linking  ]\n➤ "
	$(CC) $(CFLAGS) $^ -o $@ $(LCFLAGS)
	@printf "$(KNRM)"

$(OBJDIR)/%$(word 2, $(.SUFFIXES)): $(SRCDIR)/%$(word 1, $(.SUFFIXES)) $(addprefix $(INCDIR)/, $(INC))
	@printf "$(KMAG)[  Compiling  ]\n➤ "
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(KNRM)"

clean:
	@printf "$(KRED)➤ "
	rm -rf $(OBJDIR)
	@printf "$(KNRM)"

fclean: clean
	@printf "$(KRED)➤ "
	rm -f $(NAME)
	@printf "$(KNRM)"

re: fclean all
