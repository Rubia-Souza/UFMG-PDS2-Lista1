#ifndef Drone_H
#define Drone_H

#include <string>

#include "../Ponto2D/Ponto2D.hpp"

typedef struct Drone {
    int id;
    double energia;
    double raioComunicacao;
    Ponto2D poiscaoAtual;

    Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao);
    void mover(const double velocidade, const double orientacaoVelocidade, const double tempo);
    double calcularDistancia(const Drone* drone);
    void broadcastMensagem(const Drone** drones, const unsigned int tamanho);
    void salvarMensagem(const std::string mensagem);
    void imprimirMensagemRescebidas();
    void imprimirStatus();
} Drone;

#endif