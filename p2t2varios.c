//LETRA
/*1) Declarar usando matriz de adyacencia un grafo G de N vértices (tener en cuenta que
N puede variar, pero en principio tomar N=15)
2) Definir G con todos sus vértices aislados
3) Poblar el grafo con 25 aristas (no hacerlo a mano).
4) Investigue si el método empleado asegura que el grafo quede conexo.
5) En caso de que no se cumpla 4) modificar el método para que estemos seguros que
sea un grafo conexo (el grafo puede tener más aristas que las 25 adicionales)
6) Proporcione un método que nos diga si un vértice está aislado
7) Dado un vértice, declarar una función que nos indique cuáles son sus vértices
adyacentes
8) Determinar, dado G cuál es su grado mínimo y máximo
9) Implemente DFS usando el algoritmo sugerido en el teórico.
10) Desarrollar una función que indique que un grafo dado es completo o no.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

///////////////////////////////////////////////////////////////////////////////

int mostrar_matriz(int **matriz, int dim); /*imprime matriz en pantalla*/
int **ini_matriz(int dim);                 /*inicializa matriz a 0     */
int **cargar_grafo_rnd();                   /*carga grafo con valores ejemplo*/
void conectarGrafo(int ** matriz, int dim);
void forzarAislado(int ** matriz, int dim);
///////////////////////////////////////////////////////////////////////////////

int main() {
  int op = 1, dim = 0;
  int **matriz = NULL;

  while (op != 0) {
    printf("MENU\n");
    printf("1.Crear e inicializar Matriz.\n");
    printf("2.Cargar Aristas random.\n");   
    printf("3.Mostrar Matriz de Adyacencia.\n");
    printf("4.Conectar Grafo.\n");
    printf("5.Forzar primer nodo aislado.\n");
    printf("6.Vertice aislado?.\n");
    printf("7.Vertices adyacentes de un vertice dado.\n");
    printf("8.Grado minimo y maximo.\n");
    printf("9.DFS.\n");
    printf("10.Grafo es completo?.\n");
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
      if (matriz != NULL){
        printf("Cargando aristas random...\n");
        matriz = cargar_grafo_rnd(matriz, dim);
      }else
        printf("Matriz vacia, cargue matriz primero.\n");
      break;      
    case 3:
      if (matriz != NULL)
        mostrar_matriz(matriz, dim);
      else
        printf("Matriz vacia, cargue matriz primero.\n");
      break;
    case 4:
      if (matriz != NULL)
        conectarGrafo(matriz, dim);        
      else
        printf("Matriz vacia, cargue matriz primero.\n");
      break;          
    case 5:
      if (matriz != NULL)
        forzarAislado(matriz, dim);        
      else
        printf("Matriz vacia, cargue matriz primero.\n");
      break;      
    break;
    case 6:
      
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
  printf("\nVisualizando matriz:\n");
  for (a = 0; a < dim; a++) {
    for (b = 0; b < dim; b++) {
      printf(" %d", matriz[a][b]);
    }
    printf("\n");
  }  
}

// reserva e incializa matriz. devuelve puntero
int **ini_matriz(int dim) {
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

//recorre matriz randomizando entre 0 y 1
int **cargar_grafo_rnd(int ** matriz, int dim) {
  int j,k,diagonal=0,conexo=0;
  double tmp;

  for(j=0;j<dim;j++){
    for(k=0;k<=j;k++){        
      tmp = rand();
      tmp = tmp/RAND_MAX; //divido entre el maximo entero para tener entre 0 y 1
      tmp = round(tmp);   //redondeo para tener solo enteros
      matriz[j][k] = (int) tmp;
      matriz[k][j] = matriz[j][k];
      //printf("-%d-",matriz[j][k]);
      printf("\n");      
    }
  }  
  mostrar_matriz(matriz, dim);
  return matriz;
}

//comprueba si hay nodos aislados, si lo encuentra randomiza hasta conectar.
void conectarGrafo(int ** matriz, int dim){
  //es conexo? -> recorro cada nodo para ver si hay alguno todo 0
  //si hay alguno -> randomizo las posibles aristas de ese nodo

  int conexo = 0, j, k;
  double tmp;
  for(j=0;j<dim;j++){
    while(conexo == 0){
      //recorro nodo para ver si conexo
      for(k=0;k<dim;k++){
        if (matriz[j][k] == 1) {
          conexo = 1;
          k=dim; //nodo conexo -> salir del for
        }
      }
      //si nodo aislado -> randomizo aristas de nodo
      if (conexo == 0) {
        //recorro nodo randomizando aristas
        for(k=0;k<dim;k++){
          tmp = rand();
          tmp = tmp/RAND_MAX; //divido entre el maximo entero para tener entre 0 y 1
          tmp = round(tmp);   //redondeo para tener solo enteros
          matriz[j][k] = (int) tmp;
          matriz[k][j] = matriz[j][k];
        }
      }    
    }
    conexo=1;      
  }
  mostrar_matriz(matriz,dim);
}

void forzarAislado(int ** matriz, int dim){
  int j,k;
  for(j=0;j<dim;j++){           
    matriz[0][j] = 0;        
  }
  for(j=0;j<dim;j++){           
    matriz[j][0] = 0;        
  }
  mostrar_matriz(matriz,dim);
}




