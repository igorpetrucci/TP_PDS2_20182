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

    // Variaveis para a condição necessária do Do-While
    bool repeticao_ = false;
    int resposta_ = 0;
    // Realiza o tratamento de exceção caso o usuário não insira a resposta adequada
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

    // Loop Do-While para verificar se o usuário deseja
    // Realizar a leitura de outro condensador
        do{
            // Variável necessaria para resposta do usuário
            // E permitirá a repetição do programa para leitura
            // De outros arquivos
            resposta_ = 0;
            //Inicia abertura do arquivo e tratamento
            abre_.Abrearquivo();
            Imprimeinterface();
            abre_.Contagemlinhas();
            abre_.Definerestricoes();
            abre_.Tratamento();
            abre_.Fechaaquivo();
            cout << "-----------------------------------------" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "------------FIM DE LEITURA---------------" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "---Deseja monitorar outro condensador?---" << endl;
            cout << "           1-SIM   2-NAO           \n" << "-> ";
            cin >> resposta_;
            while(resposta_ <= 0 || resposta_ >= 3){
                cout << "-----RESPOSTA INVALIDA!-----\n" << "-> ";
                cin >> resposta_;
                if(resposta_ > 0 && resposta_ < 3){
                    break;
                }
            }
            if(resposta_ == 2){
                cout << "\n\n------ENCERRANDO O PROGRAMA------\n" << endl;
                exit(1);
            }
        }while(repeticao_ == 1);
}

Interface::~Interface(){

}
