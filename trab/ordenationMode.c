#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int particiona_random(long int v[], long int a, long int c);
void troca(long int v[], long int c, long int n);
int particiona(long int v[], long int i, long int a);

//insertion 

int contadorQuick = 0;



void sortMethode(int n, int* ptr){

    int i,j, min, t;
    int contador=0;
    for (i = 1; i < n; i++) {
        contador++;      
        min=ptr[i];
        for (j=i; j>=1 && min< ptr[j-1];j--){
            ptr[j]=ptr[j-1];
            contador++;
        }   
        ptr[j]=min;
    }

    //printf("sort vector\n");
    //for (int i=0;i<n;i++){
    //    printf("%d ", ptr[i]);
    //}
    
    printf("contador: %i\n", contador);
    
}


//selection

void sort(long int n, long int* vet){

    printf("\n");

    int count = 0;

    for (long int i = 0; i < n - 1; i++) {
        long int min_index = i;

        //find min index
        for (long int j = i + 1; j < n; j++) {
            if (vet[j] < vet[min_index]) { //erro de segmentação
                min_index = j;

            }
        }
        //swap
        if (min_index != i) {
            long int temp = vet[i];
            count++;
            vet[i] = vet[min_index];
            vet[min_index] = temp;
        }
    }
    /*
    printf("sort vector\n");

    //printer
    for (int i=0;i<n;i++){
        printf("%i ", vet[i]);
    }
    */
    printf("\ncontador: %i\n", count);
}

//bubble

int swap (long int *a, long int *b){
   int temp=*(b);
   *b=*a;
   *a=temp;
   return 1;
};

void bubble(long int n, long int *ptr) 
{   
    printf("\n");

    int i, j;
    int cont = 0;   
    for (i = 0; i < n; i++) {   
        for (j = i + 1; j < n; j++) {   
            if (*(ptr + j) < *(ptr + i)) {   
                cont += swap((ptr + j), (ptr + i)); 
            }
        } 
    }

    printf("contador: %d\n", cont);
    //PrintArray(n,ptr);
    //printf("\n");
}

//quick

void quick_sort(long int vet[], long int inicio, long int fim)
{
    int cont = 0;
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}
//função para particionar
int particiona_random(long int vet[], long int inicio, long int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}
//troca
void troca(long int vet[], long int i, long int j)
{
    contadorQuick++;
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}
//
int particiona(long int vet[], long int inicio, long int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

//metodo bubble
double testaTempo(long int vet1, long int n){
    //teste de vetor
    clock_t begin = clock();
    //função de teste
    bubble(vet1, n);
    clock_t final = clock();
    double time_spent = (double)(final-begin)/CLOCKS_PER_SEC;
    return time_spent;
}

//selection
double testaTempo2(long int *vet1, long int n){
    clock_t begin = clock();
    //função de teste
    sort(n, vet1);
    clock_t final = clock();
    double time_spent = (double)(final-begin)/CLOCKS_PER_SEC;
    return time_spent;
}
//insertion
double testaTempo3(long int vet1, long int n){
    clock_t begin = clock();
    //função de teste
    sortMethode(n, vet1);
    clock_t final = clock();
    double time_spent = (double)(final-begin)/CLOCKS_PER_SEC;
    return time_spent;
}
//quick sort
double testaTempo4(long int vet1, long int n){
    clock_t begin = clock();
    //função de teste
    quick_sort(vet1, 0, n);
    clock_t final = clock();
    double time_spent = (double)(final-begin)/CLOCKS_PER_SEC;
    return time_spent;
}

int main(){

    //primeiro vet

    long int n1 = 1000000;

    long int *vet1 = (long int *)malloc(n1* sizeof(long int));

    long int *vet2 = (long int *)malloc(n1* sizeof(long int));
    long int *vet3 = (long int *)malloc(n1* sizeof(long int));
    long int *vet4 = (long int *)malloc(n1* sizeof(long int));

    srand(time(NULL));


    for ( long int i = 0; i < n1; i++)
    {
        vet1[i] = (rand()%1000000);
    }

    for (long int i = 0; i < n1; i++)
    {
        vet2[i]=vet3[i]=vet4[i]=vet1[i];
    }
    



    //long int n2 = sizeof(vet1);
    /*
    clock_t begin = clock();
    bubble(n1, vet1);
    clock_t final = clock();
    double time_spent = (double)(final-begin)/CLOCKS_PER_SEC;
    printf("tempo de execução: %f\n", time_spent);
    */

   // clock_t init = clock();
    //sortMethode(n1, vet1);
    //clock_t finally = clock();
    //double time_sp = (double)(finally-init)/CLOCKS_PER_SEC;
    printf("BUBLLE:\n");
    printf("Tempo de execução: %f\n", testaTempo(n1, vet1));
    printf("\n");
    printf("\n");
    printf("SELECTION\n");
    printf("Tempo de execução: %f\n", testaTempo2(vet2, n1));
    printf("\n");
    printf("\n");
    printf("INSERTION\n");
    printf("Tempo de execução: %f\n", testaTempo3(vet3, n1));
    printf("\n");
    printf("\n");
    printf("QUICK\n");
    printf("Tempo de execução: %f\n", testaTempo4(vet4, n1));
    printf("contador: %d", contadorQuick);
    printf("\n");


    free(vet1);
    free(vet2);
    free(vet3);
    free(vet4);
    return 0;
}