all:
	gcc -o labirinto main.c Image.c estruturas.c labirinto.c -lpng
clean:
	rm labirinto