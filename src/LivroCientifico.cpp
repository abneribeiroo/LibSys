#include "../include/LivroCientifico.h"

LivroCientifico::LivroCientifico(string titulo, string autor, int anoPublicacao, string areaPesquisa) : Geral(titulo, autor, anoPublicacao), areaPesquisa(areaPesquisa) {}


void LivroCientifico::mostrarInfo() const
{
    Geral::mostrarInfo();
    cout << "Area de Pesquisa: " << areaPesquisa << endl;
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}
