#include <iostream>
#include <string>

#include "./FilaAtendimento.hpp"
#include "../Cliente/Cliente.hpp"

Celula::Celula() {
    set_proxima(nullptr);
    set_anterior(nullptr);
    set_valor(*(new Cliente()));
}

Celula::Celula(Cliente valor) {
    set_proxima(nullptr);
    set_anterior(nullptr);
    set_valor(valor);
}

Celula::Celula(Celula* proxima, Celula* anterior) {
    set_proxima(proxima);
    set_anterior(anterior);
    set_valor(*(new Cliente()));
}

Celula::Celula(Celula* proxima, Celula* anterior, Cliente valor) {
    set_proxima(proxima);
    set_anterior(anterior);
    set_valor(valor);
}

void Celula::set_proxima(Celula* proxima) {
    this->proxima = proxima;
    return;
}

Celula* Celula::get_proxima() const {
    return proxima;
}

void Celula::set_anterior(Celula* anterior) {
    this->anterior = anterior;
    return;
}

Celula* Celula::get_anterior() const {
    return anterior;
}

void Celula::set_valor(Cliente valor) {
    this->valor = valor;
    return;
}

Cliente Celula::get_valor() const {
    return valor;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    inicio = new Celula();
    fim = new Celula();

    inicio->set_proxima(fim);
    fim->set_anterior(inicio);
    tamanho = 0;
}

bool ListaDuplamenteEncadeada::esta_vazia() const {
    return (inicio->proxima == fim && fim->anterior == inicio);
}

void ListaDuplamenteEncadeada::adicionar_ao_fim(const Cliente valor) {
    Celula* novaCelula = new Celula(valor);

    Celula* penultimaCelula = fim->get_anterior();
    penultimaCelula->set_proxima(novaCelula);

    novaCelula->set_anterior(penultimaCelula);
    novaCelula->set_proxima(fim);

    fim->set_anterior(novaCelula);
    tamanho++;

    return;
}

void ListaDuplamenteEncadeada::adicionar_ao_comeco(const Cliente valor) {
    Celula* novaCelula = new Celula(valor);

    Celula* segundaCelula = inicio->get_proxima();
    segundaCelula->set_anterior(novaCelula);

    novaCelula->set_proxima(segundaCelula);
    novaCelula->set_anterior(inicio);

    inicio->set_proxima(novaCelula);
    tamanho++;

    return;
}

void ListaDuplamenteEncadeada::adicionar_antes(const Cliente valor, const int senhaReferencia) {
    Celula* posterior = nullptr;
    for(posterior = inicio->get_proxima(); posterior != fim; posterior = posterior->get_proxima()) {
        if(posterior->get_valor().get_senha() == senhaReferencia) {
            break;
        }
    }

    Celula* anterior = posterior->get_anterior();
    Celula* novaCelula = new Celula(valor);

    anterior->set_proxima(novaCelula);
    posterior->set_anterior(novaCelula);

    novaCelula->set_anterior(anterior);
    novaCelula->set_proxima(posterior);

    tamanho++;
    return;
}

void ListaDuplamenteEncadeada::adicionar_depois(const Cliente valor, const int senhaReferencia) {
    Celula* anterior = nullptr;
    for(anterior = inicio->get_proxima(); anterior != fim; anterior = anterior->get_proxima()) {
        if(anterior->get_valor().get_senha() == senhaReferencia) {
            break;
        }
    }

    Celula* posterior = anterior->get_proxima();
    Celula* novaCelula = new Celula(valor);

    anterior->set_proxima(novaCelula);
    posterior->set_anterior(novaCelula);

    novaCelula->set_anterior(anterior);
    novaCelula->set_proxima(posterior);

    tamanho++;
    return;
}

void ListaDuplamenteEncadeada::remover(const Cliente valor) {
    Celula* alvo = nullptr;
    for(alvo = inicio->get_proxima(); alvo != fim; alvo = alvo->get_proxima()) {
        if(alvo->get_valor().get_senha() == valor.get_senha()) {
            break;
        }
    }

    if(alvo == fim) {
        return;
    }

    Celula* anterior = alvo->get_anterior();
    Celula* posterior = alvo->get_proxima();

    anterior->set_proxima(posterior);
    posterior->set_anterior(anterior);

    delete alvo;
    return;
}

void ListaDuplamenteEncadeada::limpar() {
    Celula* proximaReferencia = nullptr;
    
    for(Celula* iterador = inicio->get_proxima(); iterador != fim; iterador = proximaReferencia) {
        proximaReferencia = iterador->get_proxima();
        delete iterador;
    }

    inicio->set_proxima(fim);
    fim->set_anterior(inicio);
    tamanho = 0;

    return;
}

Cliente ListaDuplamenteEncadeada::get_elemento_em(const unsigned int posicao) const {
    if(posicao >= get_tamanho()) {
        return *(new Cliente());
    }

    Celula* alvo = inicio->get_proxima();
    for(unsigned int i = 0; i < posicao; i++) {
        alvo = alvo->get_proxima();
    }

    return alvo->get_valor();
}

unsigned int ListaDuplamenteEncadeada::get_tamanho() const {
    return tamanho;
}

/*void FilaAtendimento::adicionar_cliente(const std::string nome, const unsigned int idade) {

}

Cliente* FilaAtendimento::chamar_cliente() {

}

void FilaAtendimento::estimativa_tempo_espera(const int senha) const {

}

void FilaAtendimento::imprimir_fila() const {

}

bool FilaAtendimento::esta_vazia() const {

}*/
