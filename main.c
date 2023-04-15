#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>

void cargarDatosPila(Pila *,int), pasarDeUnaPilaAOtra(Pila *, Pila *), pasarAOtraPilaConservarOrden(Pila *, Pila *),
     ordenarSeleccion(Pila *), insertarDatoEnPila(Pila *, int), ordenamientoPorSeleccion(Pila *), ordenarPorInserccion(Pila *),
     vaciarPila(Pila *, Pila *);

int encontrarMenor(Pila *), sumarTopeYAnterior(Pila *), contarPila(Pila *), sumatoriaPila(Pila *), dePilaADecimal(Pila *);

float divideYVenceras(int, int), promedioPila(Pila *);

int main(){

    srand(time(NULL));
    Pila pila, auxPila; int num, suma, menor;  char resp;
    inicpila(&pila);
    inicpila(&auxPila);
    do {
        printf("\nSeleccione una opcion para continuar, presione Escape para salir del programa\n");
        printf("\n1. Ingresar elementos a la pila en un valor ingresado por el usuario\n");
        printf("\n2. Pasar los elementos de una pila a otra\n");
        printf("\n3. Pasar los elementos de una pila a otra pero conservando el orden\n");
        printf("\n4. Encontrar el menor elemento de la pila\n");
        printf("\n5. Ordenamiento por seleccion\n");
        printf("\n6. Insertar un valor ingresado por el usuario\n");
        printf("\n7. Ordenamiento por inserccion\n");
        printf("\n8. Sumar los ultimos dos valores de una pila\n");
        printf("\n9. Funcion para calcular el promedio\n");
        printf("\n10. De pila a Decimal\n");
        printf("\n11. Vaciar la Pila\n");
        printf("\n12. Rellenar con valores aleatorios\n");

        resp = getch( );
        system("CLS");

         switch(resp){
            case '1':
                printf("\nIngrese la cantidad de elementos para cargar en la pila: ");
                scanf("%d", &num);
                cargarDatosPila(&pila,num);
                mostrar(&pila);
            break;
            case '2':
                if (!pilavacia(&pila)){
                    pasarDeUnaPilaAOtra(&pila, &auxPila);
                    printf("\nLa pila luego del pasaje\n");
                    mostrar(&pila);
                    printf("\nLa otra pila\n");
                    mostrar(&auxPila);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    pasarDeUnaPilaAOtra(&pila, &auxPila);
                    printf("\nLa pila luego del pasaje\n");
                    mostrar(&pila);
                    printf("\nLa otra pila\n");
                    mostrar(&auxPila);

                }
            break;
            case '3':
                if (!pilavacia(&pila)){
                    pasarAOtraPilaConservarOrden(&pila, &auxPila);
                    printf("\nLa pila luego del pasaje\n");
                    mostrar(&pila);
                    printf("\nLa otra pila\n");
                    mostrar(&auxPila);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    pasarAOtraPilaConservarOrden(&pila, &auxPila);
                    printf("\nLa pila luego del pasaje\n");
                    mostrar(&pila);
                    printf("\nLa otra pila\n");
                    mostrar(&auxPila);
                }
            break;
            case '4':
                if (!pilavacia(&pila)){
                    mostrar(&pila);
                    menor = encontrarMenor(&pila);
                    printf("\nEl menor elemento de la pila es %d\n", menor);
                    apilar(&pila,menor);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    mostrar(&pila);
                    menor = encontrarMenor(&pila);
                    printf("\nEl menor elemento de la pila es %d\n", menor);
                    apilar(&pila,menor);
                }
            break;
            case '5':
                if (!pilavacia(&pila)){
                    mostrar(&pila);
                    ordenamientoPorSeleccion(&pila);
                    printf("\nLa pila luego de ordenarla\n");
                    mostrar(&pila);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    mostrar(&pila);
                    ordenamientoPorSeleccion(&pila);
                    printf("\nLa pila luego de ordenarla\n");
                    mostrar(&pila);
                }
            break;
            case '6':
                if (!pilavacia(&pila)){
                    printf("\nIngrese un valor para agregar a la pila\n");
                    scanf("%d", &num);
                    ordenamientoPorSeleccion(&pila);
                    insertarDatoEnPila(&pila,num);
                    mostrar(&pila);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    printf("\nIngrese un valor para agregar a la pila\n");
                    scanf("%d", &num);
                    ordenamientoPorSeleccion(&pila);
                    insertarDatoEnPila(&pila,num);
                    mostrar(&pila);
                }
            break;
            case '7':
                if (!pilavacia(&pila)){
                    ordenarPorInserccion(&pila);
                    mostrar(&pila);
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    ordenarPorInserccion(&pila);
                    mostrar(&pila);
                }
            break;
            case '8':
                if (!pilavacia(&pila)){
                    suma = sumarTopeYAnterior(&pila);
                    mostrar(&pila);
                        if (suma)
                            printf("\nLa suma del ultimo y ante ultimo valor de la pila es %d \n", suma);
                        else
                            printf("\nLa suma no puede realizarce porque no habia cantidad suficientes de elementos\n");
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    mostrar(&pila);
                    if (suma)
                            printf("\nLa suma del ultimo y ante ultimo valor de la pila es %d \n", suma);
                        else
                            printf("\nLa suma no puede realizarce porque no habia cantidad suficientes de elementos\n");
                }
            break;
            case '9':
                if (!pilavacia(&pila)){
                    promedioPila(&pila);
                    mostrar(&pila);
                    printf("%f", promedioPila(&pila));
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 15);
                    promedioPila(&pila);
                    mostrar(&pila);
                    printf("%f", promedioPila(&pila));
                }
            break;
            case 33:
                if (!pilavacia(&pila)){
                    printf("\n\nLa pila pero en decimal %.d\n", dePilaADecimal(&pila));
                } else {
                    printf("\nLa pila esta vacia, se van a cargar 15 elementos aleatorios\n");
                    cargarElementosCantidad(&pila, 5);
                    mostrar(&pila);
                    printf("\n\nLa pila pero en decimal %.d\n", dePilaADecimal(&pila));
                }
            break;
            case 64:
                vaciarPila(&pila, &auxPila);
                mostrar(&pila);
                mostrar(&auxPila);
            break;
            case 35:
                cargarElementosCantidad(&pila, 10);
                mostrar(&pila);
            break;
        }
        printf("\nPresione una tecla para continuar...\n");
        getche();
        system("CLS");
    } while (resp != 27);
    return 0;
}

