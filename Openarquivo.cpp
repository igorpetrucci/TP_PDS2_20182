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
    // Inicializar a variável que armazenará a quantidade de linhas
    // Do arquivo de entrada
    linhas_ = 0;
}

// Se a abertura de arquivo falhar pelo nome errado do arquivo
// Fornecido pelo usuário o tratamento de exceção realiza
// a tentativa de abertura novamente

void Openarquivo::Abrearquivo(){
    bool repeticao_ = false;
    do{
        try{
            cout << "---------------------------------------------" << endl;
            cout << "Digite o nome do arquivo a ser aberto: \n" << "-> ";
            cin >> nomearquivo_;

            // O teclado do condensador possui apenas números
            // Desse modo o nome do arquivo digitado precisa ter
            // A extensão explicita, neste caso, .txt, para assim,
            // Poder ler o arquivo
           nomearquivo_ = nomearquivo_ + ".txt";

            leitura.open(nomearquivo_.c_str());
            if (leitura.fail()){
                throw Excecao("Erro de leitura de arquivo! \n");
            }else{
                repeticao_ = true;
            }
        }catch(Excecao &e){
            e.Out();
            cout << "\nAbertura do arquivo " << nomearquivo_ << " Falhou!" << endl;
        }
    }while(repeticao_ == false);
}

void Openarquivo::Fechaaquivo(){
    leitura.close();
    cout << "---->Fechamento do arquivo realizado com sucesso!" << endl;
}

// Verifica quantos linhas estão no arquivo de entrada
void Openarquivo::Contagemlinhas(){
    ifstream contagem;
    string logs_;

    contagem.open(nomearquivo_.c_str());

    while(!contagem.eof()) {
        getline(contagem, logs_);
        linhas_++;
    }
    contagem.close();
}

// Esta função faz a exibição de teste para verificar
// Se os dados do arquivo de entrada estão sendo lidos
// Corretamente
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

// Realiza a separação dos dados de cada linha através dos espaços e trata
// Os dados lidos para serem atribuidos a memória (DATA, HORA e VALORES).
// Dentro da função analisa valores ocorre a verificação dos valores
// do Limite Superior e Inferiror definido pelo usuário
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
        Analisavalores();
    }
}

void Openarquivo::Separadata(string data_){
   // cout << "\nImprimindo data: " << data_ << "\n" << endl;
    istringstream date(data_);
	/// Separando em parcelas menores a string da data
	string ano_, mes_, dia_;
	getline(date, ano_, '/');
	getline(date, mes_, '/');
	getline(date, dia_, ' ');

	int year_, month_, day_;
	/// converte as parcelas da string em int
	istringstream ano(ano_);
	ano >> year_;
	istringstream mes(mes_) ;
	mes >> month_;
	istringstream dia(dia_);
	dia >> day_;


	/// Definir na classe data aos valores referentes a ano, mes e dia
    atual_.SetAno(year_);
    atual_.SetMes(month_);
    atual_.SetDia(day_);
}

void Openarquivo::Separahorario(string data_){

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

	/// Definir na classe Hora os valores referentes ao ano, mes e dia
	horario_.SetHora(hour_);
	horario_.SetMinuto(minute_);
	horario_.SetSegundo(second_);
}


void Openarquivo::Separavalores(string data_){

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

   	/// Definir na classe Dados os valores referentes ao ano, mes e dia
    dados_.Setnivel(dnivel_);
    dados_.Setvazao(dvazao_);
    dados_.Settemperatura(dtemperatura_);
    dados_.Setpressao(dpressao_);
    dados_.Setconcentracao(dconcentracao_);

}

