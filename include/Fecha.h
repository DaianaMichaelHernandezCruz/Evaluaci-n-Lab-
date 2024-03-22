#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class Fecha{
    public:
        Fecha(int, int, int);
        virtual ~Fecha();
        void mostrarFecha();

    protected:

    private:
        int dia;
        int mes;
        int anio;
};

#endif // FECHA_H
