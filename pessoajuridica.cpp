#include "pessoajuridica.h"
namespace matt {
PessoaJuridica::PessoaJuridica()
{
}
PessoaJuridica::PessoaJuridica(QString nome, QString endereco, QString email, QString cnpj, long long inscricaoEstadual, QString RazaoSocial)
{
    setNome(nome);
    setEndereco(endereco);
    setEmail(email);
    setIdentificador(cnpj);
    setInscricaoEstadual(inscricaoEstadual);
    setRazaoSocial(RazaoSocial);
}

void PessoaJuridica::setIdentificador(QString numb){
    if(numb.size()!=14)
        throw QString("CNPJ INVALIDO");
    this->cnpj=numb;
}

void PessoaJuridica::setInscricaoEstadual(long long inscricaoEstadual){
    if(inscricaoEstadual <= 0)
        throw QString("INCRIÇÃO ESTADUAL INVALIDA");
    this->inscricaoEstadual=inscricaoEstadual;
}

void PessoaJuridica::setRazaoSocial(QString razaoSocial){
    if(razaoSocial == "")
        throw QString("RAZAO SOCIAL INVALIDA");
    this->RazaoSocial=razaoSocial;
}

QString PessoaJuridica::print() {
    QString saida = "\nNome: " + getNome();
    saida += "\nEndereco: " + getEndereco();
    saida +="\nEmail: " + getEmail();
    saida += "\nCNPJ: " + getIdentificador();
    saida += "\nInscrição Estadual: " + QString::number(inscricaoEstadual);
    saida += "\nRazão Social: " + RazaoSocial + "\n";
    return saida;
}

}
