#include <iostream>
#include <sstream>
#include "Data.h"

using std::cout;
using std::endl;
using std::stringstream;

Data::Data(){
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::~Data(){

}

//Sobrecarga do Operador

bool Data::operator> (const Data &other1){ //Verifica se a Data Esquerda A>B é maior que a Data da direita
    if (total_de_dias() > other1.total_de_dias()){
        return true;
    } else{
        return false;
    }
}

bool Data::operator< (const Data &other1){ //Verifica se a Data Esquerda A<B é menor que a Data da direita
    if (total_de_dias() < other1.total_de_dias()){
        return true;
    } else{
        return false;
    }
}

bool Data::operator==(const Data &other1){
    return (dia == other1.GetDia()) && (mes == other1.GetMes()) && (ano == other1.GetAno());
}

int Data::operator- (Data &other1){
    int Quantidade_de_dias = 0;

    Quantidade_de_dias = (total_de_dias() - other1.total_de_dias());

    if (Quantidade_de_dias < 0){
        Quantidade_de_dias *= (-1); //garante que minha quantidade de dias será sempre positiva
    }

    return Quantidade_de_dias;
}

Data & Data::operator= (const Data &l){
    SetDia(l.GetDia());
    SetMes(l.GetMes());
    SetAno(l.GetAno());
    return *this;
}


//Métodos complementares para a sobrecarga de operador
int Data::total_de_dias()const{
int total_dias = 0;
    const int dias_mes[ ] = {31, 28, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};
    total_dias += dia;

    for (int i = mes - 1; i > 0; i--){
        total_dias += dias_mes[i];
    }

    for (int i = ano - 1; i > 1582; i--){
        if(ano % 100 == 0)
        {
            if(ano % 400 == 0)
                total_dias += 366;
            else
                total_dias += 365;
        }
        else
        {
            if(ano % 4 == 0)
                total_dias += 366;
            else
                total_dias += 365;
        }
    }
    return total_dias;
}


//Métodos SET
void Data::SetDia(int d){
    dia = d;
}
void Data::SetMes(int m){
    mes = m;
}
void Data::SetAno(int a){
    ano = a;
}


//Métodos GET
int Data::GetDia()const{
    return dia;
}
int Data::GetMes()const{
    return mes;
}
int Data::GetAno()const{
    return ano;
}

void Data::dat_agora(){
    //Imprime a data atual
    cout << "Dia: " << GetDia() << " Mes: " << GetMes() << " Ano: " << GetAno() << endl;
}

string Data::Datastring(){
    string data_;
    stringstream dia_, mes_, ano_;

    dia_ << dia;
    mes_ << mes;
    ano_ << ano;

    if(dia < 10 && mes < 10){
        data_ = "0" + dia_.str() + "/0" + mes_.str() + "/" + ano_.str() + "  ";
    }
    if(dia < 10 && mes > 10){
        data_ = "0" + dia_.str() + "/" + mes_.str() + "/" + ano_.str() + "  ";
    }
    if(dia > 10 && mes > 10){
        data_ = dia_.str() + "/" + mes_.str() + "/" + ano_.str() + "  ";
    }
    if(dia > 10 && mes < 10){
        data_ = dia_.str() + "/0" + mes_.str() + "/" + ano_.str() + "  ";
    }
    return data_;
}

