#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "./structs/Cliente/Cliente.hpp"
#include "./structs/FilaAtendimento/FilaAtendimento.hpp"
#include "avaliacao_basica_atendimento.hpp"

#define ADICIONAR 'a'
#define CHAMAR 'c'
#define ESTIMATIVA_TEMPO 'e'
#define IMPRIMIR_FILA 'p'
#define AVALIACAO_BASICA 'b'

std::string getLine();
std::vector<string> splitString(const string& referencia, const char character_quebra);

int main() {
    FilaAtendimento* fila = new FilaAtendimento();
    std::string input = "";
    std::getline(std::cin, input);

    while(input != "") {
        std::vector<string> parametros = splitString(input, ' ');
        char comando = parametros[0][0];

        switch(comando) {
            case(ADICIONAR):{
                std::string nome = parametros[1];
                std::string idade = parametros[2];

                fila->adicionar_cliente(nome, std::stoi(idade));
                break;
            }

            case(CHAMAR): {
                fila->chamar_cliente();
                break;
            }

            case(ESTIMATIVA_TEMPO): {
                std::string senha = parametros[1];
                fila->estimativa_tempo_espera(std::stoi(senha));
                break;
            }

            case(IMPRIMIR_FILA): {
                fila->imprimir_fila();
                break;
            }

            case(AVALIACAO_BASICA): {
                avaliacao_basica();
                break;
            }
        }

        std::getline(std::cin, input);
    }    
    return 0;
}

std::string getLine() {
    std::stringstream input;
    input.clear();

    std::string temp = "";
    while(std::cin >> temp) {
        input << temp << " ";
    }

    return input.str();
}

std::vector<string> splitString(const string& referencia, const char character_quebra) {
    std::string palavra_atual = "";
    std::vector<string> string_separada;

    for(unsigned int i = 0; i < referencia.size(); i++) {
        char caracter_atual = referencia[i];
        if(caracter_atual != character_quebra) {
            palavra_atual.push_back(caracter_atual);
        }
        else {
            string_separada.push_back(palavra_atual);
            palavra_atual.clear();
        }
    }

    string_separada.push_back(palavra_atual);
    return string_separada;
}
