#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

/*estructura de datos*/
struct almacenamiento_pokemon *pokemochila;
struct pokedex *Pokedex;

typedef struct almacenamiento_pokemon{
  int PC;
  int PS;
  char * nombre;
  char * sexo;
}almacenamiento_pokemon;

typedef struct PokemonMochila{//tipo de dato que se ingresa en el mapa
  int id;
  almacenamiento_pokemon * datos;
}PokemonMochila;

typedef struct pokedex{
  int id;
  int cantidad;
  int numero_pokedex;
  char * tipos;
  char * evPrevia;
  char * evPosterior;
  char * region;
}pokedex;

typedef struct PokemonPokedex{ //tipo de dato que se ingresa en el mapa
  int id;
  int cantidad;
  int numero_pokedex;
  pokedex * datos;
}PokemonPokedex;


/*prototipos*/
const char *get_csv_field();

PokemonMochila* createAlmacenamiento(char* nombre,char* sexo, int id, int PC, int PS);

PokemonPokedex* createPokedex(char* tipos,char* evPrevia,char* evPosterior,char* region, int numero_pokedex, int cantidad,int id);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);


int main(void) {

  //mapa con clave int para buscar pokemons con id
    Map * almacenamiento_pokemon_id = createMap(is_equal_int);
    Map* pokedex = createMap(is_equal_int);
    Map* pokemochila = createMap(is_equal_int);

  //mapa con clave string para buscar pokemons por nombre
    Map * almacenamiento_pokemon_nombre = createMap(is_equal_string);
    setSortFunction(almacenamiento_pokemon_nombre,lower_than_string);

    pokedex = createMap(is_equal_string);
    setSortFunction(pokedex,lower_than_string);

//-----------------------------------------------------------------------------------------------//

    PokemonMochila* mochila = createAlmacenamiento(mochila->datos->nombre,mochila->datos->sexo,mochila->id,mochila->datos->PC,mochila->datos->PS);

    insertMap(almacenamiento_pokemon_nombre, mochila->datos->nombre, mochila->datos->sexo);
    insertMap(almacenamiento_pokemon_id, &mochila->id, &mochila->datos);

//-----------------------------------------------------------------------------------------------//

    PokemonPokedex * PokeDex = createPokedex(PokeDex->datos->tipos,PokeDex->datos->evPrevia,PokeDex->datos->evPosterior,PokeDex->datos->region,PokeDex->numero_pokedex,PokeDex->cantidad,PokeDex->id);

    insertMap(almacenamiento_pokemon_nombre, PokeDex->datos->tipos, PokeDex->datos);
    insertMap(almacenamiento_pokemon_id, &PokeDex->datos->id, &PokeDex->datos);
    
//------------------------------------------------------------------------------------------------//
  int p=0;
  int id,PC,PS,numeroPokedex,cantidad;
  char* nombre,*sexo,*tipos,*evPrevia,*evPosterior,*region;
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
              printf("Ingrese id del pokemon en la pokedex");//mochila
              scanf("%d", &id);
              printf("\n");
              
              printf("Ingrese nombre del pokemon");//mochila
              scanf("%s", nombre);
              printf("\n");

              printf("Ingrese PC del pokemon");//mochila
              scanf("%d", &PC);
              printf("\n");

              printf("Ingrese PS del pokemon");//mochila
              scanf("%d",&PS);
              printf("\n");

              printf("Ingrese sexo del pokemon");//mochila
              scanf("%s", sexo);
              printf("\n");

              PokemonMochila * mochila = createAlmacenamiento(nombre,sexo,id,PC,PS);
              insertMap(almacenamiento_pokemon_id, &mochila->id, mochila->datos);

              if(searchMap(pokedex,&mochila->id) == NULL){
              printf("Ingrese tipo del pokemon(si el pokemon posee mas de un tipo, ingresar los tipos de la forma \"Tipo1-Tipo2\"): ");//Pokedex
              scanf("%s", tipos);
              printf("\n");

              printf("Ingrese la evolucion previa del pokemon");//Pokedex
              scanf("%s", evPrevia);
              printf("\n");

              printf("Ingrese la evolucion posterior del pokemon");//Pokedex
              scanf("%s", evPosterior);
              printf("\n");

              printf("Ingrese la region del pokemon");//Pokedex
              scanf("%s",region);
              printf("\n");

              printf("Ingrese el numero de la pokedex del pokemon atrapado: ");
              scanf("%i", &numeroPokedex);
              printf("\n");

              printf("Ingresar cantidad: ");
              scanf("%i", &cantidad);
              printf("\n");
              
              PokemonPokedex * PokeDex = createPokedex(tipos,evPrevia,evPosterior,region,numeroPokedex,cantidad,id);
              insertMap(almacenamiento_pokemon_nombre, nombre, PokeDex->datos);

              }
            break;

           // case 3: 
           // break;

           /* case 4: 

            PokeDex = createPokedex(tipos,evPrevia,evPosterior,region,numeroPokedex,cantidad,id);
            insertMap(almacenamiento_pokemon_nombre, nombre, PokeDex->datos);

                    printf("Ingrese el tipo del pokemon a buscar");
                    scanf("%c",tipos);
                    
                    printf("\n Buscando pokemon\n");
                    searchMap(almacenamiento_pokemon_id,&tipos);
                    
                    if(searchMap(almacenamiento_pokemon_nombre,&tipos)){
                    printf("%s (%d)\n", nombre, id);
                    }else{
                    printf("No existe el tipo\n");
                    }*/
                    
            /*case 5: 
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",nombre);

              searchMap(almacenamiento_pokemon_nombre, nombre);
              if(nombre){
                printf("Nombre: %s\n",);
                printf("Id: %i\n",);
                printf("PC: %i\n",);
                printf("PS: %i\n",);
                printf("Sexo: %s\n",);
              }else{
                printf("No se han encontrado Pokemones con el nombre \"%s\"",nombre);
              }
            break;

            case 6:
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",nombre);

              Pokedex* Busqueda = searchMap(pokedex, nombre);
              if(nombre){
                printf("Nombre: %s",busqueda->nombre);
              }
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


//funciÃ³n para comparar claves de tipo string, retorna 1 si son iguales
int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}


//funciÃ³n para comparar claves de tipo string, retorna 1 si son key1<key2
int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}


//funciÃ³n para comparar claves de tipo int, retorna 1 si son iguales
int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}


//funciÃ³n para comparar claves de tipo int, retorna 1 si son key1<key2
int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}


PokemonMochila* createAlmacenamiento(char* nombre,char* sexo, int id, int PC, int PS){
    PokemonMochila* b = (PokemonMochila*) malloc (sizeof(PokemonMochila));
    strcpy(b->datos->nombre,nombre);
    strcpy(b->datos->sexo,sexo);
    b->id= id; 
    b->datos->PC = PC;
    b->datos->PS = PS;
    return b;
}


PokemonPokedex* createPokedex(char* tipos,char* evPrevia,char* evPosterior,char* region, int numero_pokedex, int cantidad,int id){
    PokemonPokedex* p = (PokemonPokedex*) malloc (sizeof(PokemonPokedex));
    strcpy(p->datos->tipos,tipos);
    strcpy(p->datos->evPrevia,evPrevia);
    strcpy(p->datos->evPosterior,evPosterior);
    strcpy(p->datos->region,region);
    p->numero_pokedex=numero_pokedex; 
    p->cantidad=cantidad; 
    p->id=id; 
    return p;
}