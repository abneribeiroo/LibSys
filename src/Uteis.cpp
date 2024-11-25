#include "../include/Uteis.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include <iostream>
#include <limits>
using namespace std;

Uteis::Uteis()
{
    //ctor
}

Uteis::~Uteis()
{
    //dtor
}

void Uteis::clearScreen() {
#ifdef _WIN32
    // Para Windows
    system("cls");
#else
    // Para sistemas Unix/Linux
    system("clear");
#endif
}


void Uteis::Pausar() {
    cout << "Pressione Enter para continuar...";

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    clearScreen();
}

