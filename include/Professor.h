#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"


class Professor : public Pessoa
{
    string area;
    public:
        Professor();
        Professor(string nome, Data nascData, int id, Data regData, string area) : Pessoa(nome, nascData, id, regData), area(area){};

        void mostrarInfo() const {
            Pessoa::mostrarInfo();
            cout << "Area: " << area << endl;
            cout << "Tipo de Leitor: Professor" << endl;
        }
        virtual ~Professor();
        string getArea() const { return area; }
        string getCategoria() const override
        {
            return "Professor";
        };
    protected:

    private:
};

#endif // PROFESSOR_H
