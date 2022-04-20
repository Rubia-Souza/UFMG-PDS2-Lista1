#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>

#include "Ponto2D.hpp"

Ponto2D::Ponto2D() {
    setX(0.0);
    setY(0.0);
}

Ponto2D::Ponto2D(const double x, const double y) {
    setX(x);
    setY(y);
}

double Ponto2D::calcularDistancia(const Ponto2D& ponto) const {
    double distanciaHorizontal = getX() - ponto.getX();
    double distanciaVertical = getY() - ponto.getY();

    return sqrt(pow(distanciaHorizontal, 2) + pow(distanciaVertical, 2));
}

std::string Ponto2D::getDados() const {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << "[" << getX() << "," << getY() << "]";
    
    return stream.str();
}

void Ponto2D::setX(const double x) {
    this->x = x;
    return;
}

double Ponto2D::getX() const {
    return this->x;
}

void Ponto2D::setY(const double y) {
    this->y = y;
    return;
}

double Ponto2D::getY() const {
    return this->y;
}
