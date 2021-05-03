#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct almacenamiento_pokemon{
  int id;
  int PC;
  int PS;
  char* nombre;
  char* sexo;
}almacenamiento_pokemon;

typedef struct pokedex{
  int cantidad;
  int numero_pokedex;
  char * nombre;
  char * tipos;
  char * evPrevia;
  char * evPosterior;
  char * region;
}pokedex;

/*prototipos*/
const char *get_csv_field();


int main(void) {

  HashMap* almacenamiento_pokemon = createMap(900);
  HashMap* pokedex = createMap(900);

  struct almacenamiento_pokemon *pokemochila;
  struct pokedex Pokedex;
  int p=0;
    int op;

    while(op!=0)
    {
        printf("---------------------------------------------------\n");
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
        printf("---------------------------------------------------\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);

        switch(op)
        {   
         /*   case 0: return 0;
            break;

            case 1: 
            break;*/

            case 2: 
              printf("Ingrese id en la pokedex del pokemon");//mochila
              scanf("%d", &pokemochila->id);
              printf("Ingrese nombre del pokemon");//mochila
              scanf("%s", pokemochila->nombre);
              printf("Ingrese PC del pokemon");//mochila
              scanf("%d", &pokemochila->PC);
              printf("Ingrese PS del pokemon");//mochila
              scanf("%d",&pokemochila->PS);
              printf("Ingrese sexo del pokemon");//mochila
              scanf("%s", pokemochila->sexo);

              if(/*condicion para comparar si esta en la pokedex*/){
              printf("Ingrese tipo del pokemon");//Pokedex
              scanf("%s", Pokedex->tipos);
              printf("Ingrese la evolucion previa del pokemon");//Pokedex
              scanf("%s", Pokedex->evPrevia);
              printf("Ingrese la evolucion posterior del pokemon");//Pokedex
              scanf("%s", Pokedex->evPosterior);
              printf("Ingrese la region del pokemon");//Pokedex
              scanf("%s", Pokedex->region);
              }
            break;

           // case 3: 
           // break;

            case 4: printf("Buscar pokemon por nombre ");
                    printf("Ingrese el nombre del pokemon a buscar");
                    scanf("%c", pokemochila->nombre);

                    
            /*case 5: 
            break;

            case 6:
            break;

            case 7: 
            break;

            case 8: 
            break;
            case 9: 
            break;

            case 10: 
            break;*/
        }
    }

	return 0;
}

/*funciones*/

const char *get_csv_field (char * tmp, int k) {
  int open_mark = 0;
  char* ret=(char*) malloc (1000*sizeof(char));
  int ini_i=0, i=0;
  int j=0;
  while(tmp[i+1]!='\1'){

    if(tmp[i]== '\"'){
        open_mark = 1-open_mark;
        if(open_mark) ini_i = i+1;
        i++;
        continue;
    }

    if(open_mark || tmp[i]!= ','){
        if(k==j) ret[i-ini_i] = tmp[i];
        i++;
        continue;
    }

    if(tmp[i]== ','){
      if(k==j) {
        ret[i-ini_i] = 0;
        return ret;
      }
      j++; ini_i = i+1;
    }

    i++;
  }

  if(k==j) {
      ret[i-ini_i] = 0;
      return ret;
  }

  return NULL;
}