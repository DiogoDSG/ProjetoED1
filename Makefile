all:
	(cd ./zlib && ./configure)
	(cd ./libpng && ./configure)
	gcc -o labirinto main.c Image.c 
clean:
	rm labirinto