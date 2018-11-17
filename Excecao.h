#ifndef EXCECAO_H
#define EXCECAO_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Excecao{
    public:
        Excecao();
        Excecao(const string &tp);
        void Inicia();
        void Out();
        string Geterro();
        void Settempsuperior(double tempsup_);
        void Settempinferior(double tempinf_);
        void Setpressaosuperior(double pressaosup_);
        void Setpressaoinferior(double pressaoinf_);
        void Setconcentracaosuperior(double concentsup_);
        void Setconcentracaoinferior(double concentinf_);
        void Setnivelsuperior(double nivelsup_);
        void Setnivelinferior(double nivelinf_);
        void Setvazaosuperior(double vazaosup_);
        void Setvazaoinferior(double vazaoinf_);
        double Gettempsuperior();
        double Gettempinferior();
        double Getpressaosuperior();
        double Getpressaoinferior();
        double Getconcentracaosuperior();
        double Getconcentracaoinferior();
        double Getnivelsuperior();
        double Getnivelinferior();
        double Getvazaosuperior();
        double Getvazaoinferior();

        ~Excecao();

    private:
        string tipoerro_;
        double tempsuperior_;
        double tempinferior_;
        double pressaosuperior_;
        double pressaoinferior_;
        double concentracaosuperior_;
        double concentracaoinferior_;
        double nivelsuperior_;
        double nivelinferior_;
        double vazaosuperior_;
        double vazaoinferior_;
};

#endif // EXCECAO_H
