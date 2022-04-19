#ifndef Ponto2D_H
#define Ponto2D_H

#include <string>

typedef struct Ponto2D {
    double x;
    double y;

    Ponto2D(const double x, const double y);

    double calcularDistancia(const Ponto2D* ponto);
    std::string getDados();

    void setX(const double x);
    void setY(const double y);
} Ponto2D;

#endif