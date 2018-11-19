#include "Interface.h"

Interface::Interface(){
    Imprimeinterface();
    abre_.Abrearquivo();
    abre_.Contagemlinhas();
    abre_.Definerestricoes();
    abre_.Tratamento();
    abre_.Fechaaquivo();

}

void Interface::Imprimeinterface(){
    cout << "-----------------------------------------" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||BEM VINDO AO SENSOR|||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "-----------------------------------------" << endl;
}

Interface::~Interface(){

}
