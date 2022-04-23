#ifndef Drone_H
#define Drone_H

#include <string>

#include "../Mensagem/Mensagem.hpp"
#include "../Ponto2D/Ponto2D.hpp"

typedef struct Drone {
    int id;
    double energia;
    double raioComunicacao;
    Ponto2D posicaoAtual;
    std::string* mensagens;
    unsigned int indexSalvarMensagem;

    Drone();
    Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao);

    void mover(const double velocidade, const double orientacaoVelocidade, const double tempo);
    double calcularDistancia(const Drone& drone) const;
    bool estaNoAlcance(const Drone& drone) const;

    void broadcastMensagem(Drone** drones, const unsigned int qtdDrones);
    void salvarMensagem(const std::string mensagem);
    void deletarMensagen(const std::string& mensagem);
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

    std::string* getMensagens() const;
} Drone;

#endif