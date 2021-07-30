#include "Image.h"

int main() {
    // inicia imagem
    Image* img = create_image();
    read_img("labirinto.png", img);

    // normaliza e salva a matrix com o labirinto
    normalize_img(img);

    // salva a imagem no arquivo final e desaloca a imagem
    write_img("resultado.png", img);
    destroy_image(img);

    return 0;
}