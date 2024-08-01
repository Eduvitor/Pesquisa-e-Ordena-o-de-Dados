#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


//Questões para serem entregues. 

//1- Rode o código e verifique se está funcionando corretamente a partir do debug. 
        //sim o codigo roda, todos os ponteiros realizam sua função corretamente. 
//2- Crie uma variável para indicar quantas operações de comparação foram executadas pelo algortimo de bublle e pelo Insertion. Para a mesma entrada de 10000 elementos quantas comparações foram realizadas? 
        //insertion: 248228 comparações realizadas em um vetor aleatorio de 1000 posições; Bublle: 187273 comparações foram realizadas pelo algoritimo bubble;
//3- Quais são as diferenças entre os métodos bubble e insertion sort? 
        //a principal diferença entre esses dois algoritmos está na estratégia de ordenação. O Bubble Sort troca pares adjacentes, enquanto o Insertion Sort insere cada elemento na posição correta dentro da parte já ordenada da lista. 
        //O Bubble Sort tende a realizar mais trocas, tornando-o menos eficiente, especialmente em listas desordenadas, em comparação com o Insertion Sort.
//4- Existe algum caso em que o buble é melhor que o sort em número de comparações?
        //os dois metodos são igualmente ineficientes quando se tratam de vetores grandes, mas podem ser usados para vetores pequenos ou quase ordenados.
//5 - Compute o tempo para fazer o ordenamento de um mesmo vetor randômico com 100000 valores usando o bubble e o insertion. 
        //insertion: foi necessario 0.215000 milisegundos; bublle: foi necessario 0.288000 milisegundos;


void sort(int n, int* ptr){

    int i,j, min, t;
    int contador=0;
    for (i = 1; i < n; i++) {   
        min=ptr[i];
        for (j=i; j>=1 && min< ptr[j-1];j--){
            ptr[j]=ptr[j-1];
            contador++;
        }   
        ptr[j]=min;
    }
    printf("sort vector: ");
    for (int i=0;i<n;i++){
        printf("%d ", ptr[i]);
    }
    printf("\ncontador %i\n", contador);
}


int main() 
{ 
    // vector size
    long int n = 1000; 
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




