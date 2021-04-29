#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;
int enlarge_called=0;

struct Pair {
     char * key;
     void * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {

int posicion;

posicion = hash(key,map->capacity);
Pair* par_nuevo = createPair(key,value);

if(map->size >= map->capacity * 0.7){// se arreglan las colisiones
  map = (HashMap*)realloc(map,sizeof(HashMap)*2);
  map->capacity *= 2;
}

while(map->buckets[posicion]!=NULL){//se evalua las siguientes posiciones para agregar algun dato repetido
  posicion++;
  if(posicion == map->capacity){
   posicion=0; 
  }
}

map->buckets[posicion] = par_nuevo;
map->size++;

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap* map = (HashMap*)malloc(sizeof(HashMap));

  map->current = -1;
  map->size = 0;
  map->capacity = capacity;

  map->buckets = (Pair**)calloc(capacity,sizeof(Pair*));
  for(int i=0;i<capacity;i++){
    map->buckets[i] = NULL;
  }

  return map;
}

void eraseMap(HashMap * map,  char * key) {    

  int posicion;
  int i=0;

  posicion = hash(key,map->capacity);

  if(strcmp(map->buckets[posicion]->key,key)==0){
    map->buckets[posicion]->key = NULL;
    map->size-=1;
  }

  while(i<map->capacity){
    i++;
    if(map->buckets[i]!=NULL){
      if(strcmp(map->buckets[i]->key,key)==0){
        map->buckets[i]->key = NULL;
        map->size -=1;
      }
    }
  }

}

void * searchMap(HashMap * map,  char * key) {   

  int posicion;

  posicion = hash(key,map->capacity);
  int i=0;

  if(map->buckets[posicion] == NULL){ 
    return NULL;
  }

  if(strcmp(map->buckets[posicion]->key,key) == 0){ 
    map->current = posicion;
    return map->buckets[posicion]->value;
  }else{

    while(i<map->capacity){
      i++;
      if(map->buckets[i] != NULL){
        if(strcmp(map->buckets[i]->key,key) == 0){
          map->current = i;
          return map->buckets[i]->value;
        }
      }
    }
  }
return NULL;
}

void * firstMap(HashMap * map) {

  int primero;
  int i=0;

    if(map->buckets[i] != NULL){
      primero = i;
    }else{
      while(i<map->capacity){
        i++;
        if(map->buckets[i] != NULL){
          return map->buckets[i]->value;
        }
      }
    }
    return map->buckets[primero]->value;
}

void * nextMap(HashMap * map) {

    return NULL;
}
