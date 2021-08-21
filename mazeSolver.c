#include "mazeSolver.h"

//____________________________________________________________________________________________
int** createSolutionMatrix(Image* img) {
	int** solution;
	// aloca memoria para a matrix solucao
	solution = (int**)malloc(img->width * sizeof(int*));
	for (int i = 0; i < img->width; i++)
		solution[i] = (int*)malloc(img->height * sizeof(int*));


	// inicia a matriz com todos os elementos iguais a 0
	for (int i = 0; i < img->width; i++){
		for (int j = 0; j < img->height; j++)
			solution[i][j] = 0;
		
	}
	return solution;
}

//____________________________________________________________________________________________
void solveMaze(Image* img, Point start, Point end) {
	// verifica se os pontos inicial e final sao validos
	if (start.x >= 0 && start.y >= 0 && start.x < img->width && start.y < img->height) {
		// cria uma matrix solucao com todos os elementos iguais a 0
		int** solution = createSolutionMatrix(img);
		printf("Calculando caminho...\n");

		// procura o caminho
		if(findPath(img->matrix, img->width, img->height, solution, start, end))
			printf("Caminho encontrado!!!\n");
		else
			printf("Caminho nao encontrado!!!\n");

		// escreve o caminho na imagem
		draw_path(img, solution);
		write_img("./images/path.png", img);
	}
	else {
		printf("Inicio ou fim invalidos.\n");
	}
}

//____________________________________________________________________________________________
int findPath(int** maze, int width, int height, int** solution, Point curr, Point end)
{
	Point newPoint;
	int x = curr.x;
	int y = curr.y;
	
	// se o ponto atual for o destino 
	if ((x == end.x) && (y == end.y))
	{
		solution[x][y] = 1;
		return 1;
	}
	// verifica se o ponto atual é valido
	if (x >= 0 && y >= 0 && x < width && y < height && solution[x][y] == 0 && maze[x][y] == 0)
	{
		solution[x][y] = 1;
		// explorar baixo
		newPoint.x = x; newPoint.y = y + 1;
		if (findPath(maze,width, height, solution, newPoint,end))
			return 1;
		// explorar baixo
		newPoint.x = x + 1; newPoint.y = y;
		if (findPath(maze, width, height, solution, newPoint, end))
			return 1;
		// explorar baixo
		newPoint.x = x; newPoint.y = y - 1;
		if (findPath(maze, width, height, solution, newPoint, end))
			return 1;
		// explorar baixo
		newPoint.x = x - 1; newPoint.y = y;
		if (findPath(maze, width, height, solution, newPoint, end))
			return 1;
		
		// voltar se nao houver nenhum caminho disponivel
		solution[x][y] = 0;
		return 0;
	}
	return 0;
}