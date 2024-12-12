#include "../include/LivroCientifico.h"


LivroCientifico::LivroCientifico() {}
LivroCientifico::LivroCientifico(int id, string titulo, string autor, Data dataPublicacao, string areaPesquisa) : Geral(id,titulo, autor, dataPublicacao), areaPesquisa(areaPesquisa) {}




LivroCientifico::~LivroCientifico()
{
    //dtor
}
