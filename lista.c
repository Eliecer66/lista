#include "lista.h"
#include <stdlib.h>
typedef struct nodo nodo_t;

struct nodo {
    void* elemento;
    nodo_t* siguiente;
};

struct lista {
    nodo_t* primero;
    nodo_t* final;
    size_t cantidad;
};

lista_t* lista_crear() {
    lista_t* new_lista = malloc(sizeof(lista_t));
    if (new_lista == NULL) {
        return NULL;
    }
    new_lista->primero = NULL;
    new_lista->final = NULL;
    new_lista->cantidad = 0;

    return new_lista;
}

bool lista_esta_vacia(const lista_t *lista) {
    if (lista->primero == NULL) {
        return true;
    }
    return false;
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
    nodo_t* new_nodo = malloc(sizeof(nodo_t));
    if (new_nodo == NULL) {
        return NULL;
    }
    new_nodo->elemento = dato;
    if (lista_esta_vacia(lista)) {
        new_nodo->siguiente = NULL;
        lista->final = new_nodo;
        lista->primero = new_nodo;
    }
    
    new_nodo->siguiente = lista->primero;
    lista->primero = new_nodo;
    lista->cantidad++;
    return true;    
}

bool lista_insertar_ultimo(lista_t* lista, void *dato) {
    nodo_t* new_nodo = malloc(sizeof(nodo_t));
    if (new_nodo == NULL) {
        return NULL;
    }
    new_nodo->siguiente = NULL;
    new_nodo->elemento = dato;
    lista->final->siguiente = new_nodo;
    lista->final = new_nodo;
    lista->cantidad++;
    return true;
}
#include <stdio.h>
void *lista_borrar_primero(lista_t *lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    if (lista->primero == lista->final) {
        lista->final = NULL;
        lista->primero->siguiente = NULL;
    }
    nodo_t* aux = lista->primero;
    void* dato = lista->primero->elemento;
    lista->primero = lista->primero->siguiente;
    lista->cantidad--;
    free(aux);
    return dato;
}

void *lista_ver_primero(const lista_t* lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    return lista->primero->elemento;
}

void *lista_ver_ultimo(const lista_t* lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    return lista->final->elemento;
}

size_t lista_largo(const lista_t *lista) {
    if (lista_esta_vacia(lista)) {
        return 0;
    }
    size_t cantidad = lista->cantidad;
    return cantidad;
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)) {
    
    while (!lista_esta_vacia(lista)) {
        if (destruir_dato == NULL) {
            lista_borrar_primero(lista);
        } else {
            destruir_dato(lista->primero->elemento);
            lista_borrar_primero(lista);
        }
    }
    free(lista);
}