#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

#include "../Drone/Drone.hpp"

typedef struct Mensagem {
    Drone remetente;
    Drone destinatario;
    std::string mensagem;

    Mensagem();
    Mensagem(const Drone remetente, const Drone destinatario, const std::string mensagem);

    void setRemetente(const Drone remetente);
    Drone getRemetente() const;

    void setDestinatario(const Drone destinatario);
    Drone getDestinatario() const;

    void setMensagem(const std::string mensagem);
    std::string getMensagem() const;
} Mensagem;

#endif
