#include <vector>
#include <string>
#include <math.h>
#include <sstream>

#include "Drone.hpp"
#include "../Ponto2D/Ponto2D.hpp"

#define QUANTIDADE_PADRAO_ENERGIA_INICIAL 100
#define TAMANHO_MAXIMO_BUFFER_MENSAGENS 5

Drone::Drone() {
    setId(-1);
    setEnergia(0);
    setRaioCamunicacao(0.0);
    setPosicaoAtual(*(new Ponto2D()));
    this->mensagens = *(new std::vector<Mensagem>(TAMANHO_MAXIMO_BUFFER_MENSAGENS));
}

Drone::Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao) {
    setId(id);
    setEnergia(QUANTIDADE_PADRAO_ENERGIA_INICIAL);
    setPosicaoAtual(posicaoAtual);
    setRaioCamunicacao(raioComunicacao);
    this->mensagens = *(new std::vector<Mensagem>(TAMANHO_MAXIMO_BUFFER_MENSAGENS));
}

void Drone::mover(const double velocidade, const double orientacaoVelocidade, const double tempo) {

}

double Drone::calcularDistancia(const Drone& drone) const {
    double distanciaHorizontal = getPosicaoAtual().getX() - drone.getPosicaoAtual().getX();
    double distanciaVertical = getPosicaoAtual().getY() - drone.getPosicaoAtual().getY();

    return sqrt(pow(distanciaHorizontal, 2) + pow(distanciaVertical, 2));
}

void Drone::broadcastMensagem(const std::vector<Drone>& drones) {
    std::string conteudoMensagem = criarMensagem(*this);
    for(Drone drone : drones) {
        if(estaNoAlcance(drone)) {
            Mensagem* mensagen = new Mensagem(*this, drone, conteudoMensagem);
            drone.salvarMensagem(*mensagen);
        }
    }
}

std::string criarMensagem(const Drone& drone) {
    std::stringstream mensagem;
    mensagem.clear();

    mensagem << "Drone: " << drone.getId() << ", Posição: [" 
             << drone.getPosicaoAtual().getX() << "," << drone.getPosicaoAtual().getY() << "]";
    
    return mensagem.str();
}

bool Drone::estaNoAlcance(const Drone& drone) const {
    double distancia = calcularDistancia(drone);
    return distancia <= raioComunicacao;
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
