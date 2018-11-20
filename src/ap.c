#include <stdio.h>
/*
Toma o último elemento como pivô, colocando na posição correta.
E todos os elementos à sua esquerda, e os maiores à direita
*/
int partition (int *in, int sta, int end) { 
    int pivot = in[end];
    int i = (sta - 1); //Menor elemento
  
    for (int j = sta; j <= end - 1; j++) { 
        // Caso seja menor ou igual ao pivô
        if (in[j] <= pivot) { 
            i++;
            swap(&in[i], &in[j]); 
        } 
    } 
    swap(&in[i + 1], &in[end]); 
    return (i + 1); 
} 
  
/*
Implementação do quicksort, recebe um vetor a ser desordenado, o indice de fim e o indice de inicio
*/
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

typedef struct _ap {
	int sta;	//Primeiro elemento da PA
	int len;	//Tamanho da PA
	int rat;	//Razão da PA
} AP;

/*
Busca uma PA especifica dentro de um vetor ordenado dado
Recebe o vetor, o inicio da PA, e a razão desejada
Retorna uma PA com todos os seus dados
*/
AP get_ap (int *in, int sta, int rat) {
	int last = sta;	//Ultimo elemento encontrado até agora, auxiliar
	int len = 1;	//Tamanho, começando a contar pelo primeiro elemento (vulgo sta)
	
	if (int i = 0; in[i] <= last+rat; i++) {	//Rodar até ultrapassar o proximo elemento da PA desejada
		if (in[i] == last+rat) {				//Caso encontre
			len++;								//Adicionar 1 no tamanho
			last += rat;						//Atualizar o auxiliar
		}
	}
	AP out; //Estrutura que vamos retornar
	out.sta = sta;
	out.len = len;
	out.rat = rat;
	
	return (out);
}

void best_ap (int *in, int len) {
	quickSort(in, 0, len-1);
}
