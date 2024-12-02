#include "../include/LivroCientifico.h"


LivroCientifico::LivroCientifico() {}
LivroCientifico::LivroCientifico(int id, string titulo, string autor, int anoPublicacao, string areaPesquisa) : Geral(id,titulo, autor, anoPublicacao), areaPesquisa(areaPesquisa) {}


void LivroCientifico::mostrarInfo() const
{
    Geral::mostrarInfo();
    cout << "Area de Pesquisa: " << areaPesquisa << endl;
}

LivroCientifico::~LivroCientifico()
{
    //dtor
}
