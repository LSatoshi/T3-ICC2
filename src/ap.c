#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
Troca dois elementos
*/
void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
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
void quicksort(int *in, int sta, int end) { 
	if (sta < end) { 
		int pi = partition(in, sta, end); 
		quicksort(in, sta, pi - 1); 
		quicksort(in, pi + 1, end); 
	} 
} 




typedef struct _ap {
	int sta;	//Primeiro elemento da PA
	int len;	//Tamanho da PA
	int rat;	//Razão da PA
} AP;

/*
Imprime uma PA na tela
*/
void print_ap (AP A) {
	for (int i = 0; i < A.len; i++) {
		printf("%d ", (A.sta + i * A.rat));
	}
	printf("\n");
}

/*
Busca uma PA especifica dentro de um vetor ordenado dado
Recebe o vetor, o inicio da PA, e a razão desejada
Retorna uma PA com todos os seus dados
*/
AP get_ap (int *in, int sta, int rat) {
	int last = sta;	//Ultimo elemento encontrado até agora, auxiliar
	int len = 1;	//Tamanho, começando a contar pelo primeiro elemento (vulgo sta)
	
	for (int i = 0; in[i] <= last+rat; i++) {	//Rodar até ultrapassar o proximo elemento da PA desejada
		if (in[i] == last+rat) {				//Caso encontre
			len++;								//Adicionar 1 no tamanho
			last += rat;						//Atualizar o auxiliar
		}
	}
	AP out; //Estrutura que vamos retornar
	out.sta = sta;
	out.len = len;
	out.rat = rat;
	//print_ap(out); //Debug
	return (out);
}

/*
Retorna a melhor PA em um vetor ordenado
*/
AP best_ap (int *in, int len) {
	AP best, tmp;
	best.len = 0;
	
	
	//Subtrair todos os elementos por todos os elementos, para obter todas as razões e inicios possiveis
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			//Encontrar a pa requisitada
			tmp = get_ap(in, in[i], in[j]-in[i]);
			//Caso seja maior que a anterior, atualizar a melhor pa
			if (tmp.len > best.len) best = tmp;
		}
	}
	
	return (best);
}









int main(int argc, char **argv) {
	int len = argc-1; //Tamanho do vetor
	int *in = (int *)malloc((len)*sizeof(int));
	
	for (int i = 0; i < len; i++) {
		in[i] = strtol(argv[i+1], NULL, 10); //Converter as strings em ints
	}
	quicksort(in, 0, len-1); //Ordenar a entrada
	print_ap(best_ap(in, len)); //printar a melhor pa
}