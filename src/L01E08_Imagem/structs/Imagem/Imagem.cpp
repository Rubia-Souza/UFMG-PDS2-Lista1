#include <iostream>
#include <string>
#include <vector>

#include "./Imagem.hpp"
#include "../Pixel/Pixel.hpp"

Imagem::Imagem() {
    set_width(0);
    set_height(0);
}

Imagem::Imagem(const unsigned int width, const unsigned int height) {
    initialize_image(width, height);
}

void Imagem::initialize_image(const unsigned int width, const unsigned int height) {
    clear();

    set_width(width);
    set_height(height);

    for(unsigned int i = 0; i < get_height(); i++) {
        for(unsigned int j = 0; j < get_width(); j++) {
            pixels[i].push_back(*(new Pixel()));
        }
    }
    
    return;
}

void Imagem::clear() {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        pixels[i].clear();
    }
    pixels.clear();

    return;
}

void Imagem::fill(const unsigned int linha, const unsigned int coluna, const std::string& pixel) {
    std::vector<unsigned short int> cor = get_cor_de_string(pixel);
    
    pixels[linha][coluna].set_rgb(cor[0], cor[1], cor[2]);
}

std::vector<unsigned short int> get_cor_de_string(const std::string& cor) {
    std::vector<unsigned short int> cor_rgb_separada(3);
    std::string cor_atual = "";
    
    unsigned int i = 0;
    for(char character : cor) {
        cor_atual.push_back(character);
        i++;
        
        if(i % 3 == 0) {
            cor_rgb_separada.push_back(std::stoul(cor_atual));
            cor_atual.clear();
        }
    }
    
    return cor_rgb_separada;
}

void Imagem::to_grayscale() {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        for(unsigned int j = 0; j < pixels[i].size(); j++) {
            Pixel* pixel = &pixels[i][j];
            unsigned short int tom_medio = pixel->get_tom_medio();
            pixel->set_rgb(tom_medio, tom_medio, tom_medio);
        }
    }
    
    return;
}

void Imagem::grayscale_thresholding(const unsigned int limiar) {
    
}

void Imagem::show() const {
    for(unsigned int i = 0; i < pixels.size(); i++) {
        for(unsigned int j = 0; j < pixels[i].size(); j++) {
            pixels[i][j].print();
            
            if(j < pixels[i].size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    
    return;
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
