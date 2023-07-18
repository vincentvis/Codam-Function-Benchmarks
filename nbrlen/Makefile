NAME = nbrlen_test

FILES = test_runner.c \
		test_helper.c \
		nbrlen_functions.c

OBJ_DIR = obj/
OBJECTS = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

DEP := $(OBJECTS:%.o=%.d)

all: $(OBJECTS)
	$(CC) -g $(OBJECTS) -O0 -o $(NAME).out

-include $(DEP)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -g -MMD -c $< -o $@

run: all
	./$(NAME).out

clean:
	$(RM) $(OBJECTS)
	$(RM) $(DEP)
	$(RM) -r $(OBJ_DIR)
