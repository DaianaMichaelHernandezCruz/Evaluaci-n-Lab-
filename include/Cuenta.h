#ifndef CUENTA_H
#define CUENTA_H
#include "Cliente.h"
#include "Abono.h"
#define DIMC 5

class Cuenta{
    public:
        Cuenta();
        Cuenta(int nc, Cliente *cli);
        virtual ~Cuenta();
        int getNumeroCuenta();
        void setNumeroCuenta(int nc);
        Cliente *getCliente();
        void setCliente(Cliente *cli);
        bool agregarAbono(Abono *ab);
        Abono **getLstAbonos();
        float getSaldo();
        int getContadorAbonos();

    protected:

    private:
        int numeroCuenta;
        Cliente *cliente;
        Abono *lstAbonos[DIMC];
        float saldo;
        int contadorAbonos;
};

#endif // CUENTA_H
