#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>

class Imagem {
    private:
        unsigned int width;
        unsigned int height;
        // TODO: Adiciona matriz de Pixels

    public:
        Imagem();

        void initialize_image(const unsigned int width, const unsigned int height);
        void fill(const unsigned int linha, const unsigned int coluna, const std::string& pixel);
        void to_grayscale();
        void grayscale_thresholding(const unsigned int limiar);
        void show() const;

        void set_width(const unsigned int width);
        unsigned int get_width() const;

        void set_height(const unsigned int height);
        unsigned int get_height() const;
};

#endif
