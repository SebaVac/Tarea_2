#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct almacenamiento_pokemon {

  int id;
  int PC;
  int PS;
  char * nombre;
  char * sexo;

}almacenamiento_pokemon;

typedef struct pokedex{

  int cantidad;
  int numero_pokedex;
  char * nombre;
  char * tipos;
  char * desvolucion;
  char * evolucion;
  char * region;

}pokedex;


int main(void) {

  int p=0;
    int op;
    int num1,num2;

    while(op!=0)
    {
        printf("1.- Importar Pokemon\n");
        printf("2.- Pokemon Atrapado\n");
        printf("3.- Evolucionar pokemon\n");
        printf("4.- Buscar mis pokémon por tipo\n");
        printf("5.- Buscar mis pokémon por nombre\n");
        printf("6.- Buscar por nombre en pokédex\n");
        printf("7.- Mostrar todos los pokémon de la pokédex\n");
        printf("8.- Mostrar mis pokémon ordenados por PC\n");
        printf("9.- Liberar pokémon\n");
        printf("10.- Mostrar pokémon por región\n");
        printf("0 .- Salir\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);

        if(op!=4){printf("Introduce el primer numero: ");
        scanf("%d", &num1);
        printf("Introduce el segundo numero: ");
        scanf("%d", &num2);}

        switch(op)
        {
            case 1: printf("Suma: %d\n", (num1+num2));break;
            case 2: printf("Resta: %d\n", (num1-num2));break;
            case 3: printf("Multiplicacion: %d\n", (num1*num2));break;
            case 4: ;
            case 5: ;
            case 6: ;
            case 7: ;
            case 8: ;
            case 9: ;
            case 10: ;
        }
    }

	return 0;
}