#include "image.h"

/* Cria e retorna uma matrix de solucoes preenchida com zeros */
int** createSolutionMatrix(Image* img);

/* Verifica se ha um caminho valido e se houver salva em "./images/caminho.png" */
void solveMaze(Image* img, Point start, Point end);

/* Procura o caminho com o uso de backtracking e salva na matriz solucao. */
int findPath(int** maze, int width, int height, int** solution, Point curr, Point end);
