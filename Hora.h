#ifndef HORA_H
#define HORA_H

#include <string>

using std::string;

class Hora{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Hora();
    //Métodos para Pegar os valores do TEMPO
    void Imprime_Tempo();

    //Métodos Set e Get
    int GetHora()const;
    int GetMinuto()const;
    int GetSegundo()const;
    void SetHora(int h);
    void SetMinuto(int m);
    void SetSegundo(int s);
    string Horastring();

    ~Hora();

};

#endif // HORA_H
