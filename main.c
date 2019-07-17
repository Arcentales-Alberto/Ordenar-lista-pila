#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    short numero;
    struct elemento *siguiente;
}  nodo;

nodo* ingresarDato(void);
void apilar(nodo ** , nodo*); //Order node
nodo* datoDesapilado(short);
short desapilar(nodo **);
void listarPila(nodo *);
nodo* desapilo(nodo **);
void eliminarPila(nodo *);

int main()
{
    nodo *apuntador , *apuntadorAuxiliar;
    nodo *apuntador2 , *apuntadorAuxiliar2;
    nodo *apuntador3, *apuntadorAuxiliar3;
    apuntador = NULL;
    apuntador2 = NULL;
    apuntador3 = NULL;
    int opcion , cantidad;
    short numeroMaximo = 0 , numeroDesapilado = 0;
    system("color 9f");

    printf("Enter amount of data to stack: ");
    scanf("%d" , &cantidad);

    for(int i=0 ; i<cantidad ; i++)
    {
        apuntadorAuxiliar = ingresarDato();
        apilar(&apuntador , apuntadorAuxiliar);
    }

        printf("\nOrder stack\n");

        while(apuntador || apuntador2)
        {
           while(apuntador)
           {
            numeroDesapilado = desapilar(&apuntador);

             if(numeroDesapilado > numeroMaximo)
             {
               numeroMaximo = numeroDesapilado;
             }

               apuntadorAuxiliar2 = datoDesapilado(numeroDesapilado);
               apilar(&apuntador2 , apuntadorAuxiliar2);
           }


             while(apuntador2)
             {
                 numeroDesapilado = desapilar(&apuntador2);

                if(numeroDesapilado == numeroMaximo)
                {
                  apuntadorAuxiliar3 = datoDesapilado(numeroDesapilado);
                  apilar(&apuntador3 , apuntadorAuxiliar3);
                }
                else
                {
                  apuntadorAuxiliar = datoDesapilado(numeroDesapilado);
                  apilar(&apuntador , apuntadorAuxiliar);
                }

             }

             numeroMaximo = 0;

       }

        listarPila(apuntador3);
        eliminarPila(apuntador3);
        printf("\nFinish\n\n");

    return 0;
}
//////////////////////////////////////////////////////////////////////////
nodo* ingresarDato()
{
    int numero;
    nodo *apuntadorAuxiliar;

    apuntadorAuxiliar = (nodo*) malloc(sizeof(nodo));
    printf("Enter date: ");
    scanf("%d" , &numero);

    apuntadorAuxiliar->numero = numero;
    apuntadorAuxiliar->siguiente = NULL;

    return apuntadorAuxiliar;
}
///////////////////////////////////////////////////////////////////////////////////
void apilar(nodo **apuntador , nodo *apuntadorAuxiliar)
{
    apuntadorAuxiliar->siguiente = *apuntador;
    *apuntador = apuntadorAuxiliar;
}
////////////////////////////////////////////////////////////////////////////
nodo* datoDesapilado(short numero)
{
    nodo *apuntadorAuxiliar;

    apuntadorAuxiliar = (nodo*) malloc(sizeof(nodo));

    apuntadorAuxiliar->numero = numero;
    apuntadorAuxiliar->siguiente = NULL;

    return apuntadorAuxiliar;
}
//////////////////////////////////////////////////////////////////////////////////
void listarPila(nodo *apuntador)
{
    if(apuntador)
    {
      printf("%d\n" , apuntador->numero);
      listarPila(apuntador->siguiente);
    }
}
///////////////////////////////////////////////////////////////////////////////
short desapilar(nodo **apuntador)
{
     nodo *apuntadorAuxiliar;
     short numero = 0;

     apuntadorAuxiliar = apuntador;
     numero = (*apuntador)->numero;
    *apuntador = (*apuntador)->siguiente;
     free(apuntadorAuxiliar);

    return numero;
}
//////////////////////////////////////////////////////////////////////////
void eliminarPila(nodo *apuntador)
{
  nodo *apuntadorAuxiliar;

  while(apuntador)
  {
    apuntadorAuxiliar = apuntador;
    apuntador = apuntador->siguiente;
    free(apuntadorAuxiliar);
    printf("*");
  }
  printf("\n");
}
