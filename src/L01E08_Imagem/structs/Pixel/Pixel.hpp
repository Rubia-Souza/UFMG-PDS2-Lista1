#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <vector>

class Pixel {
    private:
        unsigned short int red;
        unsigned short int green;
        unsigned short int blue;
    
    public:
        Pixel();
        Pixel(const unsigned short int red, const unsigned short int green, const unsigned short int blue);

        void print() const;

        void set_rgb(const std::string& cor);
        void set_rgb(const unsigned short int red, const unsigned short int green, const unsigned short int blue);
        std::vector<unsigned short int> get_rgb() const;

        void set_red(const unsigned short int red);
        unsigned short int get_red() const;

        void set_green(const unsigned short int green);
        unsigned short int get_green() const;

        void set_blue(const unsigned short int blue);
        unsigned short int get_blue() const;
    
        unsigned short int get_tom_medio() const;
};

#endif
