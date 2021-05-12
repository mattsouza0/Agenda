#include "pessoa.h"
namespace matt {
Pessoa::Pessoa():
    nome(""),
    endereco(""),
    email("")
{
}

void Pessoa::setNome(QString nome){
    if(nome == "")
        throw QString("NOME INVALIDO");
    this->nome=nome;
}

void Pessoa::setEndereco(QString endereco){
    if(endereco == "")
        throw QString("ENDERECO INVALIDO");
    this->endereco=endereco;
}

void Pessoa::setEmail(QString email){
    if(email == "")
        throw QString("EMAIL INVALIDO");
    this->email=email;
}
/*
QString Pessoa::print() const{
    QString saida = "Nome: " + nome;
    saida += "\nEndereço: " + endereco;
    saida += "\nEmail: " + email;
    return saida;
}
*/
}
