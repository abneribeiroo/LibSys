#include "../include/Biblioteca.h"
#include "../include/Data.h"
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

Data::Data() : dia(0), mes(0), ano(0) {}

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

Data::~Data() {

}


int Data::calcularIdade() const
{
    time_t t = time(0);
    tm* now = localtime(&t);
    int anoAtual = now->tm_year + 1900;
    int mesAtual = now->tm_mon + 1;
    int diaAtual = now->tm_mday;

    int idade = anoAtual - ano;

    if (mesAtual < mes ||
        (mesAtual == mes && diaAtual < dia)) {
        idade--;
    }

    return idade;
}

Data Data::dataAtual(){
    time_t t = time(0);
    tm* now = localtime(&t);
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1;
    int ano = now->tm_year + 1900;

    return Data(dia, mes, ano);
}

void Data::mostrarInfo() const
{
    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;
}

Data Data::lerData() {
    int dia, mes, ano;

    cout << "Insira o dia: ";
    cin >> dia;
    if(dia == 0){
        return Data(0,0,0);
    }

    cout << "Insira o mês: ";
    cin >> mes;

    cout << "Insira o ano: ";
    cin >> ano;

    // Retorna o objeto Data com os valores lidos
    return Data(dia, mes, ano);
}

Data Data::lerString(const string& dataStr) {
    char* cstr = new char[dataStr.length() + 1];
    strcpy(cstr, dataStr.c_str());

    char* token = strtok(cstr, "/");
    int dia = atoi(token);

    token = strtok(nullptr, "/");
    int mes = atoi(token);

    token = strtok(nullptr, "");
    int ano = atoi(token);

    delete[] cstr;

    return Data(dia, mes, ano);
}


string Data::paraString() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}

bool Data::eValida() const{
        // Verifica o ano
        if (ano < 1900) {
            return false;
        }

        // Verifica o mês
        if (mes < 1 || mes > 12) {
            return false;
        }

        // Verifica os dias do mês
        if (dia < 1) {
            return false;
        }

        // Número de dias em cada mês
        int diasNoMes[] = { 31, 29, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Verifica se o dia é válido para o mês correspondente
        if (dia > diasNoMes[mes - 1]) {
            return false;
        }

        return true;
    }
