#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "utilidades.h"
#include "clientes.h"
#include "consumos.h"
#include "arbol.h"
#include "lista.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"
#define ESC 27
#define DIM_CLI 100

void menuPrincipal();
void menuClientes();
void menuConsumos();
void menuModificacionDatos();
void menuADl();

nodoArbol* archivo2Arbol(nodoArbol* arbol);

int main()
{
    stCliente Lista[DIM_CLI];
    int vLista = 0;
    stConsumo Consumos[30];
    char opcion;
    char opcionCli;
    char opcionCon;
    char opcionArbol;
    int mesmax;
    int Array[mesmax];
    int vArreglo=1;
    int mes=0;
    srand (time(NULL));
    int id=0;
    int cont=0;

    nodoArbol* arbol = NULL;
    //stCliente c;
    //arbol = archivo2Arbol(arbol);
                        arbol = archivo2Arbol(arbol);
    system("pause");



    do
    {
        system("cls");
        menuPrincipal();
        fflush(stdin);
        opcion=getch();
        system("cls");
        switch(opcion){

        case '1':
            do
            {
                system("cls");
                menuClientes();
                opcionCli=getch();
                system("cls");
                switch(opcionCli){

                case '1':
                    cargarArchListaClientes();
                    break;
                case '2':
                    mostrarArchClientes();
                    printf("\n\n");
                    system("pause");
                    break;
                case '3':
                    encontrarClienteArch();
                    break;
                case '4':
                    funcion05();
                    printf("\n\n");
                    system("pause");
                    break;
                case '5':
                    ordenacionSeleccionArchivoDNI();
                    system("pause");
                    break;
                case '6':
                    ordenacionSeleccionArchivoApellido();
                    system("pause");
                    break;
                case '7':
                    muestraBuscaCliente();
                    system("pause");
                    break;
                case '8':
                    ordenacionSeleccionArchivoEmail();
                    system("pause");
                    break;

                }
            }while(opcionCli!=ESC);

            break;
        case '2':
            do
            {
                system("cls");
                menuConsumos();
                fflush(stdin);
                opcionCon=getch();
                system("cls");
                //srand (time(NULL));
                switch(opcionCon)
                {

                case '1':
                    cargaArchListaConsumos();
                    system("cls");
                    break;

                case '2':
                    mostrarArchConsumos();
                    system("pause");
                    break;
                case '3':
                    modificacionConsumo();
                    break;
                case '4':
                    modificoBajaConsumo();
                    break;
                case '5':
                    preguntaFechaConsumo();
                    system("pause");
                    break;
                case '6':

                    break;

                case '7':

                    mesmax=buscarMesMAX();
                    vArreglo=cargarArreglo(Array,vArreglo,mesmax);
                    muestraArreglo(vArreglo,Array);
                    system("pause");
                    system("cls");
                    mes=comprarMesMayor(Array,vArreglo);
                    printf("El mes con datos mas consumidos es %d.\n\n",mes);
                    system("pause");
                    break;

                }

            }
            while(opcionCon!=ESC);
            break;

        case '3':
            do
            {
                system("cls");
                menuADl();
                fflush(stdin);
                opcionArbol=getch();
                system("cls");
                //srand (time(NULL));
                switch(opcionArbol)
                {
                    case '1':

                        //inOrder(arbol);
                        //arbol = archivo2Arbol(arbol);
                        printf("El arbol fue cargado.. \n");
                        system("pause");
                        break;

                    case '2':
                        inOrder(arbol);
                        system("pause");
                        break;
                }
            }while(opcionArbol!=ESC);
            //break;
        }
    }

    while(opcion!=ESC);


    return 0;
}

///MENU PRINCIPAL.
void menuPrincipal()
{
    printf("\t\t <<MENU PRINCIPAL>>");
    printf("\n\n");
    printf("1- Listado de clientes.\n");
    printf("2- Listado de consumos.\n");
    printf("3- Listado de arboles. \n");
    printf("ESC para salir...");
}
///MENU DE LA LISTA DE CLIENTES.
void menuClientes()
{
    printf("\t\tListado de clientes.");
    printf("\n\n");
    printf("1- Cargar un cliente nuevo...\n\n");
    printf("2- Mostrar lista de clientes...\n\n");
    printf("3- Modificar un cliente...\n\n");
    printf("4- Dar de baja/alta un cliente...\n\n");
    printf("5- Mostrar clientes ordenados por DNI (activos)...\n\n");
    printf("6- Mostrar clientes ordenados por Apellido (activos)...\n\n");
    printf("7- Buscar un cliente por DNI...\n\n");
    printf("8- Mostrar clientes ordenados por mail (inactivos)...\n\n");
    printf("\n\n");
    printf("ESC para salir...");


}
///MENU DE LA LISTA DE CONSUMOS
void menuConsumos()
{
    printf("\t\tConsumos.");
    printf("\n\n");
    printf("1- Carga un consumo... \n\n");
    printf("2- Muestra consumos...\n\n");
    printf("3- Modificar consumo... \n\n");
    printf("4- Dar de baja un consumo...\n\n");
    printf("5- Mostrar consumos por fecha...\n\n");
    printf("7- Estadistica, Indica que mes se consume mas...");
    printf("\n\n");
    printf("ESC para salir...");
}


/**********************************************
MENU PARA MODIFICAR LOS DATOS DEL CLIENTE.
**********************************************/
void menuModificacionDatos()
{
    printf("Que datos desea modificar?\n");
    printf("\n");
    printf("\n1- Numero de Cliente.\n");
    printf("\n2- Nombre.\n");
    printf("\n3- Apellido.\n");
    printf("\n4- D.N.I.\n");
    printf("\n5- Email.\n");
    printf("\n6- Telefono.\n");
    printf("\n7- Domicilio.\n");
    printf("\n\n\n9- GUARDAR CLIENTE.\n");
    printf("\n");
    printf("ESC para salir...");
}

/**********************************************
MENU DE ARBOL DE LISTAS
**********************************************/
void menuADl()
{
    printf("ARBOL DE LISTAS\n");
    printf("\n");
    printf("\n1- Pasar del archivo de clientes al arbol\n");
    printf("\n2- Mostrar arbol en in order \n");
    printf("\n3- .\n");
    printf("\n4- .\n");
    printf("\n5- .\n");
    printf("\n6- .\n");
    printf("\n7- .\n");
    printf("\n8- .\n");
    printf("\n");
    printf("ESC para salir...");
}

nodoArbol* archivo2Arbol(nodoArbol* arbol)
{
    stCliente c;
    FILE* arch = fopen(AR_CLIENTES, "rb");

    if(arch)
    {
        while(fread(&c, sizeof(stCliente), 1, arch) > 0)
        {
            arbol = insertar(arbol, crearNodoArbol(c));
        }

        fclose(arch);
    }

    return arbol;
}
