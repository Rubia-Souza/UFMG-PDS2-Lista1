#include <iostream>
#include <vector>
#include <string>

#include "./Pixel.hpp"

std::vector<std::string> formatar_cores(const unsigned short int red, const unsigned short int green, const unsigned short int blue);

Pixel::Pixel() {
    set_rgb(0, 0, 0);
}

Pixel::Pixel(const unsigned short int red, const unsigned short int green, const unsigned short int blue) {
    set_rgb(red, blue, green);
}

void Pixel::print() const {
    std::vector<std::string> cores = formatar_cores(get_red(), get_blue(), get_green());

    std::cout << cores[0] << cores[1] << cores[2];

    return;
}

std::vector<std::string> formatar_cores(const unsigned short int red, const unsigned short int green, const unsigned short int blue) {
    std::vector<std::string> cores;
    cores.push_back(std::to_string(red));
    cores.push_back(std::to_string(green));
    cores.push_back(std::to_string(blue));

    std::string cores_formatadas = "";

    for(unsigned int i = 0; i < cores.size(); i++) {
        if(cores[i].size() == 1) {
            cores[i].insert(0, "00");
        }
        else if(cores[i].size() == 2) {
            cores[i].insert(0, "0");
        }
    }

    return cores;
}

void Pixel::set_rgb(const unsigned short int red, const unsigned short int green, const unsigned short int blue) {
    set_red(red);
    set_blue(blue);
    set_green(green);

    return;
}

std::vector<unsigned short int> Pixel::get_rgb() const {
    std::vector<unsigned short int> cores;

    cores.push_back(get_red());
    cores.push_back(get_green());
    cores.push_back(get_blue());

    return cores;
}

unsigned short int Pixel::get_tom_medio() const {
    return (red + blue + green) / 3;
}

void Pixel::set_red(const unsigned short int red) {
    this->red = red;
    return;
}

unsigned short int Pixel::get_red() const {
    return red;
}

void Pixel::set_green(const unsigned short int green) {
    this->green = green;
    return;
}

unsigned short int Pixel::get_green() const {
    return green;
}

void Pixel::set_blue(const unsigned short int blue) {
    this->blue = blue;
    return;
}

unsigned short int Pixel::get_blue() const {
    return blue;
}
