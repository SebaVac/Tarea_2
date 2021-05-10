#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

/*estructura de datos*/
typedef struct Pokemon{
  int id;
  int PC;
  int PS;
  char * nombre;
  char * sexo;
}Pokemon;

typedef struct pokedex{
  char* nombre;
  int cantidad;
  int numero_pokedex;
  char * tipo;
  char * evPrevia;
  char * evPosterior;
  char * region;
}pokedex;


/*prototipos*/
const char *get_csv_field();

Pokemon* crearPokemon(int id, char*nombre, int PC, int PS, char* sexo);

Pokemon* createAlmacenamiento(char* nombre,char* sexo, int id, int PC, int PS);

pokedex* createPokedex(char* tipos,char* evPrevia,char* evPosterior,char* region, int numero_pokedex, int cantidad,int id);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);


int main() {
  //mapa con clave int para buscar pokemons con id
    Map * almacenamiento_pokemon = createMap(is_equal_int);
    Map* pokedex = createMap(is_equal_string);
    setSortFunction(pokedex,lower_than_string);

   // Map* pokemochila = createMap(is_equal_int);

  //mapa con clave string para buscar pokemons por nombre
    Map * almacenamiento_pokemon_nombre = createMap(is_equal_string);
    setSortFunction(almacenamiento_pokemon_nombre,lower_than_string);

    pokedex = createMap(is_equal_string);
    setSortFunction(pokedex,lower_than_string);

    FILE *fp = fopen ("pokemonArchivo1.csv", "r");

    char linea[1024];

    fgets (linea, 1023, fp);

  int p=0;

  int id,PC,PS,numeroPokedex,cantidad;

  char* nombre,*sexo,*tipos,*evPrevia,*evPosterior,*region;

  Pokemon * Poke = NULL;
  pokedex * DEX = NULL;

  while (fgets(linea,1023,fp) != NULL){
    id= (int) strtol(get_csv_field(linea,0), NULL,10);
    nombre = (char*) get_csv_field(linea,1);
    tipos = (char*) get_csv_field(linea,2);
    PC = (int) strtol(get_csv_field(linea, 3), NULL, 10);
    PS = (int) strtol(get_csv_field(linea, 4), NULL, 10);
    sexo = (char*)get_csv_field(linea, 5);
    evPrevia = (char*)get_csv_field(linea, 6);
    evPosterior =(char*) get_csv_field(linea, 7);
    numeroPokedex=(int) strtol(get_csv_field(linea, 8), NULL, 10);
    region =(char*) get_csv_field(linea, 9);

    Poke = create_pokemon(id,nombre,PC,PS,sexo);
    PokemonPokedex = searchMap(pokedex, nombre);

    if (PokemonPokedex == NULL){

      PokemonPokedex= create_Pokedex(nombre,0,tipos,evPrevia,evPosterior,numeroPokedex,region);
      insertMap(pokedex,PokemonPokedex->nombre,PokemonPokedex);
      PokemonPokedex->cantidad = 1;

    }else{ 
    PokemonPokedex->cantidad++;
    }

    
    if(contPokALmacenados <= 100){
            insertMap(pokemonAlm,oPokemon->id,oPokemon);
            contPokALmacenados++;
        }



  }




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
            id = (int) malloc(sizeof(id));
            nombre = (char*) malloc(sizeof(nombre));
            PC = (int) malloc(sizeof(PC));
            PS = (int) malloc(sizeof(PS));
            sexo = (char*) malloc(sizeof(sexo));
            int cont;
            tipos = ((char*) malloc(*tipos));
            evPrevia = (char*) malloc(*evPrevia);
            evPosterior = (char*) malloc(*evPosterior);
            numeroPokedex = (int) malloc(numeroPokedex);
            region = (char*) malloc(*region);

            printf("2. Agregar un Pokemon al Almacenamiento \n");
            
            if(cont==100){

                printf("El almacenamiento esta lleno. \n");
                break;

            }

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
              
              cont++;
              
              //printf("%s %s %i %i %s %s %s %i %s\n",nombre,tipo,pc,ps,sexo,evolPrev,evolPost,numPokedex,region);
              
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
                    
            case 5: 
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",nombre);

              Pokemon* Busqueda = searchMap(almacenamiento_pokemon_nombre, nombre);
              if(nombre != NULL){
                printf("Nombre: %s\n",Poke->nombre);
                printf("Id: %i\n",Poke->id);
                printf("PC: %i\n",Poke->PC);
                printf("PS: %i\n",Poke->PS);
                printf("Sexo: %s\n",Poke->sexo);
              }else{
                printf("No se han encontrado Pokemones con el nombre \"%s\"",nombre);
              }
            break;

            case 6:
              printf("Ingresar nombre del pokemon: ");
              scanf("%s",nombre);

              pokedex * Busqueda = searchMap(pokedex, nombre);
              if(nombre){
                printf("Nombre: %s",Busqueda->nombre);
              }
            break;

            case 7: 

              mostrarPokedex(pokedex);

            break;

            case 8: 
              mostrarMochila(almacenamiento_pokemon);
            break;

            case 9: 
              
            break;

            case 10: 
            break;
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

Pokemon* crearPokemon(int id,char* nombre,int PC, int PS, char* sexo){

  Pokemon* Pokemochila = (Pokemon*)malloc(sizeof(Pokemon));

  Pokemochila->id = id;
  Pokemochila->nombre = nombre;
  Pokemochila->PC = PC;
  Pokemochila->PS = PS;
  Pokemochila->sexo = sexo;

  return Pokemochila;
}

pokedex* crearPokedex(char* nombre, int cantidad, char* tipo, char* evPrevia, char* evPosterior, int numero_pokedex, char* region){

  pokedex* dex =(pokedex*)malloc(sizeof(pokedex));
  
  dex->nombre = nombre;
  dex->cantidad = cantidad;
  dex->tipo = tipo,
  dex->evPrevia = evPrevia;
  dex->evPosterior = evPosterior;
  dex->numero_pokedex = numero_pokedex;
  dex->region = region;

  return dex;

}

void mostrarMochila(Map* map){

  Pokemon* Pokemochila = (Pokemon*)malloc(sizeof(Pokemon));
  Pokemochila = firstMap(map);

  int i=1;
  while(Pokemochila != NULL){
    printf("------------------------%i-------------------------",i);
  }

  printf("%i\n",Pokemochila->id);
  printf("%s\n",Pokemochila->nombre);
  printf("%i\n",Pokemochila->PC);
  printf("%i\n",Pokemochila->PS);
  printf("%s\n\n",Pokemochila->sexo);

  i++;
  Pokemochila = nextMap(map);
}

void mostrarPokedex(Map* map){

  pokedex * dex = (pokedex*)malloc(sizeof(pokedex));

  dex = firstMap(map);

  int i=0;
  while(dex != NULL){
    printf("------------------------%i-------------------------",i);

    printf("%s\n",dex->nombre);
    printf("%i\n",dex->cantidad);
    printf("%s\n",dex->evPrevia);
    printf("%s\n",dex->evPosterior);
    printf("%i\n",dex->numero_pokedex);
    printf("%s\n\n",dex->region);
    i++;

    dex = nextMap(map);
  }

}

void borrarPoke(Map *map,int id){

  Pokemon* Busqueda = searchMap(map, id);
  
  Busqueda = NULL;

}