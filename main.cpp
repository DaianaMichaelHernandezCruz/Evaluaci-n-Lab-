#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Cliente.h"
#include "Cuenta.h"
#define TML 5

int menu(){
    int op;
    cout << "*********************************************\n";
    cout << "               MENU DE OPCIONES             *\n";
    cout << "*********************************************\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar cuenta a la lista\n";
    cout << "3. Hacer abonos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de cuentas\n";
    cout << "6. Mostrar detalles de cuenta\n";
    cout << "7. Salir\n";
    cout << "*********************************************\n";
    cout << "Digite una opcion: ";
    cin >> op;
    cout << "*********************************************\n\n";
    return op;
}

Cliente *agregarCliente(){
    int idCl;
    string nombreCl,apellidoCl;
    Cliente *cli;

    cout << "Digite el Id del Cliente: ";
    cin >> idCl;
    cout << "Digite el Nombre del Cliente: ";
    cin >> nombreCl;
    cout << "Digite el Apellido del Cliente: ";
    cin >> apellidoCl;

    cli = new Cliente(idCl, nombreCl ,apellidoCl);
    return cli;
}

Cuenta *agregarCuenta(Cliente *cli){
    int numeroCuenta;
    Cuenta *cuenta;

    cout << "Digite el Numero de la Cuenta: ";
    cin >> numeroCuenta;

    cuenta = new Cuenta(numeroCuenta, cli);
    return cuenta;
}

