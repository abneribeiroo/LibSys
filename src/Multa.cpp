#include "../include/Multa.h"

Multa::Multa() : diasAtraso(0), valorBasePorDia(0.5), desconto(0.0), valorFinal(0.0), pago(true) {
    // Constructor implementation
}

Multa::~Multa() {
    // Destructor implementation
}

void Multa::exibirMulta() const {
    cout << "Multa Calculada:\n";
    cout << " - Dias de Atraso: " << diasAtraso << "\n";
    cout << " - Valor Base por Dia: " << valorBasePorDia << " EUR\n";
    cout << " - Desconto Aplicado: " << desconto * 100 << "%\n";
    cout << " - Valor Final: " << valorFinal << " EUR\n";
}

Multa Multa::calcularMulta(int diasAtraso, double valorBasePorDia, double desconto) {
    Multa multa;
    multa.diasAtraso = diasAtraso;
    multa.valorBasePorDia = valorBasePorDia;
    multa.desconto = desconto;
    multa.valorFinal = diasAtraso * valorBasePorDia * (1 - desconto);
    if(multa.valorFinal > 0){
        multa.pago = false;
    }
    return multa;
}