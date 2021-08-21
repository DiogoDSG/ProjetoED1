#include "labirinto.h"

int main() {
    // inicia imagem
    Image* img = create_image();
    read_img("teste.png", img);

    // normaliza e salva a matrix com o labirinto
    normalize_img(img);

    // salva a imagem no arquivo final e desaloca a imagem
    write_img("resultado.png", img);

    Stack* path = create_stack();
    pathFind(img, path);
    destroy_image(img);

    return 0;
}