#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"

static void pruebas_lista_creada() {

    printf("INICIO DE PRUEBAS DE LISTA CREAR.\n");

  //Definición de variables a usar
    lista_t* lista = lista_crear();
    int dato = 10;
    void* elemento = &dato;
    int* def_dato;

    //Prueba de crear lista y verificar que este vacia.
    pa2m_afirmar(lista_esta_vacia(lista), "lista recien creada, la lista esta vacia.");
    
    //Prueba de ver elementos cuando la lista esta vacia.
    def_dato = lista_ver_primero(lista);
    pa2m_afirmar(def_dato == NULL, "lista recien creada, lista ver primero es igual a NULL.");
    def_dato = lista_ver_ultimo(lista);
    pa2m_afirmar(def_dato == NULL, "lista recien creada, lista ver ultimo es igual a NULL.");
    
    //Prueba de borrar lista cuando la lista esta vacia.
    def_dato = lista_borrar_primero(lista);
    pa2m_afirmar(def_dato == NULL, "lista recien creada, lista borrar primero es igual a NULL.");

    //Prueba de ver largo cuando la lista esta vacia.
    pa2m_afirmar(lista_largo(lista) == 0, "lista recien creada, lista largo es igual a 0.");

    //Prueba de cargar pila insertando por el primer elemeto.
    pa2m_afirmar(lista_insertar_primero(lista, elemento), "lista recien creada, inserto primero elemento.");
    pa2m_afirmar(!lista_esta_vacia(lista), "La lista no esta vacia.");
    
    //Prueba de borrar un elemento de la pila.
    def_dato = lista_borrar_primero(lista);
    pa2m_afirmar(*def_dato == dato, "Se borró el unico elemento.");
    pa2m_afirmar(lista_esta_vacia(lista), "La lista esta vacia.");

    //Prueba de destruccion de la lista cuando está vacia.
    lista_destruir(lista, NULL);
}
#define REGULAR 10
#define PRIMERO 1
#define ULTIMO 0

bool lista_cargar(lista_t* lista, void* elemento[], size_t top, bool lugar) {
  for(int i = 0; i < top; i++) {
    if (lugar) {
      if(!lista_insertar_primero(lista, elemento[i])) {
        return false;
      }
    } else {
      if(!lista_insertar_ultimo(lista, elemento[i])) {
        return false;
      }
    }
  }
  return true;
}

static void pruebas_lista_invariantes() {

  printf("INICIO PRUEBAS DE LISTA INVARIANTES.\n");

  //Definición de variables a usar
  lista_t* lista = lista_crear();
  int dato = 10;
  void* elemento[REGULAR];
  elemento[0] = &dato;
  int* def_dato;


  //Pruebas de cargar elementos a la pila por el primero, verificar que el final no varia.
  pa2m_afirmar(lista_cargar(lista, elemento, REGULAR, PRIMERO), "La lista se cargo con una cantidad de elementos.");
  def_dato = lista_ver_primero(lista);
  pa2m_afirmar( dato == *def_dato, "Despues de cargar elementos a la lista por el primero se mantiene, el primero invariante.");

  //Destruyo la lista creada
  lista_destruir(lista, NULL);

}

int main() {
  pruebas_lista_creada();
  pruebas_lista_invariantes();
  return pa2m_mostrar_reporte();
}
//Pruebas cuando esta recien creado/esta vacio
//Pruebas de invariantes (que en este caso seria encolar y desencolar algunos elementos y chequear que cumpla las propiedades)
//Pruebas de volumen (variando los elementos que se insertan)
//Pruebas de destruccion (guardar elementos y aplicar su correspondiente funcion de destruccion al final)
//Si amerita, pruebas de iteradores