void Openarquivo::Analisavalores(){

    // Exibe na tela os valores do sensor PRESSAO, TEMPERATURA, NIVEL, VAZAO, CONCENTRAÇÃO
    // Lidos do arquivo de entrada
    Mostravalorestela();

    // Grava os valores no arquivo de saída do sensor PRESSAO, TEMPERATURA, NIVEL, VAZAO, CONCENTRAÇÃO
    Gravalogs();


    // Realiza as comparações dos LIMITES SUPERIORES E LIMITES INFERIORES
    // Com as variáveis fornecidas pelo arquivo de entrada do CONDENSADOR
    // Como pode haver violação de vários sensores ao mesmo tempo
    // Utilizamos o if em vez do tratamento de exceção, pois
    // Ao verificar um erro o tratamento para a execução do programa e
    // Não verifica o restante dos sensores
    if(dados_.Gettemperatura() > restricoes_.Gettempsuperior()){
        Excecao e("^^^^^^-------ALERTA DE TEMPERATURA MAX-------\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Gettemperatura() < restricoes_.Gettempinferior()){
        Excecao e("^^^^^^-------ALERTA DE TEMPERATURA MIN-------\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Getnivel() > restricoes_.Getnivelsuperior()){
        Excecao e("-ALERTA DE NIVEL MAX-^^^^^^\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Getnivel() < restricoes_.Getnivelinferior()){
        Excecao e("-ALERTA DE NIVEL MIN-^^^^^^\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Getvazao() > restricoes_.Getvazaosuperior()){
        Excecao e("-ALERTA DE VAZAO MAX-------^^^^^^\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Getvazao() < restricoes_.Getvazaoinferior()){
        Excecao e("-ALERTA DE VAZAO MIN-------^^^^^^\n");
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
        Excecao e("-------ALERTA DE CONCENTRACAO MAX----------------------^^^^^^\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
    if(dados_.Getconcentracao() < restricoes_.Getconcentracaoinferior()){
        Excecao e("-------ALERTA DE CONCENTRACAO MIN----------------------^^^^^^\n");
        Gravalogs(e.Geterro());
        e.Out();
    }
}

// Realiza a gravação dos logs do sensor PRESSAO, TEMPERATURA, NIVEL, VAZAO, CONCENTRAÇÃO
// E grava no inicio do arquivo de saída
// Ocorre a conversão dos valores do tipo double para o tipo string e a sua identificação
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


// Realiza a gravação de uma string especifica no arquivo de saída
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

// Realiza a gravação das restrições definidas pelo usuário no arquivo de saída.
// Ocorre a conversão das variáveis do tipo double para string
// É realizado o primeiro processo de impressão do cabeçalho no arquivo e saída
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

    string nomearquivosaida_;
    nomearquivosaida_ = "------------" + nomearquivo_ + "------------\n";
    Gravalogs(nomearquivosaida_);

    string cabecalho_ = "------------RESTRICOES------------\n";
    Gravalogs(cabecalho_);

    string texto_;
    texto_ = "Temperatura superior: " + tempsup_.str() + "\n" + "Temperatura inferior: " + tempinf_.str() + "\n" + "Nivel superior: " + nivelsup_.str() + "\n" + "Nivel inferior: " + nivelinf_.str() + "\n" + "Vazao superior: " + vazaosup_.str() + "\n" + "Vazao inferior: " + vazaoinf_.str() + "\n" + "Pressao superior: " + pressaosup_.str() + "\n" + "Pressao inferior: " + pressaoinf_.str() + "\n" + "Concentracao superior: " + concsup_.str() + "\n" + "Concentracao inferior: " + concinf_.str() + "\n";

    Hypnos_FILE.open("Logs_Sensores.txt", ios::app);
    if(Hypnos_FILE.is_open()){
        Hypnos_FILE << texto_;
    }else{
        cout << "Erro ao abrir o arquivo de texto" << endl;
    }

    Hypnos_FILE.close();
}

// Exibe as informações no formato correto e identificado
// DATA (formato PT-BR), HORA, VALORES dos sensores
void Openarquivo::Mostravalorestela(){
    cout << atual_.Datastring() << horario_.Horastring() << endl;
    cout << "Temperatura:" << dados_.Gettemperatura() << " Nivel:" << dados_.Getnivel() << " Vazao:" << dados_.Getvazao() << " Pressao:" << dados_.Getpressao() << " Concentracao:" << dados_.Getconcentracao() << endl;
    cout << endl;
}

// Inicia o processo de instanciar as variáveis de LIMITE SUPERIOR E INFERIOR
// De cada sensor de PRESSAO, TEMPERATURA, NIVEL, VAZAO, CONCENTRAÇÃO
// Após a definição a função grava os valores no arquivo de saída e
// O inicio do cabeçalho de LOGs
void Openarquivo::Definerestricoes(){

    restricoes_.Inicia();
    Gravarestricoes(restricoes_);

    string cabecalho_ = "---------------------------------------\n---------------LOGs--------------------\n";

    Gravalogs(cabecalho_);

    cabecalho_= "----------------------------------------\n";
    Gravalogs(cabecalho_);
}


Openarquivo::~Openarquivo(){

}
