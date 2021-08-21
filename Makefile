all:
	gcc -o maze-solver main.c image.c mazesolver.c -lpng
clean:
	rm maze-solver