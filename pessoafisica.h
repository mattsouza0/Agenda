#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include <pessoa.h>
namespace matt {
class PessoaFisica:public Pessoa
{
private:
    QString cpf;
    int dataNascimento;
    QString estadoCivil;
public:
    PessoaFisica();
    PessoaFisica(QString nome, QString endereco, QString email, QString cpf,int dataNascimento, QString estadoCivil);

    virtual QString getIdentificador()const override{return cpf;}
    virtual void setIdentificador(QString numb)override;


    void setDataNascimento(int dataNascimento);
    int getDataNascimento(){return dataNascimento;}

    void setEstadoCivil(QString estadoCivil);
    QString getEstadoCivil(){return estadoCivil;}

    virtual QString print() override;
};
}
#endif // PESSOAFISICA_H
