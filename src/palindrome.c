#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
Recebe uma string e seu tamanho.
Retorna 1 caso seja palíndrome e 0 caso contrário
*/
int check_palin(char *in) {

	int size = strlen(in);

	for (int i = 0; i < size/2; i++) {
		if (in[i] != in[(size-1) - i]) return (0);
	}
	return (1);
}

/*
Recebe uma string, uma posição de início e uma de fim
Retorna uma partição da string dada, com as posições como limites
*/
char *slice_str(char *in, int sta, int end) {
	int size_in = strlen(in); //Tamanho da string de entrada
	if (end >= size_in || sta >= size_in || sta > end) return(NULL); //Caso os limites dados sejam inválidos

	int size_out = end - sta + 1; //Tamanho da string de saída
	char *out = (char *)malloc(size_out + 1); //Alocar uma nova string
	out[size_out] = '\0'; //Colocar o caractere nulo no fim da string

	for (int i = 0; i < size_out; i++) {
		out[i] = tolower(in[sta + i]); //Copiar para a string de saída, deixando minúscula just in case
	}

	return (out);
}

/*
Printa, um a um, os melhores trechos palíndromes (Utiliza o método guloso)
*/
void best_part(char *in) {
	int size = strlen(in);
	for (int sta = 0; sta < size;) { //Percorre o vetor, trecho a trecho
		char *best = NULL; //O melhor palindrome para determinado trecho
		int end_best; //Posição final do melhor palindrome
		
		for (int end = sta; end < size; end++) { //Encontra o melhor palindrome começando por uma posição (sta)
			char *tmp = slice_str(in, sta, end); //Cria uma substring com o sta e end atuais
			if (check_palin(tmp)) { //Checa se essa string é palindrome, se sim, ela é maior do que a armazenada anteriormente
				if (best != NULL) free(best);
				best = tmp;
				end_best = end;
			} else {
				free(tmp);
			}
		}
		sta = end_best + 1; //O novo início será a casa após o fim desse trecho
		printf("%s ", best); //Printa o melhor palíndrome do trecho
		free(best);
	}
}

int main(int argc, char **argv) {
	printf("resultado: ");
	best_part(argv[1]);
	printf("\n");
	
	return(0);
}
