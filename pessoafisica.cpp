#include "pessoafisica.h"

namespace matt {
PessoaFisica::PessoaFisica()
{
}
PessoaFisica::PessoaFisica(QString nome, QString endereco, QString email, QString cpf,int dataNascimento, QString estadoCivil)
{
    setNome(nome);
    setEndereco(endereco);
    setEmail(email);
    setIdentificador(cpf);
    setDataNascimento(dataNascimento);
    setEstadoCivil(estadoCivil);
}
void PessoaFisica::setIdentificador(QString cpf){
    if(cpf == "")
       throw QString("CPF Invalido");
    int CadPF[11];
    QString aux;
    for(int i = 0;i< 11;i++){
        aux = cpf[i];
        CadPF[i] = aux.toInt();
    }
    int dg1,dg2,aux2=0;
    for(char j=0;j<9;j++)
        aux2+=CadPF[j]*(10-j);
    aux2%=11;
    if(aux2 < 2){
        dg1 = 0;
    }else{
        dg1=11-aux2;
    }
    aux2=0;
    for(char k=0;k<10;k++)
        aux2+=CadPF[k]*(11-k);
    aux2%=11;
    if(aux2 < 2){
        dg2 = 0;
    }else{
        dg2 = 11-aux2;
    }

    if(dg1 != CadPF[9] || dg2 != CadPF[10])
        throw QString("CPF INVALIDO");

    this->cpf=cpf;
}


void PessoaFisica::setDataNascimento(int dataNascimento){
    if(dataNascimento <= 0)
        throw QString("DATA DE NASCIMENTO INVALIDA");
    this->dataNascimento=dataNascimento;
}

void PessoaFisica::setEstadoCivil(QString estadoCivil){
    if(estadoCivil == "")
        throw QString("ESTADO CIVIL INVALIDO");
    this->estadoCivil=estadoCivil;
}

QString PessoaFisica::print() {
    QString saida = "\nNome: " + getNome();
    saida += "\nEndereco: " + getEndereco();
    saida += "\nEmail: " + getEmail();
    saida += "\nCPF: " + getIdentificador();
    saida += "\nData de Nascimento: " + QString::number(dataNascimento);
    saida +="\nEstado Civil: " + estadoCivil + "\n";
    return saida;
}

}
