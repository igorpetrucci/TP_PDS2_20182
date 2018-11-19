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
    void Imprime_Tempo();
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
