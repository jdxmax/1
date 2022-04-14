/*
 ============================================================================
 Name        : TP1.c
 Author      : Escobar Juan Ignacio
 Version     :
 Copyright   : DIVISION F
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "funcionesImpresionPorPantallaTP1.h"
#include "funcionesCalculosTP1.h"
#include "dataInOutValidateTP1.h"

int main()
{
	setbuf(stdout,NULL);

    int opcion;
    int opcionSubmenu;

    float km=0;
    float precioAA = 0;
    float precioLatam = 0;

    //costos AA
    float precioTdAA=0;
    float precioTcAA=0;
    float precioBtcAA=0;
    float precioAAUnitario=0;

    //costos LATAM
    float precioTdLatam=0;
    float precioTcLatam=0;
    float precioBtcLatam=0;
    float precioLatamUnitario=0;

    float precioDiferencia=0;

    int continuar = 1;

    do{

        mostrarMenuInicial(km, precioAA, precioLatam);
        opcion = recibirOpcionMenuPrincipal(km, precioAA, precioLatam);
        limpiarPantalla();

        switch(opcion){
            case 1:
                km = cargarKilometros();
                break;
            case 2:
                mostrarSubmenuAereolineas();
                opcionSubmenu = recibirOpcionSubmenu();
                if(opcionSubmenu==1){
                    precioAA = cargarPrecio();
                }else{
                    precioLatam = cargarPrecio();
                }
                break;
            case 3:
                if(km>0 && precioAA>0 && precioLatam>0){
                    precioTdAA = calcularPrecioTD(precioAA);
                    precioTdLatam = calcularPrecioTD(precioLatam);

                    precioTcAA = calcularPrecioTC(precioAA);
                    precioTcLatam = calcularPrecioTC(precioLatam);

                    precioBtcAA = calcularPrecioBTC(precioAA);
                    precioBtcLatam = calcularPrecioBTC(precioLatam);

                    precioAAUnitario = calcularPrecioUnitario(precioAA, km);
                    precioLatamUnitario = calcularPrecioUnitario(precioLatam, km);

                    precioDiferencia = diferenciaPrecio(precioAA,precioLatam);

                    calcularTodosLosCostos();

                }else{
                    noRealizarCalculos();
                }
                break;
            case 4:
                if(precioAAUnitario>0){
                    printf("\nLatam:\n");
                    printf("\na) Precio con tarjeta de débito: %.2f", precioTdLatam);
                    printf("\nb) Precio con tarjeta de crédito: %.2f", precioTcLatam);
                    printf("\nc) Precio pagando con bitcoin : %f", precioBtcLatam);
                    printf("\nd) Precio unitario: %.2f", precioLatamUnitario);
                    printf("\n\nAerolíneas:\n");
                    printf("\na) Precio con tarjeta de débito: %.2f", precioTdAA);
                    printf("\nb) Precio con tarjeta de crédito: %.2f", precioTcAA);
                    printf("\nc) Precio pagando con bitcoin : %f", precioBtcAA);
                    printf("\nd) Precio unitario: %.2f", precioAAUnitario);
                    printf("\n\nLa diferencia de precio es : %.2f", precioDiferencia);
                    printf("\n\n\n\n");
                }else{
                    noMostrarCalculos();
                }
                break;
            case 5:
                km = 7090;
                precioLatam = 162965;
                precioAA = 159339;

                precioTdAA = calcularPrecioTD(precioAA);
				precioTdLatam = calcularPrecioTD(precioLatam);

				precioTcAA = calcularPrecioTC(precioAA);
				precioTcLatam = calcularPrecioTC(precioLatam);

				precioBtcAA = calcularPrecioBTC(precioAA);
				precioBtcLatam = calcularPrecioBTC(precioLatam);

				precioAAUnitario = calcularPrecioUnitario(precioAA, km);
				precioLatamUnitario = calcularPrecioUnitario(precioLatam, km);

				precioDiferencia = diferenciaPrecio(precioAA,precioLatam);

                break;
            case 6:
                continuar = confirmacionSalida();
                break;
        }

    }while(continuar);

    return 0;
}



