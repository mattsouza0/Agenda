#ifndef AGENDA_H
#define AGENDA_H
#include <QString>
#include <elemento.h>
namespace matt {
class Agenda
{
private:
    Elemento* primeiro;
    Elemento* ultimo;
    int qtd;
public:
    Agenda();
    void inserirContato(Pessoa* cntt);
    Pessoa* removerContato(QString doc);
    QString buscarContato(QString doc);
    int getQtd(){return qtd;}
    QString listar();
};
}
#endif // AGENDA_H
