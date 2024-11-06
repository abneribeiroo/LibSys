#include "../include/Uteis.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif


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