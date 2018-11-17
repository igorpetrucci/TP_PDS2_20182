#include "Openarquivo.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ios;
using std::stringstream;
using std::istringstream;
using std::ofstream;
using std::ifstream;

Openarquivo::Openarquivo(){
    linhas_ = 0;
    rest_ = false; //Enquanto as restrição é false signfica que as restições não foram gravadas
}

void Openarquivo::Abrearquivo(){
    cout << "---------------------------------------------" << endl;
	cout << "Digite o nome do arquivo a ser aberto: \n" << "-> ";
    cin >> nomearquivo_;

	leitura.open(nomearquivo_.c_str());
	if (leitura.fail()){
		cout << "\n     A abertura do arquivo " << "\""<< nomearquivo_
		<< "\" " << "falhou!" << endl;
		cout << "-----------Encerrando o Programa-------------" << endl;
		exit(1);
	}
	cout << "\nAbertura do arquivo " << nomearquivo_ << " realizada com sucesso!" << endl;
    cout << "---------------------------------------------" << endl;
}

void Openarquivo::Fechaaquivo(){
    leitura.close();
    cout << "---->Fechamento do arquivo realizado com sucesso!" << endl;
}

void Openarquivo::Contagemlinhas(){
    //Realiza a contagem de linhas para poder saber quantos itens serão avaliados
    //Dentro do sistema
    ifstream contagem;
    string logs_;

    contagem.open(nomearquivo_.c_str());

    while(!contagem.eof()) {
        getline(contagem, logs_);
        linhas_++;
    }
    contagem.close();
}

void Openarquivo::Mostraarquivo(){
    //Função para visualização da tela para usuário
    string parte1_, parte2_, parte3_;
    cout << linhas_ << endl;
    for(int i=0; i < linhas_ ; i++){
        leitura >> parte1_;
        leitura >> parte2_;
        leitura >> parte3_;
        cout << parte1_ << " " << parte2_ <<  " " << parte3_ << endl;
    }
}

void Openarquivo::Tratamento(){
    string date_, hour_, value_;
    //cout << linhas_ << endl;

    for(int i=0; i < linhas_ ; i++){ ///MUDAR AQUI A RESTRIÇÃO DE LINHAS (1 -> só pega uma linha)
        leitura >> date_;
        leitura >> hour_;
        leitura >> value_;


        ///Tratamento das informações
        Separadata(date_);
        Separahorario(hour_);
        Separavalores(value_);
        AnalisaValores(); ///Verifica se os valores correspondem entre os limites superiores e inferiores
    }
}

void Openarquivo::Separadata(string data_){
    //cout << data_ << endl;
    istringstream date(data_);
	///Separando em parcelas menores a string da data
	string ano_, mes_, dia_;
	getline(date, ano_, '/');
	getline(date, mes_, '/');
	getline(date, dia_, ' ');

	int year_, month_, day_;
	///convertendo as parcelas da string em int
	istringstream ano(ano_);
	ano >> year_;
	istringstream mes(mes_) ;
	mes >> month_;
	istringstream dia(dia_);
	dia >> day_;

	///Definir na classe data os valores referentes ao ano, mes e dia
    atual_.SetAno(year_);
    atual_.SetMes(month_);
    atual_.SetDia(day_);
}

void Openarquivo::Separahorario(string data_){
    //cout << data_ << endl;

    istringstream tempo(data_);

	string hora_, minuto_, segundo_;
	getline(tempo,hora_,':');
	getline(tempo,minuto_,':');
	getline(tempo,segundo_,' ');

	int hour_,minute_,second_;
	istringstream hora(hora_);
	istringstream minuto(minuto_);
	istringstream segundo(segundo_);
	hora >> hour_;
	minuto >> minute_;
	segundo >> second_;

	///Definir na classe Hora os valores referentes ao ano, mes e dia
	horario_.SetHora(hour_);
	horario_.SetMinuto(minute_);
	horario_.SetSegundo(second_);
}


void Openarquivo::Separavalores(string data_){
    //cout << data_ << endl;
    istringstream sensor(data_);

	string nivel_, vazao_, temperatura_, pressao_, concentracao_;
	getline(sensor,nivel_,';');
	getline(sensor,vazao_,';');
	getline(sensor,temperatura_,';');
	getline(sensor,pressao_,';');
    getline(sensor,concentracao_,' ');

    double dnivel_, dvazao_, dtemperatura_, dpressao_, dconcentracao_;
	istringstream nivel(nivel_);
	istringstream vazao(vazao_);
	istringstream temperatura(temperatura_);
    istringstream pressao(pressao_);
    istringstream concentracao(concentracao_);

    nivel >> dnivel_;
    vazao >> dvazao_;
    temperatura >> dtemperatura_;
    pressao >> dpressao_;
    concentracao >> dconcentracao_;

   	///Definir na classe Dados os valores referentes ao ano, mes e dia
    dados_.Setnivel(dnivel_);
    dados_.Setvazao(dvazao_);
    dados_.Settemperatura(dtemperatura_);
    dados_.Setpressao(dpressao_);
    dados_.Setconcentracao(dconcentracao_);

}

