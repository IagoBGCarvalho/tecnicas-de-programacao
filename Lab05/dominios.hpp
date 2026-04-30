#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <stdexcept>

using namespace std;

class Dominio {
    private:
        Tipo valor;
        void validar(Tipo);
    public:
        void setValor(Tipo);
        Tipo getValor() const;
};

inline Tipo Dominio::getValor() const{
    return valor;
}

#endif // DOMINIOS_HPP_INCLUDED
