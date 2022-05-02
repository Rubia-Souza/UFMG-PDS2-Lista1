#include <vector>

#include "./Pixel.hpp"

Pixel::Pixel() {
    set_rgb(0, 0, 0);
}

Pixel::Pixel(const unsigned short int red, const unsigned short int green, const unsigned short int blue) {
    set_rgb(red, blue, green);
}

void Pixel::print() const {}

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