Cliente *BuscarCliente(Cliente *lstCl[], int contadorCl, int idCl ){
    bool encontrado = false;
    int contador =0;
    Cliente *cli = NULL;
    while (contador < contadorCl && !encontrado){
        if (lstCl[contador]->getIdCliente() == idCl){
            encontrado = true;
            cli = lstCl[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}

Cuenta *BuscarCuenta(Cuenta *lstCuenta[], int contadorCuenta, int idCuenta){
    bool encontrado = false;
    int contador =0;
    Cuenta *cuenta = NULL;
    while (contador < contadorCuenta && !encontrado){
        if (lstCuenta[contador]->getNumeroCuenta() == idCuenta){
            encontrado = true;
            cuenta = lstCuenta[contador];
        }
        else{
            contador++;
        }
    }
    return cuenta;
}

void registrarAbono(Cuenta *cuenta){
    int diafecha, mesfecha, aniofecha;
    Fecha *f1;
    float montoabono;
    Abono *ab;
    cout << "Digite la fecha del Abono (dd/mm/aa) : \n";
    cout << "dia: "; cin >> diafecha;
    cout << "mes: ";cin >> mesfecha;
    cout << "anio: ";cin >> aniofecha;
    f1 = new Fecha(diafecha, mesfecha, aniofecha);

    cout << "Digite el monto del Abono: $";
    cin >> montoabono;
    ab = new Abono(f1, montoabono);

    cuenta->agregarAbono(ab);
}

void verDetalles(Cuenta *cuenta){
    cout << "\n";
    cout << "No Cuenta : " << cuenta->getNumeroCuenta() <<endl;
    cout << "Cliente : " << cuenta->getCliente()->getNombre() << " " << cuenta->getCliente()->getApellido() << endl;
    cout << "Saldo: $ " << cuenta->getSaldo();
    cout << "\n";
    if (cuenta->getContadorAbonos() == 0){
        cout << "\nNo tiene Abonos registrados\n";
    }
    else{
        cout << "\n";
        cout << "Abonos\n";
        Abono **lista = cuenta->getLstAbonos();
        cout << "No\tFecha\t\tMonto del Abono\n";
        for (int i=0; i < cuenta->getContadorAbonos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaAbono()->mostrarFecha();
            cout << "\t";
            cout << "\t $" << lista[i]->getMontoAbono() << endl;
        }
    }
}

/*

void verDetalles(Prestamo *ptmo){
    cout << "El numero : " << ptmo->getNumeroPrestamo() <<endl;
    cout << "Cliente : " << ptmo->getCliente()->getNombre() << " " << ptmo->getCliente()->getApellido() << endl;
    cout << "Fecha Aprobacion : ";
    ptmo->getFechaAprobacion()->mostrarFecha();
    cout << "\nMonto aprobado : " << ptmo->getMontoAprobado() <<endl;
    cout << "Saldo pendiente : " << ptmo->getSaldoPendiente() << endl;
    if (ptmo->getContadorPagos() == 0){
        cout << "No tiene pagos registrados\n";
    }
    else{
        Pago **lista = ptmo->getLstPagos();
        cout << "No\tFecha\tMonto\n";
        for (int i=0; i<ptmo->getContadorPagos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t" << lista[i]->getMontoPago() << endl;
        }
    }
}

*/
int main()
{
    Cliente *lstCl[TML];
    Cuenta *lstCuenta[TML];
    Cliente *cli=NULL;
    Cuenta *cuenta = NULL;
    int opc, contadorCl = 0, contadorCuenta = 0, idCliente, idCuenta;
    do{
        system("cls");
        opc = menu();
        switch (opc){
            case 1:
                ///Agregar clientes
                if (contadorCl < TML){
                    lstCl[contadorCl] = agregarCliente();
                    contadorCl++;
                    cout << "\nEl cliente se agrego con exito\n";
                }else{
                    cout << "\nLa lista esta llena\n";
                }
                break;

            case 2:
                ///Agregar cuenta
                if(contadorCuenta < TML){
                    cout << "Digite el Id del cliente a quien le creara la cuenta: ";
                    cin >> idCliente;
                    cli = BuscarCliente(lstCl, contadorCl, idCliente);
                    if (cli){
                        lstCuenta[contadorCuenta] = agregarCuenta(cli);
                        contadorCuenta++;
                        cout << "\nLa cuenta se registro con exito\n";
                    }
                    else{
                        cout << "\El cliente no existe, no se puede agregar una cuenta";
                    }
                }
                else{
                    cout << "\nLa lista de cuentas esta llena\n";
                }
                break;

            case 3:
                ///Hacer Abonos
                cout << "Digite el Numero de la Cuenta: ";
                cin >> idCuenta;
                cuenta = BuscarCuenta(lstCuenta, contadorCuenta, idCuenta);
                if(cuenta !=NULL){
                    registrarAbono(cuenta);
                    cout << "\nEl Abono se registro con exito\n";
                }
                else{
                    cout << "\nLa cuenta no existe, no se puede registrar el abono\n";
                }
                break;

            case 4:
                ///Mostrar lista clientes
                if (contadorCl == 0){
                    cout << "\nLa lista esta vacia\n";
                }
                else{
                    cout << "Id\tNombre\tApellido\n";
                    for (int i=0;i<contadorCl;i++){
                        cout <<lstCl[i]->getIdCliente() << "\t";
                        cout <<lstCl[i]->getNombre() << "\t";
                        cout <<lstCl[i]->getApellido() << "\n";
                    }
                }
                break;

            case 5:
               ///Mostrar lista cuentas
                if (contadorCuenta == 0){
                    cout << "\nLa lista esta vacia\n";
                }
                else{
                    cout << "No\tCliente\t\tSaldo\n";
                    for (int i=0;i<contadorCuenta;i++){
                        cout <<lstCuenta[i]->getNumeroCuenta() << "\t";
                        cout <<lstCuenta[i]->getCliente()->getNombre() << " " << lstCuenta[i]->getCliente()->getApellido() << "\t";
                        cout << "$ " << lstCuenta[i]->getSaldo() <<endl;
                    }
                }

                break;

            case 6:
                ///Mostrar detalles de la Cuenta
                cout << "\n";
                cout << "Digite el Numero de la Cuenta: ";
                cin >> idCuenta;
                cuenta = BuscarCuenta(lstCuenta, contadorCuenta, idCuenta);
                if(cuenta){
                    verDetalles(cuenta);
                }
                else{
                    cout << "\nLa Cuenta No Existe, no se puede visualizar los detalles de la Cuenta\n";
                }



              /*  cout << "Digite el numero de la Cuenta: ";
                cin >> idCuenta;
                cuenta = BuscarCuenta(lstCuenta, contadorCuenta, idCuenta);
                if(cuenta != NULL){
                    //se encontro
                    cout << "\n";
                    cout << "No Cuenta : " << cuenta->getNumeroCuenta() <<endl;
                    cout << "Cliente : " << cuenta->getCliente()->getNombre() << " " << cuenta->getCliente()->getApellido() << endl;
                    cout << "Saldo: $ " << cuenta->getSaldo();
                    cout << "\n";
                    if (cuenta->getContadorAbonos() == 0){
                        cout << "\nNo tiene Abonos registrados\n";
                    }
                    else{
                        cout << "\n";
                        cout << "Abonos\nFecha\t\tMonto del Abono\n";
                        Abono **lista = cuenta->getLstAbonos();
                        for (int i=0; i < cuenta->getContadorAbonos();i++){
                            lista[i]->getFechaAbono()->mostrarFecha();
                            //cout << "\t";
                            cout << "\t $" << lista[i]->getMontoAbono() << endl;
                        }
                    }
                }
                else{
                    cout << "\nLa Cuenta No Existe, no se puede visualizar los detalles de la Cuenta\n";
                }*/







                break;

            case 7:
                ///Salir
                cout << "\nSaliendo del programa\n";
                break;

            default:
                cout << "\nError, opcion no definida\n";
                break;
        }
        system ("pause");
    }while (opc !=7);
    return 0;
}
