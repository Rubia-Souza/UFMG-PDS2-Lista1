#include "./Imagem.hpp"
#include "../Pixel/Pixel.hpp"

Imagem::Imagem() {

}

void Imagem::initialize_image(const unsigned int width, const unsigned int height) {

}

void Imagem::fill(const unsigned int linha, const unsigned int coluna, const std::string& pixel) {

}

void Imagem::to_grayscale() {

}

void Imagem::grayscale_thresholding(const unsigned int limiar) {

}

void Imagem::show() const {
    
}

void Imagem::set_width(const unsigned int width) {
    this->width = width;
    return;
}

unsigned int Imagem::get_width() const {
    return width;
}

void Imagem::set_height(const unsigned int height) {
    this->height = height;
    return;
}

unsigned int Imagem::get_height() const {
    return height;
}
