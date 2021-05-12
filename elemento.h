#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <pessoa.h>
namespace matt {
class Elemento
{
private:
    Pessoa* contato;
    Elemento* proximo;
    Elemento* anterior;
public:
    Elemento();
    Elemento(Pessoa* cont);

    Pessoa* getContato()const{return contato;}
    void setContato(Pessoa *cont){this->contato = cont;}

    Elemento* getProximo(){return  proximo;}
    void setProximo(Elemento *objeto){this->proximo = objeto;}

    Elemento* getAnterior(){return anterior;}
    void setAnterior(Elemento *objeto){this->anterior = objeto;}
};
}
#endif // ELEMENTO_H
