#include "../include/Utils.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
#include <iostream>
#include <limits>
using namespace std;

Utils::Utils() {}

Utils::~Utils() {}

void Utils::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    // For Unix/Linux systems
    system("clear");
#endif
}

void Utils::pause()
{
    cout << "Press Enter to continue...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
}