void Openarquivo::AnalisaValores(){

    //Definição das restrições das variaveis Temperatura, Pressao e concentraçao
    Excecao restricoes_;
    //Incia a gravação das restriçõe, se já foi iniciado set os valores com o usuario e passa a analisar
    //Os numeros fornecidos pelo arquivo principal
    if(rest_ == false){
        restricoes_.Inicia();
        Gravarestricoes(restricoes_);
        rest_= true;

        string cabecalho_ = "---------------------------------------\n---------------LOGs--------------------\n";

        Gravalogs(cabecalho_);
    }
    string cabecalho_= "----------------------------------------\n";
    Gravalogs(cabecalho_);

    //Exibe na tela os valores lidos do arquivo de entrada
    Mostravalorestela();

    //Grava os valores analisados no arquivo base
    Gravalogs();
        if(dados_.Gettemperatura() > restricoes_.Gettempsuperior()){
            Excecao e("-------ALERTA DE TEMPERATURA MAX--------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Gettemperatura() < restricoes_.Gettempinferior()){
            Excecao e("-------ALERTA DE TEMPERATURA MIN--------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getnivel() > restricoes_.Getnivelsuperior()){
            Excecao e("-------ALERTA DE NIVEL MAX--------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getnivel() < restricoes_.Getnivelinferior()){
            Excecao e("-------ALERTA DE NIVEL MIN--------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getvazao() > restricoes_.Getvazaosuperior()){
            Excecao e("-------ALERTA DE VAZAO MAX--------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getvazao() < restricoes_.Getvazaoinferior()){
            Excecao e("-------ALERTA DE VAZAO MIN--------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getpressao() > restricoes_.Getpressaosuperior()){
            Excecao e("-------ALERTA DE PRESSAO MAX------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getpressao() < restricoes_.Getpressaoinferior()){
            Excecao e("-------ALERTA DE PRESSAO MIN------------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getconcentracao() > restricoes_.Getconcentracaosuperior()){
            Excecao e("-------ALERTA DE CONCENTRACAO MAX-------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
        if(dados_.Getconcentracao() < restricoes_.Getconcentracaoinferior()){
            Excecao e("-------ALERTA DE CONCENTRACAO MIN-------^^^^^^\n");
            Gravalogs(e.Geterro());
            e.Out();
        }
}

///Grava os logs lidos do sistema para o arquivo de saída
void Openarquivo::Gravalogs(){
    ofstream Hypnos_FILE;

    stringstream temp_, nivel_, vazao_, pressao_, concentracao_;

    temp_           << dados_.Gettemperatura();
    nivel_          << dados_.Getnivel();
    vazao_          << dados_.Getvazao();
    pressao_        << dados_.Getpressao();
    concentracao_   << dados_.Getconcentracao();

    string texto_;

    texto_ = atual_.Datastring() + horario_.Horastring() + "  Temperatura: " + temp_.str() + "  Nivel: " + nivel_.str() + "  Vazao: " + vazao_.str() + "  Pressao: " + pressao_.str() + "  Concentracao: " + concentracao_.str() + "\n";

    Hypnos_FILE.open("Logs_Sensores.txt", ios::app);
    if(Hypnos_FILE.is_open()){
        //cout << "Abertura do arquivo com Sucesso" << endl;
        Hypnos_FILE << texto_;
    }else{
        cout << "Erro ao abrir o arquivo de texto" << endl;
    }
    Hypnos_FILE.close();
}

void Openarquivo::Gravalogs(string a_){
    ofstream Hypnos_FILE;

    Hypnos_FILE.open("Logs_Sensores.txt", ios::app);
    if(Hypnos_FILE.is_open()){
        //cout << "Abertura do arquivo com Sucesso" << endl;
        Hypnos_FILE << a_;
    }else{
        cout << "Erro ao abrir o arquivo de texto" << endl;
    }
    Hypnos_FILE.close();

}

void Openarquivo::Gravarestricoes(Excecao &restricoes_){
    ofstream Hypnos_FILE;

    stringstream tempsup_, tempinf_, nivelsup_, nivelinf_, vazaosup_, vazaoinf_, pressaosup_, pressaoinf_, concsup_, concinf_;

    tempsup_        << restricoes_.Gettempsuperior();
    tempinf_        << restricoes_.Gettempinferior();
    nivelsup_       << restricoes_.Getnivelsuperior();
    nivelinf_       << restricoes_.Getnivelinferior();
    vazaosup_       << restricoes_.Getvazaosuperior();
    vazaoinf_       << restricoes_.Getvazaoinferior();
    pressaosup_     << restricoes_.Getpressaosuperior();
    pressaoinf_     << restricoes_.Getpressaoinferior();
    concsup_        << restricoes_.Getconcentracaosuperior();
    concinf_        << restricoes_.Getconcentracaoinferior();

    string texto_;

    string cabecalho_ = "------------RESTRICOES------------\n";
    Gravalogs(cabecalho_);

    texto_ = "Temperatura superior: " + tempsup_.str() + "\n" + "Temperatura inferior: " + tempinf_.str() + "\n" + "Nivel superior: " + nivelsup_.str() + "\n" + "Nivel inferior: " + nivelinf_.str() + "\n" + "Vazao superior: " + vazaosup_.str() + "\n" + "Vazao inferior: " + vazaoinf_.str() + "\n" + "Pressao superior: " + pressaosup_.str() + "\n" + "Pressao inferior: " + pressaoinf_.str() + "\n" + "Concentracao superior: " + concsup_.str() + "\n" + "Concentracao inferior: " + concinf_.str() + "\n";

    Hypnos_FILE.open("Logs_Sensores.txt", ios::app);
    if(Hypnos_FILE.is_open()){
        //cout << "Abertura do arquivo com Sucesso" << endl;
        Hypnos_FILE << texto_;
    }else{
        cout << "Erro ao abrir o arquivo de texto" << endl;
    }

    Hypnos_FILE.close();
}

void Openarquivo::Mostravalorestela(){
    cout << atual_.Datastring() << horario_.Horastring() << endl;
    cout << "Temperatura:" << dados_.Gettemperatura() << " Nivel:" << dados_.Getnivel() << " Vazao:" << dados_.Getvazao() << " Pressao:" << dados_.Getpressao() << " Concentracao:" << dados_.Getconcentracao() << endl;
    cout << endl;
}


Openarquivo::~Openarquivo(){

}
