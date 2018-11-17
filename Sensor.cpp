#include "Sensor.h"

Sensor::Sensor(){
    nivel_        = 0;
    vazao_        = 0;
    temperatura_  = 0;
    pressao_      = 0;
    concentracao_ = 0;
}

void Sensor::Setnivel(double ni_){
    nivel_ = ni_;
}

void Sensor::Setvazao(double va_){
    vazao_ = va_;
}

void Sensor::Settemperatura(double temp_){
    temperatura_ = temp_;
}

void Sensor::Setpressao(double pres_){
    pressao_ = pres_;
}

void Sensor::Setconcentracao(double conce_){
    concentracao_ = conce_;
}

double Sensor::Getnivel(){
    return nivel_;
}

double Sensor::Getvazao(){
    return vazao_;
}

double Sensor::Gettemperatura(){
    return temperatura_;
}

double Sensor::Getpressao(){
    return pressao_;
}

double Sensor::Getconcentracao(){
    return concentracao_;
}


Sensor::~Sensor(){

}
