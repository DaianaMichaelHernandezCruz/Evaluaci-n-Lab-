#ifndef ABONO_H
#define ABONO_H
#include <iostream>
using namespace std;
#include "Fecha.h"

class Abono{
    public:
        Abono(Fecha *f1, float montoAb);
        virtual ~Abono();
        Fecha *getFechaAbono();
        float getMontoAbono();

    protected:

    private:
        Fecha *fechaAbono;
        float montoAbono;
};

#endif // ABONO_H
