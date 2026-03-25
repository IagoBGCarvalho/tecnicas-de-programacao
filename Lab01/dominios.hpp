#include <string>
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

using namespace std;

class CodigoCliente {
    private:
        static const int LIMITE = 5;
        int valor;
        bool validar(int);
    public:
        bool setValor(int);
        int getValor();
};

inline int CodigoCliente::getValor(){
    return valor;
}

class Estado{
    private:
        string estadoAtual;
        static const string AFAZER; // Apenas tipos primitivos podem ser incializados nas classes (int, bool e char)!!
        static const string FAZENDO;
        static const string FEITO;
        bool validar(string);
    public:
        bool setEstado(string);
        string getEstado();
};

inline string Estado::getEstado(){
    return estadoAtual;
}

#endif // DOMINIOS_HPP_INCLUDED
