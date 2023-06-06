#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////

int mostrar_matriz(int **matriz, int dim); /*imprime matriz en pantalla*/
int **ini_matriz(int dim);                 /*inicializa matriz a 0     */
int **cargar_grafo_ej();                   /*carga grafo con valores ejemplo*/
int obtener_arista(int *arista);           /*entrada de usuario         */
int arista_existe(int **matriz, int arista1, int arista2);/*si existe->1;sino->0*/
int op_arista_pertenece(int **matriz);     /*funcion menu  */
int nodo_adyacente();            
int op_nodo_adyacente(int **matriz);       /*funcion menu  */

///////////////////////////////////////////////////////////////////////////////

int main() {
  int op, dim = 0;
  int **matriz = NULL;
  while (op != 0) {
    printf("MENU\n");
    printf("1.Inicializar Matriz Vacia.\n");
    printf("2.Cargar Aristas\n");
    printf("3.Arista pertenece?\n");
    printf("4.Nodos Adyacentes?\n");
    printf("0.Salir\n");
    printf("=>");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Ingrese dimension\n");
      scanf("%d", &dim);
      matriz = ini_matriz(dim);
      break;
    case 2:
      matriz = cargar_grafo_ej();
      break;
    case 3:
      
      if (matriz != NULL) {
        op_arista_pertenece(matriz);
      }else{
        printf("Matriz vacia. Cargar Matriz.\n");
      }
      break;
    case 4:
      if (matriz != NULL) {
         op_nodo_adyacente(matriz);
      }else{
        printf("Matriz vacia. Cargar Matriz.\n");
      }        
    break;
    case 5:
      mostrar_matriz(matriz, dim);
    break;
    case 0:
        printf("Chau\n");
    break;
    }
  }
  free(matriz);    
}

///////////////////////////////////////////////////////////////////////////////

int mostrar_matriz(int **matriz, int dim) {
  int a, b;
  printf("Visualizando matriz:\n");
  for (a = 0; a < dim; a++) {
    for (b = 0; b < dim; b++) {
      printf(" %d", matriz[a][b]);
    }
    printf("\n");
  }
  printf("\n");
}

int **ini_matriz(dim) {
  int **matriz = NULL;
  int a, b;
  matriz = (int **)malloc(dim * sizeof(int *));
  
  for (a = 0; a < dim; a++) {
    matriz[a] = (int *)malloc(dim * sizeof(int));
    for (b = 0; b < dim; b++) {
      matriz[a][b] = 0;
    }
  }
  mostrar_matriz(matriz, dim);
  return matriz;
}

int **cargar_grafo_ej() {
  int dim = 7;
  int **matriz = ini_matriz(dim);

  matriz[0][1] = 1;
  matriz[1][0] = 1;
  matriz[1][2] = 1;
  matriz[2][1] = 1;
  matriz[1][3] = 1;
  matriz[3][1] = 1;
  matriz[3][4] = 1;
  matriz[4][3] = 1;
  matriz[4][5] = 1;
  matriz[5][4] = 1;
  matriz[5][6] = 1;
  matriz[6][5] = 1;
  matriz[5][2] = 1;
  matriz[2][5] = 1;

  mostrar_matriz(matriz, dim);
  return matriz;
}

int obtener_arista(int *arista) {
  printf("Ingrese primer elemento:\n=>");
  scanf("%d", &arista[0]);
  printf("Ingrese segundo elemento:\n=>");
  scanf("%d", &arista[1]);
  printf("\n");
}

int arista_existe(int **matriz, int arista1, int arista2) {
  // como nombre de arista = posicion en matriz...
  if ((matriz[arista1][arista2] == 1) || (matriz[arista2][arista1] == 1)) {
    return 1;
  } else {
    return 0;
  }
}

int op_arista_pertenece(int **matriz) {
  int *arista = (int *)malloc(2 * sizeof(int));
  int resultado = 0;
  obtener_arista(arista);
  resultado = arista_existe(matriz, arista[0], arista[1]);

  if (resultado == 1) {
    printf("Arista {%d,%d} encontrada\n", arista[0], arista[1]);
  } else {
    printf("Arista {%d,%d} no encontrada\n", arista[0], arista[1]);
  }
  free(arista);
}

int nodo_adyacente(){  
}

int op_nodo_adyacente(int **matriz){
  int *nodos = (int *)malloc(2 * sizeof(int));
  int resultado = 0;
  //reciclando, si son adjacentes tienen arista.
  obtener_arista(nodos); 
  resultado = arista_existe(matriz, nodos[0],nodos[1]);
  
  if (resultado == 1) {
    printf("Nodos %d y %d son adyacentes\n\n", nodos[0], nodos[1]);
  } else {
    printf("Nodos %d y %d no son adyacentes\n\n", nodos[0], nodos[1]);
  }
  
  free(nodos);
}
