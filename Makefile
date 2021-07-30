all:
	gcc -o labirinto main.c Image.c  -lpng
clean:
	rm labirinto