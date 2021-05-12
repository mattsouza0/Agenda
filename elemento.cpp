#include "elemento.h"
namespace matt {
Elemento::Elemento():
    proximo(nullptr),
    anterior(nullptr)
{

}
Elemento::Elemento(Pessoa *cont):
    proximo(nullptr),
    anterior(nullptr)
{
    setContato(cont);
}

}
