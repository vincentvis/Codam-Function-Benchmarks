NAME = strlen_test

FILES = test_runner.c \
		test_helper.c \
		strlen_functions.c

OBJ_DIR = obj/
OBJECTS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

ASM_FILE = ft_strlen_asm.s
ASM_OBJ = $(OBJ_DIR)ft_strlen_asm.o

DEP := $(OBJECTS:%.o=%.d)

all: $(OBJECTS) assembly
	$(CC) $(OBJECTS) $(ASM_OBJ) -O0 -o $(NAME).out

-include $(DEP)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -MMD -c $< -o $@

assembly:
	nasm -g -O0 -f macho64 $(ASM_FILE) -o $(ASM_OBJ)

run: all
	./$(NAME).out

clean:
	$(RM) $(OBJECTS)
	$(RM) $(ASM_OBJ)
	$(RM) $(DEP)
	$(RM) -r $(OBJ_DIR)
