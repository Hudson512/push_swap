CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = function_aux.o list_function.o push_swap.o
DEPS = header.h

%.o: %.c $(DEPS)
    $(CC) $(CFLAGS) -c -o $@ $<

push_swap: $(OBJ)
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f *.o push_swap
