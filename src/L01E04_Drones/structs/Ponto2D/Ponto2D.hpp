#ifndef Ponto2D_H
#define Ponto2D_H

#include <string>

typedef struct Ponto2D {
    double x;
    double y;

    Ponto2D();
    Ponto2D(const double x, const double y);

    void setX(const double x);
    double getX() const;

    void setY(const double y);
    double getY() const;

    double calcularDistancia(const Ponto2D& ponto) const;
    std::string getDados() const;
} Ponto2D;

#endif