/*1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el
usuario.*/

void cargarDatosPila(P_Pila p,int cantElementos){

    int i;

    //Carga los valores que el usuario desee
    for (i=0; i<cantElementos; i++){
        leer(p);
    }
}

/*2. Hacer una función que pase todos los elementos de una pila a otra.*/

void pasarDeUnaPilaAOtra(Pila * pPila, Pila * pOtraPila){

    while (!pilavacia(pPila)){
        apilar(pOtraPila, desapilar(pPila));
    }
}

/*3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.*/

void pasarAOtraPilaConservarOrden (Pila * pPila, Pila * pOtraPila){

    Pila auxPila;//Pila auxiliar de la funcion
    inicpila(&auxPila);

    //Cargamos auxPila con los datos de la Pila
    pasarDeUnaPilaAOtra(pPila,&auxPila);

    //CARGAMOS LA OTRAPILA CON LOS DATOS DE AUX
    pasarDeUnaPilaAOtra(&auxPila, pOtraPila);
}

/*4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La
misma debe eliminar ese dato de la pila.*/

int encontrarMenor(Pila * pPila){

    //Pilas a utilizar en la funcion
    Pila menor, auxPila;
    inicpila(&auxPila);
    inicpila(&menor);

    //Guardamos el tope para poder comparar
    apilar(&menor,desapilar(pPila));

    //Algoritmo para sacar el menor elemento de la pila
    while(!pilavacia(pPila)){
        //Si tope de la pila es menor al menor cambia el valor
        if (tope(pPila) < tope(&menor)) {
            apilar(&auxPila, desapilar(&menor));
            apilar(&menor, desapilar(pPila));

        //Sino desapila para seguir comparando valores
        } else {
            apilar(&auxPila,desapilar(pPila));
        }
    }

    //Paseje de valores
    pasarDeUnaPilaAOtra(&auxPila, pPila);

    //se retorna el menor dato de la pila
    return desapilar(&menor);

}

/*5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)*/

