#include "Interface.h"
#include <cstdlib>

Interface::Interface(){
    Iniciaprograma();
}

void Interface::Imprimeinterface(){
    cout << "-----------------------------------------" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||||||||||BEM VINDO AO SENSOR|||||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "-----------------------------------------" << endl;
}

void Interface::Iniciaprograma(){
    cout << "-----------------------------------------" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "|||||||MONITORAMENTO CONDENSADOR||||||||" << endl;
    cout << "||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "-----Deseja iniciar o programa?-----" << endl;
    cout << "           1-SIM   2-NAO           \n" << "-> ";
    bool repeticao_ = false;
    int resposta_ = 0;
        do{
            try{
                cin >> resposta_;
                if(resposta_ <= 0 || resposta_ >= 3){
                    throw Excecao("-----RESPOSTA INVALIDA!-----\n");
                }else{
                    repeticao_ = true;
                }
            }catch(Excecao &e){
                e.Out();
                cout << "--DIGITE 1 (SIM) OU 2 (NAO)--\n-> ";
            }
        }while(repeticao_ == false);

        if(resposta_ == 2){
            cout << "\n\n------ENCERRANDO O PROGRAMA------\n" << endl;
            exit(1);
        }
    abre_.Abrearquivo();
    Imprimeinterface();
    abre_.Contagemlinhas();
    abre_.Definerestricoes();
    abre_.Tratamento();
    abre_.Fechaaquivo();

}

Interface::~Interface(){

}
