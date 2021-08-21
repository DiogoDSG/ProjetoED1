#include "Image.h"

/*
void printImgMatrix(Image* img){
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width; j++)
            printf("%3d", img->matrix[j][i]);

        printf("\n");
    }
}
*/
int validPos(Image* img, Point curr){
    if(curr.x >= 0 && curr.y >= 0 && curr.x < img->width &&
        curr.y < img->height && img->matrix[curr.x][curr.y] != 1){
        return 1;
    }
    else
        return 0;
}


int explore(Image* img, Point curr, Stack* path, List* visited){
    
    
    if (validPos(img, curr)) {
        Point newpoint = curr;
        if(img->matrix[curr.x][curr.y] == END){
            path = push(path, curr);
            //print_stack(path);
            draw_path(img, path);
            write_img("caminho.png", img);
            return 1;
        }

        if (isInList(visited, curr)) {
            return 0;
        }

        visited = enqueue(visited, curr);
        path = push(path, curr);

        newpoint.x = curr.x + 1;
        newpoint.y = curr.y;
        if (explore(img, newpoint, path, visited))
            return 1;

        newpoint.x = curr.x - 1;
        newpoint.y = curr.y;
        if (explore(img, newpoint, path, visited))
            return 1;

        newpoint.x = curr.x;
        newpoint.y = curr.y + 1;
        if (explore(img, newpoint, path, visited))
            return 1;

        newpoint.x = curr.x;
        newpoint.y = curr.y - 1;
        if (explore(img, newpoint, path, visited))
            return 1;
        
        if(path->next != NULL)
            *path = *pop(path);
        return 0;
    }
    return 0;

    /*
    printf("ponto atual : %d : %d\n", curr.x, curr.y);
    if(validPos(img, curr)){
        Point newpoint = curr;
        if(img->matrix[curr.x][curr.y] == END){
            path = push(path, curr);
            draw_path(img, path);
            write_img("caminho.png", img);
            return 1;
        }
        if(isInList(visited, curr)){
            printf("\nvisited:\n");
            print_queue(visited);
            return 0;
        }

        int response = 0;
        scanf("%d",&response);
        visited = enqueue(visited, curr);
        path = push(path, curr);

        if(response == 1)
        {
            print_stack(path);
        }
        else if(response == 2){
            draw_path(img, path);
            write_img("caminho.png", img);
            system("clear");
        }
        getchar();

        newpoint.x = curr.x + 1; 
        newpoint.y = curr.y;
        if(explore(img, newpoint, path, visited))
            return 1;

        newpoint.x = curr.x - 1; 
        newpoint.y = curr.y;
        if(explore(img, newpoint, path, visited))
            return 1;
        
        newpoint.x = curr.x;
        newpoint.y = curr.y + 1; 
        if(explore(img, newpoint, path, visited))
            return 1;

        newpoint.x = curr.x;
        newpoint.y = curr.y - 1; 
        if(explore(img, newpoint, path, visited))
            return 1;

        *path = *pop(path);
        return 0;
    }
    printf("back");
    return 0;*/
}

int pathFind(Image* img, Stack* path){
    Point p;
    p.x = 0;
    p.y = 0;
    List* visited = NULL;
    if(explore(img, p, path, visited)){
        printf("has solution");
        return 1;
    }
    else {
        printf("no solution");
        path = NULL;
        return 0;
    }
}
