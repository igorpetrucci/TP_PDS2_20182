#ifndef DATA_H
#define DATA_H

#include <string>

using std::string;

class Data{
public:
    Data();
    //Sobrecarga de Operador
    bool operator> (const Data &other1);
    bool operator< (const Data &other1);
    bool operator==(const Data &other1);
    int operator-(Data &other1);
    Data & operator=(const Data &l);

    //Métodos adjacentes para sobrecarga de operador
    int total_de_dias()const;
    void dat_agora();
    string Datastring();

    void SetDia(int d);
    void SetMes(int m);
    void SetAno(int a);
    int GetDia()const;
    int GetMes()const;
    int GetAno()const;

    ~Data();

private:
    int dia;
    int mes;
    int ano;
};

#endif // DATA_H
