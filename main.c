#include "mazeSolver.h"
#define IMAGE_1 "./images/maze50x50.png"
#define IMAGE_2 "./images/maze100x100.png"

/* Menu de escolha de imagem a ser carregada. */
Image* loadImageMenu();

/* Nas imagens o ponto de inicio e o vermelho e o de fim e o azul. */
int main() {

    // inicia imagem
    Image* img = loadImageMenu();
    
    // normaliza e salva a matrix com o labirinto
    Point start, end;
    normalize_img(img, &start, &end);

    // acha e salva o caminho em "caminho.png"
    solveMaze(img, start, end);

    // desaloca a imagem;
    destroy_image(img);

    return 0;
}


Image* loadImageMenu(){
    Image* img = create_image();
    
    int option = 0;
    printf("Digite 1 para achar o caminho do labirinto 50x50.\nDigite 2 para achar o caminho do labirinto 100x100.\n");
    scanf("%d", &option);
    if(option == 1)
        read_img(IMAGE_1, img);
    else if(option == 2)
        read_img(IMAGE_2, img);
    else{
        printf("Opcao invalida!");
        return NULL;
    }

    return img;
}
