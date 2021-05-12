#include "agenda.h"
namespace matt {
Agenda::Agenda():
    primeiro(nullptr),
    ultimo(nullptr),
    qtd(0)
{

}

void Agenda::inserirContato(Pessoa *cntt){
    try {
        Elemento *aux = new Elemento(cntt);
        if(qtd==0){
            primeiro=ultimo=aux;
            qtd++;
        }
        else if (primeiro->getContato()->getIdentificador() >= aux->getContato()->getIdentificador()) {//insere no inicio
            aux->setProximo(primeiro);
            primeiro->setAnterior(aux);
            primeiro = aux;
            qtd++;
        }else{
            Elemento *iterator = primeiro;
            while(iterator != nullptr && aux->getContato()->getIdentificador() >= iterator->getContato()->getIdentificador()){
                iterator = iterator->getProximo();
            }
            if(iterator == nullptr){//insere no fim
                ultimo->setProximo(aux);
                //aux->setAnterior(iterator); ERRO ESTAVA AQUI
                aux->setAnterior(ultimo);
                ultimo = aux;
                qtd++;
            }else{//insere no meio
                aux->setAnterior(iterator->getAnterior());
                aux->setProximo(iterator);
                iterator->getAnterior()->setProximo(aux);
                iterator->setAnterior(aux);
                qtd++;
            }
        }
    } catch (std::bad_alloc) {
        throw QString("Memória insuficiente");
    }
}

QString Agenda::buscarContato(QString doc){
    QString saida;
    Elemento *aux=primeiro;
    while(aux!=nullptr){
        if(aux->getContato()->getIdentificador() == doc){
            saida += aux->getContato()->print();
        }
        aux=aux->getProximo();
    }
    return saida;
    if(aux == nullptr)
        throw QString("Contato não encontrado");
}

Pessoa* Agenda::removerContato(QString doc){
    Pessoa* saida;
    if(primeiro == nullptr)
        throw  QString("Operação Invalida. Agenda Vazia");
    for(Elemento*i=primeiro;i!=nullptr;i=i->getProximo()){
        if(doc == i->getContato()->getIdentificador()){
            Elemento* aux;
            if(i->getAnterior() == nullptr){//inicio
                aux = primeiro;
                primeiro = primeiro->getProximo();
                primeiro->setAnterior(nullptr);
                saida = aux->getContato();
                aux->setProximo(nullptr);
                qtd--;
                return saida;
            }
            else if (i->getProximo() == nullptr) {//fim
                aux = ultimo;
                ultimo = ultimo->getAnterior();
                ultimo->setProximo(nullptr);
                saida = aux->getContato();
                aux->setAnterior(nullptr);
                qtd--;
                return saida;
            }else{//meio
                saida = i->getContato();
                i->getAnterior()->setProximo(i->getProximo());
                i->getProximo()->setAnterior(i->getAnterior());
                qtd--;
                return saida;
            }
        }
    }
}

QString Agenda::listar(){
    QString saida;
    Elemento *aux = primeiro;
    if(aux == nullptr)
        throw QString("Operação Invalida. Agenda Vazia");
    while(aux != nullptr){
        saida += aux->getContato()->print();
        saida += "**********************************";
        aux = aux->getProximo();
    }
    saida += "\n";
    return saida;
}

}
