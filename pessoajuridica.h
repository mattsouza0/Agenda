#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <QString>
#include <pessoa.h>
namespace matt {
class PessoaJuridica:public Pessoa
{
private:
    QString cnpj;
    long long inscricaoEstadual;
    QString RazaoSocial;
public:
    PessoaJuridica();
    PessoaJuridica(QString nome, QString endereco, QString email, QString cnpj, long long inscricaoEstadual, QString RazaoSocial);

    virtual QString getIdentificador()const override{return cnpj;}
    virtual void setIdentificador(QString numb)override;

    void setInscricaoEstadual(long long inscricaoEstadual);
    long long getInscricaoEstadual(){return inscricaoEstadual;}

    void setRazaoSocial(QString razaoSocial);
    QString getRazaoSocial(){return RazaoSocial;}

    virtual QString print() override;
};
}
#endif // PESSOAJURIDICA_H
