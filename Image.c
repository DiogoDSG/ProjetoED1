#include "Image.h"

//____________________________________________________________________________________________
Image* create_image() {
    Image* new_img = (Image*)malloc(sizeof(Image));
    new_img->width = 0;
    new_img->height = 0;
    new_img->row_pointers = NULL; // é alocado apos receber as dimensoes da imagem na função read_img
    return new_img;
}

//____________________________________________________________________________________________
void destroy_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        free(img->row_pointers[y]);
    }
    free(img->row_pointers);
    free(img);
}

//____________________________________________________________________________________________
void read_img(char* filename, Image* img) {
    // Inicia variaveis pertinentes a lib png
    FILE* fp = fopen(filename, "rb");
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();
    png_infop info = png_create_info_struct(png);
    if (!info) abort();
    if (setjmp(png_jmpbuf(png))) abort();
    png_init_io(png, fp);
    png_read_info(png, info);

    // inicia variaveis da estrutura Image
    img->width = png_get_image_width(png, info);
    img->height = png_get_image_height(png, info);
    img->color_type = png_get_color_type(png, info);
    img->bit_depth = png_get_bit_depth(png, info);

    // 8 bits por canal
    if (img->bit_depth == 16)
        png_set_strip_16(png);

    // definiçoes da paleta de cors
    if (img->color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    if (img->color_type == PNG_COLOR_TYPE_GRAY && img->bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if (png_get_valid(png, info, PNG_INFO_tRNS)) 
        png_set_tRNS_to_alpha(png);

    if (img->color_type == PNG_COLOR_TYPE_RGB || img->color_type == PNG_COLOR_TYPE_GRAY || img->color_type == PNG_COLOR_TYPE_PALETTE) 
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if (img->color_type == PNG_COLOR_TYPE_GRAY || img->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    // atualiza definiçoes
    png_read_update_info(png, info);

    // aloca ponteiro para colunas
    if (img->row_pointers) exit(1); // se o ponteiro para colunas não entiver vazio
    img->row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * img->height);
    for (int y = 0; y < img->height; y++) {
        img->row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png, info));
    }

    // inicia ponteiro para colunas
    png_read_image(png, img->row_pointers);
    fclose(fp);
    png_destroy_read_struct(&png, &info, NULL);
}

//____________________________________________________________________________________________
void write_img(char* filename, Image* img) {
    // inicia novo arquivo png
    FILE* fp = fopen(filename, "wb");
    if (!fp) abort();

    // inicia variaveis para escrever novo arquivo
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) abort();
    png_infop info = png_create_info_struct(png);
    if (!info) abort();
    if (setjmp(png_jmpbuf(png))) abort();
    png_init_io(png, fp);

    // Image Definitions
    png_set_IHDR(png, info, img->width, img->height, 8, PNG_COLOR_TYPE_RGBA, 
        PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    // escreve a imagem alterada no novo arquivo
    png_write_info(png, info);
    if (!img->row_pointers) abort();
    png_write_image(png, img->row_pointers);
    png_write_end(png, NULL);
    
    // fecha arquivo
    fclose(fp);
    png_destroy_write_struct(&png, &info);
}

//____________________________________________________________________________________________
void normalize_img(Image* img) {
    for (int y = 0; y < img->height; y++) {
        png_bytep row = img->row_pointers[y];
        for (int x = 0; x < img->width; x++) {
            png_bytep px = &(row[x * 4]);
            // verifica se é vermelho ou azul
            if ((px[0] > 100 && px[1] < 80 && px[2] < 80) || (px[2] > 100 && px[1] < 80 && px[0] < 80)) {
                px[0] = 0; px[1] = 255; px[2] = 0;
            }
            // verifica se é preto
            else if (px[0] < 130 && px[1] < 130 && px[2] < 130) {
                px[0] = 0; px[1] = 0; px[2] = 0;
            }
            // se não for preto, vermelho ou azul preenche com branco
            else {
                px[0] = 255; px[1] = 255; px[2] = 255;
            }
        }
    }
}