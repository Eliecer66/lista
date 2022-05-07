#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdbool.h>
#include <stddef.h>

typedef struct lista lista_t;

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
lista_t *lista_crear(void);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
bool lista_esta_vacia(const lista_t *lista);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
bool lista_insertar_primero(lista_t *lista, void *dato);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
bool lista_insertar_ultimo(lista_t *lista, void *dato);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
void *lista_borrar_primero(lista_t *lista);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
void *lista_ver_primero(const lista_t *lista);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
void *lista_ver_ultimo(const lista_t* lista);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
size_t lista_largo(const lista_t *lista);

/*
 *PRE-CONDICIONES:
 *POST-CONDICIONES:
 */
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

#endif //_LISTA_H_
