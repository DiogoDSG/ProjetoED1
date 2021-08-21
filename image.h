#include <png.h>
#include "stdio.h"
#include "stdlib.h"

#define END 99

/* Estrutura que representa um ponto. */
typedef struct _point {
    int x;
    int y;
} Point;

/* Estrutura que representa uma imagem. */
typedef struct _image {
    int width;
    int height;
    int** matrix;
    png_byte color_type;
    png_byte bit_depth;
    png_bytep* row_pointers;
}Image;

/* Cria uma estrutura de imagem. */
Image* create_image();

/* Desaloca uma imagem. */
void destroy_image(Image* img);

/* Abre e le a imagem de um arquivo. */
void read_img(const char* filename, Image* img);

/* Salva as alteracoes em um novo arquivo png. */
void write_img(const char* filename, Image* img);

/* Normaliza a imagem para preto e branco e preenche uma matrix  */
/* sendo 1 para preto e 0 para branco, pontos vermelhos ou azuis */
/* sao preenchidos com verde.                                    */
void normalize_img(Image* img, Point* start, Point* end);

/* Desenha o caminho do labirinto */
void draw_path(Image* img, int** solution);
