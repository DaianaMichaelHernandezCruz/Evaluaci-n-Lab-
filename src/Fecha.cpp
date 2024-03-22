#include "Fecha.h"

Fecha::Fecha(int diafecha, int mesfecha, int aniofecha){
    dia = diafecha;
    mes = mesfecha;
    anio = aniofecha;
}
Fecha::~Fecha(){
    //dtor
}
void Fecha::mostrarFecha(){
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}
