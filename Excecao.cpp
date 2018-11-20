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
    bool repeticao_  = false;
    do{
        try{
            cout << "------Restricoes de Temperatura Maxima:------\n" << "->";
            cin >> tempsuperior_;
            if(tempsuperior_ <= .0){
                throw Excecao("-----TEMPETURA SUPERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor maior que ZERO para Temperatura Maxima-----" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Temperatura Minima:------\n" << "->";
            cin >> tempinferior_;
            if(tempinferior_ <= .0 || tempinferior_ >= tempsuperior_){
                throw Excecao("-----TEMPERATURA INFERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor diferente de ZERO e da TEMPERATURA SUPERIOR-----" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Nivel Maximo:------------\n" << "->";
            cin >> nivelsuperior_;
            if(nivelsuperior_ <= .0){
                throw Excecao("-----NIVEL SUPERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor de NIVEL SUPERIOR diferente de ZERO-----" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Nivel Minimo:------\n" << "->";
            cin >> nivelinferior_;
            if (nivelinferior_ <= .0 || nivelinferior_ >= nivelsuperior_){
                throw Excecao("-----NIVEL INFERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor diferente de ZERO e difentre do NIVEL SUPERIOR-----\n" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Vazao Maxima:------\n" << "->";
            cin >> vazaosuperior_;
            if(vazaosuperior_ <= .0){
                throw Excecao("-----VAZAO SUPERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
                e.Out();
                cout << "-----Entre com um valor de VAZAO SUPERIOR diferente de ZERO-----\n" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Vazao Minima:------\n" << "->";
            cin >> vazaoinferior_;
            if(vazaoinferior_ <= .0 || vazaoinferior_ >= vazaosuperior_){
                throw Excecao("-----VAZAO INFERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor diferente de ZERO e difentre do VAZAO SUPERIOR-----\n" << endl;
        }
    }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

   do{
        try{
            cout << "------Restricoes de Pressao Maxima:------\n" << "->";
            cin >> pressaosuperior_;
            if(pressaosuperior_ <= .0){
                throw Excecao("-----PRESSAO SUPERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor de PRESSAO SUPERIOR diferente de ZERO-----\n" << endl;
        }
   }while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

do{
    try{
        cout << "------Restricoes de Pressao Minima:------\n" << "->";
        cin >> pressaoinferior_;
        if (pressaoinferior_ <= .0 || pressaoinferior_ >= pressaosuperior_){
            throw Excecao("-----PRESSAO INFERIOR invalido!-----\n");
        }else{
            repeticao_ = true;
        }
    }catch(Excecao &e){
        e.Out();
        cout << "-----Entre com um valor diferente de ZERO e diferente da PRESSAO SUPERIOR-----\n" << endl;
    }
}while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

do{
    try{
        cout << "------Restricoes de Concetracao Maxima:------\n" << "->";
        cin >> concentracaosuperior_;
        if(concentracaosuperior_ <= .0){
            throw Excecao("-----CONCENTRACAO SUPERIOR invalido!-----\n");
        }else{
            repeticao_ = true;
        }
    }catch(Excecao &e){
        e.Out();
        cout << "-----Entre com um valor de CONCENTRACAO SUPERIOR diferente de ZERO-----\n" << endl;
    }
}while(repeticao_ == false);

    //volta a variavel repeticção para o valor incial
    repeticao_ = false;

    do{
        try{
            cout << "------Restricoes de Concetracao Minima:------\n" << "->";
            cin >> concentracaoinferior_;
            if(concentracaoinferior_ <= .0 || concentracaoinferior_ >= concentracaosuperior_){
                throw Excecao("-----CONCENTRACAO INFERIOR invalido!-----\n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "-----Entre com um valor diferente de ZERO e diferente da CONCENTRACAO SUPERIOR-----\n" << endl;
        }
    }while(repeticao_ == false);

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
