// Multa.h
#ifndef MULTA_H
#define MULTA_H

#include <iostream>
using namespace std;

class Multa {
public:
    Multa();
    ~Multa();
    void exibirMulta() const;
    Multa calcularMulta(int diasAtraso, double valorBasePorDia, double desconto);
    double getValorFinal() const { return valorFinal; }
    void setPago(bool estado) { pago = estado; }
    bool getPago() const { return pago; }

private:
    int diasAtraso;
    double valorBasePorDia;
    double desconto;
    double valorFinal;
    bool pago;
};

#endif // MULTA_H