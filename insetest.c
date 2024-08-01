#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void sort(int n, int* ptr) {
    int i, j, min, t;
    int contador = 0; // Inicializar contador
    for (i = 1; i < n; i++) {
        min = ptr[i];
        for (j = i; j >= 1; j--) { // Incrementar contador a cada comparação
            if (min < ptr[j - 1]) {
                contador++;
                ptr[j] = ptr[j - 1];
            } else {
                break; // Parar o loop quando a comparação for falsa
            }
        }
        ptr[j] = min;
    }
    printf("sort vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\ncontador %i\n", contador);
}




int main() 
{ 
    // vector size
    long int n = 100000; 
    // memory allocation

    int *vet = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

   int i;

    for (int i=0; i< n; i++){
        vet[i]=(rand()%1000);
    }    
    
    printf("Created vector: ");

    for(i=0; i < n; i++)
   {
        printf("%d ", vet[i]);
   }


    clock_t begin = clock();    
    sort(n, vet); 
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n end time: %f", time_spent);
    free(vet);
    return 0; 
} 




