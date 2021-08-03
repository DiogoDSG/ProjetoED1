all:
	gcc -o labirinto main.c Image.c stack.c -lpng
clean:
	rm labirinto