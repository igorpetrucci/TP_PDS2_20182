#include "Excecao.h"

Excecao::Excecao(){

}

void Excecao::Inicia(){
    tempsuperior_= 0.;
    tempinferior_ = 0.;
    nivelsuperior_ = 0.;
    nivelinferior_ = 0.;
    vazaosuperior_ = 0.;
    vazaoinferior_ = 0.;
    pressaosuperior_ = 0.;
    concentracaosuperior_ = 0.;
    concentracaoinferior_ = 0.;
    cout << "---------------------------------------------" << endl;
    cout << "-----------Restricoes do Sistema-------------" << endl;
    cout << "------Restricoes de Temperatura Maxima:------\n" << "->";
    cin >> tempsuperior_;
    cout << "------Restricoes de Temperatura Minima:------\n" << "->";
    cin >> tempinferior_;
    cout << "------Restricoes de Nivel Maximo:------------\n" << "->";
    cin >> nivelsuperior_;
    cout << "------Restricoes de Nivel Minimo:------\n" << "->";
    cin >> nivelinferior_;
    cout << "------Restricoes de Vazao Maxima:------\n" << "->";
    cin >> vazaosuperior_;
    cout << "------Restricoes de Vazao Minima:------\n" << "->";
    cin >> vazaoinferior_;
    cout << "------Restricoes de Pressao Maxima:------\n" << "->";
    cin >> pressaosuperior_;
    cout << "------Restricoes de Pressao Minima:------\n" << "->";
    cin >> pressaoinferior_;
    cout << "------Restricoes de Concetracao Maxima:------\n" << "->";
    cin >> concentracaosuperior_;
    cout << "------Restricoes de Concetracao Minima:------\n" << "->";
    cin >> concentracaoinferior_;
    cout << "---------------------------------------------" << endl;
    cout << "\n ------Restricoes definidas com exito!------" << endl;
    cout << "---------------------------------------------" << endl;
}

Excecao::Excecao(const string &tp){
    tipoerro_ = tp;
}

void Excecao::Out(){
    cout << tipoerro_ << endl;
}

string Excecao::Geterro(){
    return tipoerro_;
}

void Excecao::Settempsuperior(double tempsup_){
    tempsuperior_ = tempsup_;
}

void Excecao::Settempinferior(double tempinf_){
    tempinferior_ = tempinf_;
}

void Excecao::Setpressaosuperior(double pressaosup_){
    pressaosuperior_ = pressaosup_;
}

void Excecao::Setpressaoinferior(double pressaoinf_){
    pressaoinferior_ = pressaoinf_;
}

void Excecao::Setconcentracaosuperior(double concentsup_){
    concentracaosuperior_ = concentsup_;
}

void Excecao::Setconcentracaoinferior(double concentinf_){
    concentracaoinferior_ = concentinf_;
}

void Excecao::Setnivelsuperior(double nivelsup_){
    nivelsuperior_ = nivelsup_;
}

void Excecao::Setnivelinferior(double nivelinf_){
    nivelinferior_ = nivelinf_;
}

void Excecao::Setvazaosuperior(double vazaosup_){
    vazaosuperior_ = vazaosup_;
}

void Excecao::Setvazaoinferior(double vazaoinf_){
    vazaoinferior_ = vazaoinf_;
}


double Excecao::Gettempsuperior(){
    return tempsuperior_;
}

double Excecao::Gettempinferior(){
    return tempinferior_;
}

double Excecao::Getpressaosuperior(){
    return pressaosuperior_;
}

double Excecao::Getpressaoinferior(){
    return pressaoinferior_;
}

double Excecao::Getconcentracaosuperior(){
    return concentracaosuperior_;
}

double Excecao::Getconcentracaoinferior(){
    return concentracaoinferior_;
}

double Excecao::Getnivelsuperior(){
    return nivelsuperior_;
}
double Excecao::Getnivelinferior(){
    return nivelinferior_;
}
double Excecao::Getvazaosuperior(){
    return vazaosuperior_;
}
double Excecao::Getvazaoinferior(){
    return vazaoinferior_;
}

Excecao::~Excecao(){

}
