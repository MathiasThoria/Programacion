#include <stdio.h>

typedef struct Nodo{
  int num;
  struct Nodo* sig;
}Nodo;

typedef struct Graph{
  int dimension;
  Nodo** lista;
}Graph;

 
int imprimirGrafo(Graph* graph) {
    int i;
    Nodo* nodo_tmp;
  
    for (i = 0; i < graph->dimension; i++) {
        nodo_tmp = graph->lista[i];
        printf("Nodo %d: ", i);
        while (nodo_tmp != NULL) {
            printf("%d -> ", nodo_tmp->num);
            nodo_tmp = nodo_tmp->sig;
        }
        printf("NULL\n");
    }
}

Graph* inicializar_grafo(int dim){
  int a;
  Graph* grafo = (Graph*) malloc(sizeof(Graph));
  printf("Dir: %p\n",&grafo);  
  grafo->lista = (Nodo**) malloc(sizeof(Nodo*) * dim);
  grafo->dimension = dim;
  
  for (a=0;a<dim;a++){
    grafo->lista[a] = NULL;
  };  
  return grafo;  
}

Nodo* crearNodo(int dest) { //Es una arista en realidad, pero definida por un nodo
    Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
    newNode->num = dest;
    newNode->sig = NULL;
    return newNode;
}

void agregarArista(Graph* graph, int origen, int destino) {
  //otra opcion, para no usar nodo_tmp:
    //nodo_nuevo->sig = graph->lista[origen];
    //graph->lista[origen] = nodo_nuevo;
    //
    //nodo_nuevo = crearNodo(origen);
    //nodo_nuevo->sig = graph->lista[dest];
    //graph->lista[dest] = nodo_nuevo;
    
    Nodo* nodo_nuevo = crearNodo(destino);
    Nodo* nodo_tmp;
  
    nodo_nuevo->sig = NULL;
    nodo_nuevo->num = destino;  
    nodo_tmp = graph->lista[origen];
  
    if (graph->lista[origen] == NULL){
      graph->lista[origen] = nodo_nuevo;
    } else {
      while (nodo_tmp->sig != NULL) {
        nodo_tmp = nodo_tmp->sig;
      }
      nodo_tmp->sig = nodo_nuevo;
    }

  //lo mismo pero en la otra direccion de arista
    nodo_nuevo = crearNodo(origen);
    nodo_nuevo->sig = NULL;
    nodo_nuevo->num = origen;  
    nodo_tmp = graph->lista[destino];
  
    if (graph->lista[destino] == NULL){
      graph->lista[destino] = nodo_nuevo;
    } else {
      while (nodo_tmp->sig != NULL) {
        nodo_tmp = nodo_tmp->sig;
      }
      nodo_tmp->sig = nodo_nuevo;
    }
}

void lista_nueva_menu(){
  int dim;
  Graph* grafo;
  printf("Indicar dimension:\n");
  scanf("%d",&dim);
  grafo = inicializar_grafo(dim);  
  imprimirGrafo(grafo);  
}

Graph * cargar_grafo_menu(){
  int a,dim;
  Graph * grafito;
  grafito = inicializar_grafo(7);
  agregarArista(grafito,0,1);
  agregarArista(grafito,1,2);
  agregarArista(grafito,1,3);
  agregarArista(grafito,3,4);
  agregarArista(grafito,4,5);
  agregarArista(grafito,5,6);
  agregarArista(grafito,5,2);  
  imprimirGrafo(grafito);
  return grafito;  
}

int arista_include(Graph * grafito, int nodo, int arista){
  Nodo* nodo_tmp;
  nodo_tmp = grafito->lista[nodo];
  while (nodo_tmp != NULL) {
    if (nodo_tmp->num == arista){
      return 1;
    }
    nodo_tmp = nodo_tmp->sig;
  }
  return 0;
}

int arista_include_menu(Graph * grafito){
  int arista, nodo, resultado;
  printf("Ingrese aristas a buscar:\n");
  printf("\n=>");
  scanf("%d",&nodo);
  printf("=>");
  scanf("%d",&arista);
  resultado = arista_include(grafito, nodo, arista);
  if (resultado){
    printf("Encontrado.Nodos adyacentes.\n"); 
  }else{
    printf("Nope.");
  }
}


int main(void) {
  int op; 
  Graph * grafito;
  while (op != 0) {
    printf("\nMENU\n");
    printf("1.Inicializar Lista Vacia.\n");
    printf("2.Cargar Grafo ejemplo.\n");
    printf("3.Arista pertenece?\n");
    printf("4.Nodos Adyacentes?\n");
    printf("5.Imprimir grafo.\n");
    printf("0.Salir\n");
    printf("=>");
    scanf("%d", &op);
    printf("\n");
    switch (op) {
    case 1:
      lista_nueva_menu();      
    break;
    case 2:
      grafito = cargar_grafo_menu();
    break;
    case 3:
      arista_include_menu(grafito);
    break;
    case 4:
      arista_include_menu(grafito);
    break;    
    case 5:
      imprimirGrafo(grafito);
    case 0:
        printf("Chau\n");
    break;
    }
  }   
}