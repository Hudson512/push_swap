
all:
	gcc -c function_aux.c -o function_aux.o
	gcc -c ft_split.c -o ft_split.o
	gcc -c list_function.c -o list_function.o
	gcc -c push_swap.c -o push_swap.o
	gcc push_swap.o list_function.o function_aux.o ft_split.o -o push_swap.exe

clean:
	rm -f *.o push_swap.exe
