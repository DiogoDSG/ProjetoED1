#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include "stack.h"

typedef struct _image {
    int width;
    int height;
    png_byte color_type;
    png_byte bit_depth;
    png_bytep* row_pointers;
}Image;

/* Cria uma estrutura de imagem. */
Image* create_image();

/* Desaloca uma imagem. */
void destroy_image(Image* img);

/* Abre e le a imagem de um arquivo. */
void read_img(char* filename, Image* img);

/* Salva as alteracoes em um novo arquivo png. */
void write_img(char* filename, Image* img);

/* Normaliza a imagem para preto e branco e preenche uma matrix */
/* sendo 1 para preto e 0 para branco */
void normalize_img(Image* img);

/* Desenha o caminho do labirinto */
void draw_path(Image* img, Stack* path);