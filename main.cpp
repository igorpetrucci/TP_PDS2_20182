#include <iostream>
#include "Interface.h"

int main(){
    //Interface t;
    Openarquivo teste_;
    teste_.Abrearquivo();
    teste_.Contagemlinhas();
    //teste_.Mostraarquivo();
    teste_.Definerestricoes();
    teste_.Tratamento();
    teste_.Fechaaquivo();


///Teste da CLASSE DATA
//    Data A;
//    A.SetDia(26);
//    A.SetMes(5);
//    A.SetAno(2016);
//
//    Data B;
//    B.SetDia(27);
//    B.SetMes(5);
//    B.SetAno(2018);
//    cout << "A: Dias: " << A.GetDia() << " Mes: " << A.GetMes() << " Ano: " << A.GetAno() << endl;
//    cout << "Total de dias eh: " << A.total_de_dias() << "\n\n" << endl;
//    cout << "B: Dias: " << A.GetDia() << " Mes: " << A.GetMes() << " Ano: " << B.GetAno() << endl;
//    cout << "Total de dias eh: " << B.total_de_dias() << endl;

//    //Teste para saber se a data da esquerda é a menor
//    int bb = 9; //coloquei 9 apenas para que eu saiba se a var bb será 0 ou 1 de fato
//    bb = B<A;
//    cout << "\nB eh menor que A? -> " << bb << endl;   //Se o resultado der 1 (true) a sentença é verdadeira
//                          //Se o resultado der 0 (false) a sentença é falsa
//    int cc = 9;
//    cc = A<B;
//    cout << "A eh menor que B? -> " << cc << endl;
//
//    //Teste para saber se a data da esquerda é a maior
//    int dd = 9;
//    dd = B>A;
//    cout << "B eh maior que A? -> " << dd << endl;   //Se o resultado der 1 (true) a sentença é verdadeira
//                          //Se o resultado der 0 (false) a sentença é falsa
//    int ee = 9;
//    ee = A>B;
//    cout << "A eh maior que B? -> " << ee << endl;
//
//    //Teste de subtração de datas para descobrir quantos dias há entre as duas datas passdas
//    int qnts_dias = 0;
//    qnts_dias = A-B;
//    cout << "Quantos Dias tem entre as datas: " << qnts_dias << endl;
//
//    cout << endl;
//
//    //Teste de impressão de data
//    A.dat_agora();
//    cout << endl;
//    B.dat_agora();

///Teste da classe Hora
//
//    Hora teste_;
//
//    teste_.SetHora(18);
//    teste_.SetMinuto(1);
//    teste_.SetSegundo(34);
//
//    teste_.Imprime_Tempo();

    return 0;
}