void ordenarSeleccion(Pila * pPila){

    //Pila a usar
    Pila auxPila;

    inicpila(&auxPila);

    //Mientras que la pila no este vacia pasa parametros
    while(!pilavacia(pPila)){
        apilar(&auxPila, encontrarMenor(pPila));//Se guarda el menor elemento en cada vuelta
    }

    pasarDeUnaPilaAOtra(&auxPila, pPila);//Volvemos a llenar la pila
}

/*6. Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden
de ésta.*/

void insertarDatoEnPila(Pila * pPila, int num){

    //Pila auxiliar para usar en la funcion
    Pila auxPila;
    inicpila(&auxPila);

    //Buscamos el hueco para insertar el valor
    while (!pilavacia(pPila) && tope(pPila) < num){
        apilar(&auxPila, desapilar(pPila));
    }

    //Metemos el valor en el hueco
    apilar(pPila, num);

    pasarDeUnaPilaAOtra(&auxPila,pPila);//Llenamos de nuevo la pila

}

/*7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)*/

void ordenarPorInserccion (Pila * pPila){

    Pila auxPila;
    inicpila(&auxPila);

    //Ordenar cada valor en una pila auxiliar
    while (!pilavacia(pPila)){
        insertarDatoEnPila(&auxPila, desapilar(pPila));
    }

    pasarAOtraPilaConservarOrden(&auxPila, pPila);
}

/*8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior),
sin alterar su contenido.*/

int sumarTopeYAnterior(Pila * pPila){
    //REFACTORIZAR
    Pila auxPila;   int suma=0, cont = 0;
    inicpila(&auxPila);

    while (!pilavacia(pPila) && cont < 1){
        apilar(&auxPila, desapilar(pPila));
        cont ++;
    }

    if (!pilavacia(pPila) && !pilavacia(&auxPila)){
        suma = tope(&auxPila) + tope(pPila);
        pasarDeUnaPilaAOtra(&auxPila,pPila);
    }

    return suma;

}

/*9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también
una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro
funciones, y la función que calcula el promedio invoca a las otras 3.*/

int sumatoriaPila(Pila * pPila){

    Pila auxPila; int sumaTotal;

    inicpila(&auxPila);

    //Sumatoria de la pila
    while (!pilavacia(pPila)){
        sumaTotal += tope(pPila);
        apilar(&auxPila,desapilar(pPila));
    }

    //la pila queda como estaba y retornamos el valor
    pasarDeUnaPilaAOtra(&auxPila,pPila);

    return sumaTotal;
}

int contarPila(Pila * pPila){

    Pila auxPila;   int cont = 0;

    inicpila(&auxPila);

    //Cantidad de elementos para calcular el promedio
    while (!pilavacia(pPila)){
        cont ++;
        apilar(&auxPila,desapilar(pPila));
    }

    pasarDeUnaPilaAOtra(&auxPila,pPila);

    return cont;
}

float divideYVenceras(int sumaTotal, int cont){
    //Casteo muy importante
    return sumaTotal / (float)cont;
}

float promedioPila(Pila * pPila){
    //Funcion controladora
    return (float)divideYVenceras(sumatoriaPila(pPila), contarPila(pPila));

}

/*10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de
quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo, la pila:
1
4
6
7
5
Debe retornar el número: 14675 */

int dePilaADecimal(Pila * pPila){

    Pila auxPila; double exponente = 0; int sumatoria = 0;

    inicpila(&auxPila);

    //Damos vuelta la pila para que el valor de la base sea el primero a iterar
    pasarDeUnaPilaAOtra(pPila,&auxPila);

    while (!pilavacia(&auxPila)){

        //Sumamos todos los valores multiplicados por 10 elevado a su posicion
        sumatoria += pow(10,exponente) * tope(&auxPila);
        exponente ++;
        apilar(pPila, desapilar(&auxPila));
    }

    //Dejamos la pila como estaba
    pasarDeUnaPilaAOtra(&auxPila, pPila);

    //retornamos ese valor
    return sumatoria;


}

void vaciarPila(Pila * pPila, Pila * pPilaAux){

    while(!pilavacia(pPila)){
        desapilar(pPila);
    }
    while(!pilavacia(pPilaAux)){
        desapilar(pPilaAux);
    }
}
