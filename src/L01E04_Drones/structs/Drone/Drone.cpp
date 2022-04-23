#include <iostream>
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
    this->mensagens = new std::string[TAMANHO_MAXIMO_BUFFER_MENSAGENS];
    this->limparMensagens();
    indexSalvarMensagem = 0;
}

Drone::Drone(const int id, const Ponto2D posicaoAtual, const double raioComunicacao) {
    setId(id);
    setEnergia(QUANTIDADE_PADRAO_ENERGIA_INICIAL);
    setPosicaoAtual(posicaoAtual);
    setRaioCamunicacao(raioComunicacao);
    this->mensagens = new std::string[TAMANHO_MAXIMO_BUFFER_MENSAGENS];
    this->limparMensagens();
    indexSalvarMensagem = 0;
}

void Drone::mover(const double velocidade, const double orientacaoVelocidade, const double tempo) {

}

double Drone::calcularDistancia(const Drone& drone) const {
    return this->getPosicaoAtual().calcularDistancia(drone.getPosicaoAtual());
}

void Drone::broadcastMensagem(Drone** drones, const unsigned int qtdDrones) {
    std::string mensagem = criarMensagem(*this);

    for(unsigned int i = 0; i < qtdDrones; i++) {
        if(estaNoAlcance(*drones[i])) {
            drones[i]->salvarMensagem(mensagem);
        }
    }

    return;
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

void Drone::salvarMensagem(const std::string mensagem) {
    if(indexSalvarMensagem >= TAMANHO_MAXIMO_BUFFER_MENSAGENS) {
        indexSalvarMensagem = 0;
    }

    this->mensagens[indexSalvarMensagem] = mensagem;
    indexSalvarMensagem++;

    return;
}

void Drone::deletarMensagen(const std::string& mensagem) {
    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        if(mensagens[i] == mensagem) {
            mensagens[i] = "";
        }
    }

    return;
}

void Drone::limparMensagens() {
    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        mensagens[i] = "";
    }

    return;
}

void Drone::imprimirMensagensRecebidas() const {
    std::cout << "Mensagens de " << this->getId() << "\n";

    for(unsigned int i = 0; i < TAMANHO_MAXIMO_BUFFER_MENSAGENS; i++) {
        if(getMensagens()[i] != "") {
            std::cout << mensagens[i] << "\n";
        }
    }

    return;
}

void Drone::imprimirStatus() const {
    std::cout << getId() << "\t" << getPosicaoAtual().getX() << "\t" << getPosicaoAtual().getY() << "\t" << getEnergia() << "\n";
    return;
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

std::string* Drone::getMensagens() const {
    return this->mensagens;
}
