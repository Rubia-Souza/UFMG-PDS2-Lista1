#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>
#include <ctime>

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
    return this->getPosicaoAtual().calcularDistancia(drone.getPosicaoAtual());
}

void Drone::broadcastMensagem(const std::vector<Drone>& drones) {
    std::string conteudoMensagem = criarMensagem(*this);
    std::string idMensagem = criarIdMensagem(*this);

    for(Drone drone : drones) {
        if(estaNoAlcance(drone)) {
            Mensagem* mensagen = new Mensagem(idMensagem, *this, drone, conteudoMensagem);
            drone.salvarMensagem(*mensagen);
        }
    }

    return;
}

std::string criarIdMensagem(const Drone& drone) {
    time_t dataHoraAtual = std::time(0);
    std::tm* dataHoraLocal = localtime(&dataHoraAtual);

    std::stringstream data;
    data.clear();
    data << dataHoraLocal->tm_year << "-" << dataHoraLocal->tm_mon << "-" << dataHoraLocal->tm_mday;

    std::stringstream hora;
    hora << dataHoraLocal->tm_hour << "-" << dataHoraLocal->tm_min << "-" << dataHoraLocal->tm_sec;

    std::stringstream id;
    id.clear();
    id << drone.getId() << "_"  << data.str() << "_" << hora.str();
    
    return id.str();
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
    if(getMensagens().size() <= 0) {
        return;
    }

    for(std::vector<Mensagem>::iterator mensagemSalva = getMensagens().begin(); mensagemSalva != getMensagens().end(); mensagemSalva++) {
        if(mensagemSalva->id == mensagem.id) {
            getMensagens().erase(mensagemSalva);
        }
    }

    return;
}

void Drone::limparMensagens() {
    getMensagens().clear();
    return;
}

void Drone::imprimirMensagemRecebidas() const {
    std::cout << "Mensagens de " << this->getId() << "\n";

    for(Mensagem mensagen : getMensagens()) {
        std::cout << mensagen.getMensagem() << "\n";
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

std::vector<Mensagem> Drone::getMensagens() const {
    return this->mensagens;
}
