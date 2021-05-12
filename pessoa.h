#ifndef PESSOA_H
#define PESSOA_H

#include <QString>
namespace matt {
class Pessoa
{
private:
    QString nome;
    QString endereco;
    QString email;
public:
    Pessoa();

    void setNome(QString nome);
    QString getNome(){return nome;}

    void setEndereco(QString endereco);
    QString getEndereco(){return endereco;}

    void setEmail(QString email);
    QString getEmail(){return email;}

    virtual void setIdentificador(QString numb)=0;
    virtual QString getIdentificador()const = 0;

    virtual QString print() = 0;
};
}
#endif // PESSOA_H
