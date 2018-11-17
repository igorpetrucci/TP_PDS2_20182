#include <iostream>
#include <sstream>
#include "Hora.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

Hora::Hora(){
    hora = 0;
    minuto = 0;
    segundo = 0;
}

void Hora::Imprime_Tempo(){
    if(GetHora() < 10){
        cout << " 0" << GetHora() << ":" << GetMinuto() << ":" << GetSegundo();
    }
    if(GetMinuto() < 10){
        cout << " " << GetHora() << ":0" << GetMinuto() << ":" << GetSegundo();
    }
    if(GetSegundo() < 10){
        cout << " " << GetHora() << ":" << GetMinuto() << ":0" << GetSegundo();
    }
    if((GetHora()<10) && (GetMinuto()<10) && (GetSegundo()<10) ){
        cout << " 0" << GetHora() << ":0" << GetMinuto() << ":0" << GetSegundo() << endl;
    }
    //Se nenhum caso é atendido, imprime a hora
    if((GetHora()>10) && (GetMinuto()>10) && (GetSegundo()>10) ){
        cout << " " << GetHora() << ":" << GetMinuto() << ":" << GetSegundo() << endl;
    }
}


void Hora::SetHora(int h){
    hora = h;
}
void Hora::SetMinuto(int m){
    minuto = m;
}
void Hora::SetSegundo(int s){
    segundo = s;
}

int Hora::GetHora()const{
    return hora;
}
int Hora::GetMinuto()const{
    return minuto;
}
int Hora::GetSegundo()const{
    return segundo;
}

string Hora::Horastring(){
    string horario_;
    stringstream hora_, minuto_, segundo_;

    hora_ << hora;
    minuto_ << minuto;
    segundo_ << segundo;

    if(minuto < 10 && segundo < 10){
        horario_ = hora_.str() + ":0" + minuto_.str() + ":0" + segundo_.str() + "  ";
    }
    if(minuto < 10 && segundo > 10){
        horario_ =  hora_.str() + ":0" + minuto_.str() + ":" + segundo_.str() + "  ";
    }
    if(minuto > 10 && segundo < 10){
        horario_ = hora_.str() + ":" + minuto_.str() + ":0" + segundo_.str() + "  ";
    }
    if(minuto > 10 && segundo > 10){
        horario_ = hora_.str() + ":" + minuto_.str() + ":" + segundo_.str() + "  ";
    }

    return horario_;
}


Hora::~Hora(){

}
