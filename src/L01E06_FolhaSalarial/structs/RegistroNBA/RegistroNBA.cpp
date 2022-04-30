#include <map>
#include <string>

#include "./RegistroNBA.hpp"
#include "../Time/Time.hpp"
#include "../Jogador/Jogador.hpp"

RegistroNBA::RegistroNBA() {
    times = *(new std::list<Time>());
}

void RegistroNBA::adicionar_time(const std::string nome) {
    Time* novo_time = new Time(nome);
    times.push_back(*novo_time);

    return;
}

void RegistroNBA::adicionar_jogador(const std::string nome_time, const std::string nome_jogador, const std::string posicao, const unsigned int salario) {
    if(!contem_time(nome_time)) {
        adicionar_time(nome_time);
    }

    Time* time_jogador = get_time(nome_time);
    time_jogador->adicionar_jogador(nome_jogador, posicao, salario);

    return;
}

bool RegistroNBA::contem_time(const std::string nome) const {
    for(Time time : get_times()) {
        if(time.get_nome() == nome) {
            return true;
        }
    }

    return false;
}

void RegistroNBA::imprimir_lista_jogadores_time(const std::string nome_time) const {
    Time* time_alvo = get_time(nome_time);
    time_alvo->imprimir_lista_jogadores();

    return;
}

void RegistroNBA::imprimir_folha_consolidada_time(const std::string nome_time) const {
    Time* time_alvo = get_time(nome_time);
    time_alvo->imprimir_folha_salarial_consolidada();

    return;
}

void RegistroNBA::imprimir_folha_salarial_geral() {
    times.sort([](const Time& time1, const Time& time2) {
        return time1.get_nome() < time2.get_nome();
    });

    for(Time time : times) {
        time.imprimir_folha_salarial_consolidada();
    }

    return;
}

Time* RegistroNBA::get_time(const std::string& nome) const {
    for(Time time : get_times()) {
        if(time.get_nome() == nome) {
            Time* alvo = &time;
            return alvo;
        }
    }

    return nullptr;
}

std::list<Time> RegistroNBA::get_times() const {
    return times;
}
