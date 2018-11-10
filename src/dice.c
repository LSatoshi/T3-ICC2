#include <stdlib.h>
#include <stdio.h>

int sum(int *arr, int n){
	int i, sum = 0;
	for(i = 0; i < n; i++) sum += arr[i];
	return(sum);
}

//n dados de m lados resultando em X
void comb(int n, int m, int X){
	int *dices, i, j, cont = 0;
	dices = (int*)malloc((n+1)*sizeof(int)); //cria um vetor n+1 posicoes
	for(i = 0; i < n; i++) dices[i] = 1; 
	dices[n] = 0; // a posicao n eh usada para verificar se todas combinacoes ja foram feitas
	while(dices[n] == 0){
		if(sum(dices, n) == X) cont++;
		if(dices[0] < m) dices[0]++;
		else {
			dices[0] = 1;
			j = 1;
			dices[j]++;
			while(dices[j] > m){
				dices[j] = 1;
				dices[j+1]++;
				j++;
			}
		}
	}
	printf("Há %d modos de se obter %d lancando %d dados com %d lados", cont, X, n, m);
	free(dices);
	return;
}

int main(){
	int n, m, X;
	printf("digite o numero de dados\n>");
	scanf("%d", &n);
	printf("digite o numero de faces dos dados\n>");
	scanf("%d", &m);
	printf("digite o numero que deseja obter\n>");
	scanf("%d", &X);
	comb(n,m,X);
	return(0);
}
	
