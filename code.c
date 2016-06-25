#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	char operacao[50];
	int quantidadeReceitas = 0;
	int quantidadeDespesas = 0;
	float receitaValor = 0;
	float despesaValor = 0;
	char dataReceita[20];
	char dataDespesa[20];
	float totalReceita = 0;
	float totalDespesa = 0;
	int saldoInicial = 0;
	int linha = 0;

	while( scanf("%s", operacao) != EOF ){
		linha++;
		if (strcmp(operacao, "saldo:") == 0 ) {
			scanf("%d", &saldoInicial);
			fprintf(stdout, "%s %d\n", operacao, saldoInicial);
		}

		if (strcmp(operacao, "receita:") == 0 ) {
			scanf("%s", &dataReceita);
			scanf("%f", &receitaValor);
			totalReceita += receitaValor;
			quantidadeReceitas++;
		} else if (strcmp(operacao, "despesa:")  == 0) {
			scanf("%s", &dataDespesa);
			scanf("%f", &despesaValor);
			totalDespesa += despesaValor;
			quantidadeDespesas++;
		} else {
			fprintf(stderr, "Na linha %d o texto era %s", linha, operacao);
		    time_t t;
		    time(&t);
			fprintf(stderr, "%s - erro de balanco na linha %d\n", ctime(&t), linha);
		}
	}

	fprintf(stdout, "Quantidade de receita: %d, VALOR DA RECEITA %.2f \n", quantidadeReceitas, totalReceita);
	fprintf(stdout, "Quantidade de despesa: %d, VALOR DA DESPESA %.2f \n", quantidadeDespesas, totalDespesa);

	return 0;
}
