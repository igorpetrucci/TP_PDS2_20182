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
    //cout << "Quantidade de linhas eh: " <<  linhas_ << "\n\n" << endl;
    contagem.close();
}

void Openarquivo::Mostraarquivo(){
    //Função para visualização da tela para usuário
    string parte1_, parte2_, parte3_;
    //cout << "Quantidade de linhas eh: " <<  linhas_ << endl;
    for(int i=0; i < linhas_ ; i++){
        leitura >> parte1_;
        leitura >> parte2_;
        leitura >> parte3_;
        cout << parte1_ << " " << parte2_ <<  " " << parte3_ << endl;
    }
}

//Realiza a separação dos dados de cada linha e tratamento para alocação
//de memória para cada item, bem como a analise de requisito se o sensor
//irá identificar alguma alteração de temperatura
void Openarquivo::Tratamento(){

    string date_, hour_, value_;
    for(int i=0; i < linhas_ ; i++){
        leitura >> date_;
        leitura >> hour_;
        leitura >> value_;

        ///Tratamento das informações
        Separadata(date_);
        Separahorario(hour_);
        Separavalores(value_);
        Analisavalores(); ///Verifica se os valores correspondem entre os limites superiores e inferiores
    }
}

void Openarquivo::Separadata(string data_){
   // cout << "\nImprimindo data: " << data_ << "\n" << endl;
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
//    cout << "\n\nImprimido horario: " << data_ << endl;

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
//    cout << "\nImprimindo valores: " << data_ << endl;
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

void Openarquivo::Analisavalores(){

    //Exibe na tela os valores lidos do arquivo de entrada
    Mostravalorestela();

cout << "\nTESTE DE TEMP:" << dados_.Gettemperatura() << "  "  << restricoes_.Gettempinferior() << endl;

    //Grava os valores analisados no arquivo base
    Gravalogs();
    try{
        if(dados_.Gettemperatura() > restricoes_.Gettempsuperior()){
            throw Excecao("-------ALERTA DE TEMPERATURA MAX-------\n");
        }
        if(dados_.Gettemperatura() < restricoes_.Gettempinferior()){
            throw Excecao("-------ALERTA DE TEMPERATURA MIN-------\n");
        }
        if(dados_.Getnivel() > restricoes_.Getnivelsuperior()){
            throw Excecao("-------ALERTA DE NIVEL MAX-------\n");
        }
        if(dados_.Getnivel() < restricoes_.Getnivelinferior()){
            throw Excecao("-------ALERTA DE NIVEL MIN-------\n");
        }
        if(dados_.Getvazao() > restricoes_.Getvazaosuperior()){
            throw Excecao("-------ALERTA DE VAZAO MAX-------\n");
        }
        if(dados_.Getvazao() < restricoes_.Getvazaoinferior()){
            throw Excecao("-------ALERTA DE VAZAO MIN-------\n");
        }
        if(dados_.Getpressao() > restricoes_.Getpressaosuperior()){
            throw Excecao("-------ALERTA DE PRESSAO MAX-------\n");
        }
        if(dados_.Getpressao() < restricoes_.Getpressaoinferior()){
            throw Excecao("-------ALERTA DE PRESSAO MIN-------\n");
        }
        if(dados_.Getconcentracao() > restricoes_.Getconcentracaosuperior()){
            throw Excecao("-------ALERTA DE CONCENTRACAO MAX-------\n");
        }
        if(dados_.Getconcentracao() < restricoes_.Getconcentracaoinferior()){
            throw Excecao("-------ALERTA DE CONCENTRACAO MIN-------\n");
        }

    }catch(Excecao &e){
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

void Openarquivo::Definerestricoes(){

    //Realiza a gravação de das restrições nos atributos
    restricoes_.Inicia();
    Gravarestricoes(restricoes_);

    string cabecalho_ = "---------------------------------------\n---------------LOGs--------------------\n";

    Gravalogs(cabecalho_);

    cabecalho_= "----------------------------------------\n";
    Gravalogs(cabecalho_);
}


Openarquivo::~Openarquivo(){

}
