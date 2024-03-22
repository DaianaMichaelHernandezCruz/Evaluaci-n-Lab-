#include "Cuenta.h"
#include "Cliente.h"
#include "Abono.h"
#define DIMC 5

Cuenta::Cuenta(){
    //ctor
}
Cuenta::Cuenta(int nc, Cliente *cli){
    numeroCuenta = nc;
    cliente = cli;
    saldo = 0;
}
Cuenta::~Cuenta(){
    //dtor
}
int Cuenta::getNumeroCuenta(){
    return this->numeroCuenta;
}
void Cuenta::setNumeroCuenta(int nc){
    this->numeroCuenta = nc;
}
Cliente *Cuenta::getCliente(){
    return this->cliente;
}
void Cuenta::setCliente(Cliente *cli){
    cliente = cli;
}
bool Cuenta::agregarAbono(Abono *ab){
    bool retorno = false;
    if (this->contadorAbonos < DIMC){
        this->lstAbonos[this->contadorAbonos] = ab;
        this->contadorAbonos++;
        this->saldo += ab->getMontoAbono();
    }
    return retorno;
}
Abono **Cuenta::getLstAbonos(){
    return this->lstAbonos;
}
float Cuenta::getSaldo(){
    return this->saldo;
}
int Cuenta::getContadorAbonos(){
    return this->contadorAbonos;
}




