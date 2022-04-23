#ifndef Drone_H
#define Drone_H

#include <vector>
#include <string>

#include "../Mensagem/Mensagem.hpp"
#include "../Ponto2D/Ponto2D.hpp"

typedef struct Drone {
    int id;
    double energia;
    double raioComunicacao;
    Ponto2D posicaoAtual;
    std::vector<Mensagem> mensagens;
    unsigned int indexSalvarMensagem;

    Drone();
    Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao);

    void mover(const double velocidade, const double orientacaoVelocidade, const double tempo);
    double calcularDistancia(const Drone& drone) const;
    bool estaNoAlcance(const Drone& drone) const;

    void broadcastMensagem(const std::vector<Drone>& drones);
    void salvarMensagem(const Mensagem mensagem);
    void deletarMensagen(const Mensagem& mensagem);
    void limparMensagens();

    void imprimirMensagensRecebidas() const;
    void imprimirStatus() const;

    void setId(const int id);
    int getId() const;

    void setEnergia(const double energia);
    double getEnergia() const;

    void setRaioCamunicacao(const double raioComunicacao);
    double getRaioComunicacao() const;

    void setPosicaoAtual(const Ponto2D posicaoAtual);
    Ponto2D getPosicaoAtual() const;

    std::vector<Mensagem> getMensagens() const;
} Drone;

#endif