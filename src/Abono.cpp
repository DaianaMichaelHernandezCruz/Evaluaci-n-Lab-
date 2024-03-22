#include "Abono.h"

Abono::Abono(Fecha *f1, float montoAb){
    fechaAbono = f1;
    montoAbono = montoAb;
}
Abono::~Abono(){
    //dtor
}
Fecha *Abono::getFechaAbono(){
    return this->fechaAbono;
}
float Abono::getMontoAbono(){
    return this->montoAbono;
}
