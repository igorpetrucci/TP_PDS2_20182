#ifndef INTERFACE_H
#define INTERFACE_H

#include "Openarquivo.h"

class Interface{
    public:
        Interface();
        void Iniciaprograma();
        void Imprimeinterface();
        ~Interface();

    private:
    Openarquivo abre_;
};

#endif // INTERFACE_H
