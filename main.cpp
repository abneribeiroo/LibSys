#include <iostream>

using namespace std;

#include "include/Biblioteca.h"

int main()
{
    cout << "Hello world!" << endl;
    Biblioteca *BIB = new Biblioteca();


    BIB->LoadFile("dados.txt");




    delete BIB;
    return 0;
}
    Biblioteca *BIB = new Biblioteca();


    BIB->LoadFile("dados.txt");




    delete BIB;
    return 0;
}
