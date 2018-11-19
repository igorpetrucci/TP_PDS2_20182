#ifndef OPENARQUIVO_H
#define OPENARQUIVO_H

#include <fstream>
#include <string>
#include "Sensor.h"
#include "Data.h"
#include "Hora.h"
#include "Excecao.h"

using std::ifstream;
using std::string;

class Openarquivo{
    public:
        Openarquivo();
        void Abrearquivo();
        void Fechaaquivo();
        void Contagemlinhas();
        void Mostraarquivo();
        void Tratamento();
        void Separadata(string data_);
        void Separahorario(string data_);
        void Separavalores(string data_);
        void Analisavalores();
        void Gravalogs();
        void Gravalogs(string a_);
        void Gravarestricoes(Excecao &restricoes_);
        void Mostravalorestela();
        void Definerestricoes();
        ~Openarquivo();

    private:
        Sensor dados_;
        Data atual_;
        Hora horario_;
        Excecao restricoes_;
        int linhas_;
        string nomearquivo_;
        ifstream leitura;
};

#endif // OPENARQUIVO_H
