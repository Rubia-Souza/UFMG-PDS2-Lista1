#ifndef Drone_H
#define Drone_H

#include <string>

#include "../Ponto2D/Ponto2D.hpp"

typedef struct Drone {
    int id;
    double energia;
    double raioComunicacao;
    Ponto2D posicaoAtual;

    Drone();
    Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao);

    void mover(const double velocidade, const double orientacaoVelocidade, const double tempo);
    double calcularDistancia(const Drone& drone);
    void broadcastMensagem(const Drone& drones, const unsigned int tamanho);
    void salvarMensagem(const std::string mensagem);
    void imprimirMensagemRescebidas() const;
    void imprimirStatus() const;

    void setId(const int id);
    int getId() const;

    void setEnergia(const double energia);
    double getEnergia() const;

    void setRaioCamunicacao(const double raioComunicacao);
    double getRaioComunicacao() const;

    void setPosicaoAtual(const Ponto2D posicaoAtual);
    Ponto2D getPosicaoAtual() const;
} Drone;

#endif