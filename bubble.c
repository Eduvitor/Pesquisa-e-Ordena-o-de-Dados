#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

//   print array elements
void printArray(int n, int* ptr) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
};

void magica(int n, int* ptr) 
{ 
    int i, j, t;   
    for (i = 0; i < n; i++) {   
        for (j = i + 1; j < n; j++) { 
            if (*(ptr + j) < *(ptr + i)) {
                t++;   
                swap((ptr + j), (ptr + i)); //Questão 5 - O parâmetro desta função são valores ou ponteiros? Explique. 
            } 
        } 
    }   
    printf("sort vector:");
    printArray(n,ptr);
    printf("Contador: %d", t);
    printf("\n");
    
} 

void magica2(long int n, int **ptr) {
    int *arr = *ptr;

    for (long int i = 0; i < n - 1; i++) {
        for (long int j = 0; j < n - i - 1; j++) {
            if (arr[j] >arr[j + 1]) {
                int temp = arr[j];// Questão 6- Está sendo realizada a troca de um valor ou um ponteiro? 
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted vector: ");
    printArray(n, *ptr);
    printf("\n");
}
  
  
int main() //Questão 0- Verifique se as funções estão funcionando corretamente. Se não, faça a correção.
              //      - Estude o código.
              //      - Altere o valor de n para 1000000. O que pode estar acontecendo com o código?
{ 
    // vector size
    int n = 1000;
    // memory allocation    
    //int vet[n];// Questão 1 - Pq se deve alocar dinamicamente o vetor quando o n>>100 (grande)?
    int *vet=(int *)malloc(n*sizeof(int));
    srand(time(NULL));

    for (int i=0; i< n; i++){
        vet[i]=rand()%1000;
    }    
    
    //printArray(n,ptr);
        
    clock_t begin = clock();    
    magica(n, vet); //Questão 2 - Qual a diferença entre &vet e vet? 
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n end time: %f", time_spent);


   // Questão 3 - O que teremos que mudar para que função magina2 passe por parametro um ponteiro duplo 
    //begin = clock();    
    //magica2(n, &vet);
    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("\n end time: %f", time_spent); // // Questão 4: Pq o tempo de execução é bem menor na função ? 
    free(vet);
    return 0; 
} 