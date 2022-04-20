#include <list>
#include <string>

#include "Drone.hpp"
#include "../Ponto2D/Ponto2D.hpp"

Drone::Drone() {
    setId(-1);
    setEnergia(0);
    setRaioCamunicacao(0.0);
    setPosicaoAtual(*(new Ponto2D()));
}

Drone::Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao) {
    setId(id);
    setEnergia(100);
    setPosicaoAtual(posicaoAtual);
    setRaioCamunicacao(raioComunicacao);
}

void Drone::mover(const double velocidade, const double orientacaoVelocidade, const double tempo) {

}

double Drone::calcularDistancia(const Drone& drone) {

}

void Drone::broadcastMensagem(const Drone& drones, const unsigned int tamanho) {

}

void Drone::salvarMensagem(const Mensagem mensagem) {

}

void Drone::deletarMensagen(const Mensagem& mensagem) {

}

void Drone::limparMensagens() {

}

void Drone::imprimirMensagemRescebidas() const {

}

void Drone::imprimirStatus() const {

}

void Drone::setId(const int id) {
    this->id = id;
    return;
}

int Drone::getId() const {
    return id;
}

void Drone::setEnergia(const double energia) {
    this->energia = energia;
    return;
}

double Drone::getEnergia() const {
    return energia;
}

void Drone::setRaioCamunicacao(const double raioComunicacao) {
    this->raioComunicacao = raioComunicacao;
    return;
}

double Drone::getRaioComunicacao() const {
    return raioComunicacao;
}

void Drone::setPosicaoAtual(const Ponto2D posicaoAtual) {
    this->posicaoAtual = posicaoAtual;
    return;
}

Ponto2D Drone::getPosicaoAtual() const {
    return posicaoAtual;
}
