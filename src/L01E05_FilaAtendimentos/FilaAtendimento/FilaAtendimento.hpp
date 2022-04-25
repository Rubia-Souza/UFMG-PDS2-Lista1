#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H

#include <string>

#include "../Cliente/Cliente.hpp"

struct FilaAtendimento {
    int ultima_senha_gerada;

    FilaAtendimento();

    void adicionar_cliente(const std::string nome, const unsigned int idade);
    Cliente* chamar_cliente();
    void estimativa_tempo_espera(const int senha);
    void imprimir_fila() const;

    bool esta_vazia() const;
};

#endif
