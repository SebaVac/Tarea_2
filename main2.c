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
  int cantidad;
  int numero_pokedex;
  int PC;
  int PS;
  char * nombre;
  char * sexo;
  char * tipos;
  char * evPrevia;
  char * evPosterior;
  char * region;
}almacenamiento_pokemon;

typedef struct almacenamiento{//tipo de dato que se ingresa en el mapa
  int id;
  almacenamiento_pokemon * datos;
}almacenamiento;


/*Prototipos*/
const char get_csv_field();

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}


int main(){

  /*se crean los mapas*/
  Map * mochila = createMap(is_equal_string);
  Map * pokedex = createMap(is_equal_int);

  int i;
  
  int * j = (int*) malloc(sizeof(int));
    *j=i;
    
  int* aux = firstMap(pokedex);
  while (aux){
    printf("%d ", *aux);
    aux = nextMap(pokedex);
  }
  printf("\n");


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
            case 0: return 0;
            break;
            int k;
            
            case 1: 
              while(fgets(linea,1023,f) != NULL){
                for(i=0;i<9;i++){
                  const char* aux = get_csv_field(linea,i);
                  insertMap(pokedex, , aux)(L,aux);
                }
              k++;
              if(k == 100){
                break;
              }
              }
            break;

            case 2: 
              printf("Ingrese id del pokemon en la pokedex");//mochila
              scanf("%d", &mochila->id);
              printf("\n");
              
              printf("Ingrese nombre del pokemon");//mochila
              scanf("%s", almacenamiento->datos->nombre);
              printf("\n");

              printf("Ingrese PC del pokemon");//mochila
              scanf("%d", &almacenamiento->datos->PC);
              printf("\n");

              printf("Ingrese PS del pokemon");//mochila
              scanf("%d", &almacenamiento->datos->PS);
              printf("\n");

              printf("Ingrese sexo del pokemon");//mochila
              scanf("%s", almacenamiento->datos->sexo);
              printf("\n");

              FILE *f = fopen("pokemonArchivo1.csv","a");

              /*se agregan saltos de lineas y "," para separar rut,nombre y la disponibilidad*/
              fputc('\n',f);
              fputc(almacenamiento->id,f);
              fputc(',',f);
              fputs(almacenamiento->datos->nombre,f);
              fputc(',',f);
              fputc(almacenamiento->datos->PC,f);
              fputc(',',f);
              fputc(almacenamiento->datos->PS,f);
              fputc(',',f);
              fputs(almacenamiento->datos->sexo,f);
              fputc(',',f);

              if(searchMap(mochila,&almacenamiento->id) == NULL){
              printf("Ingrese tipo del pokemon(si el pokemon posee mas de un tipo, ingresar los tipos de la forma \"Tipo1-Tipo2\"): ");//Pokedex
              scanf("%s", &almacenamientoPrincipal->datos->tipos);
              printf("\n");

              printf("Ingrese la evolucion previa del pokemon");//Pokedex
              scanf("%s", &almacenamientoPrincipal->datos->evPrevia);
              printf("\n");

              printf("Ingrese la evolucion posterior del pokemon");//Pokedex
              scanf("%s", &almacenamientoPrincipal->datos->evPosterior);
              printf("\n");

              printf("Ingrese la region del pokemon");//Pokedex
              scanf("%s",almacenamientoPrincipal->datos->region);
              printf("\n");

              printf("Ingrese el numero de la pokedex del pokemon atrapado: ");
              scanf("%i", &almacenamientoPrincipal->datos->numero_pokedex);
              printf("\n");

              printf("Ingresar cantidad: ");
              scanf("%i", &almacenamientoPrincipal->datos->cantidad);
              printf("\n");

              fputs(almacenamientoPrincipal->datos->tipos,f);
              fputc(',',f);
              fputs(almacenamientoPrincipal->datos->evPrevia,f);
              fputc(',',f);
              fputs(almacenamientoPrincipal->datos->evPosterior,f);
              fputc(',',f);
              fputs(almacenamientoPrincipal->datos->region,f);
              fputc(',',f);
              fputc(almacenamientoPrincipal->datos->numero_pokedex,f);
              fputc(',',f);
              fputc(almacenamientoPrincipal->datos->cantidad,f);
              
              }
            break;

           case 3: 
           break;

           case 4: 

             printf("Ingresar tipo/tipos del pokemon(si son mas de uno, ingresar de la forma \"Tipo1-Tipo2\"): ");
              scanf("%s",almacenamientoPrincipal->datos->tipos);

              searchMap(pokedex, almacenamientoPrincipal->datos->tipos);
              if(almacenamientoPrincipal->datos->tipos){
                printf("Nombre: %s\n",almacenamiento->datos->nombre);
                printf("Id: %i\n",);
                printf("PC: %i\n",);
                printf("PS: %i\n",);
                printf("Sexo: %s\n",);
              }else{
                printf("No se han encontrado Pokemones con el/los tipo(s) \"%s\"", almacenamientoPrincipal->datos->tipos);
              }
                    
            case 5: 
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",almacenamiento->datos->nombre);

              searchMap(pokedex, almacenamiento->datos->nombre);
              if(almacenamiento->datos->nombre){
                printf("Nombre: %s\n",almacenamiento->datos->nombre);
                printf("Id: %i\n",almacenamientoPrincipal->datos->id);
                printf("PC: %i\n",almacenamiento->datos->PC);
                printf("PS: %i\n",almacenamiento->datos->PS);
                printf("Sexo: %s\n",almacenamiento->datos->sexo);
              }else{
                printf("No se han encontrado Pokemones con el nombre \"%s\"",almacenamientoPrincipal->datos->nombre);
              }
            break;

            case 6:
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",nombre);

              
              if(nombre){
                printf("Nombre: %s",);
              }
            break;

            case 7: 
            break;

            case 8: 
            break;

            case 9:
             searchMap(mochila, almacenamiento->id);
             eraseMap(mochila, almacenamiento->id);
            break;

            case 10: 
              printf("Ingresar region: ");
              scanf("%s", almacenamientoPrincipal->datos->region);
              
              char* aux = searchMap(pokedex, almacenamientoPrincipal->datos->region);
            
            break;
        }
    }

  return 0;
}