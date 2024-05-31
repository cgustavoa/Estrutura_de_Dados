#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cidades.h"

// Função para inicializar as cidades a partir do arquivo de entrada
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Lendo o comprimento total da estrada e o número de cidades
    int T, N;
    fscanf(arquivo, "%d", &T);
    fscanf(arquivo, "%d", &N);

    // Alocando memória para a estrutura Estrada
    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    estrada->N = N;
    estrada->T = T;
    estrada->C = (Cidade *)malloc(N * sizeof(Cidade));

    // Lendo dados das cidades e populando a estrutura Estrada
    for (int i = 0; i < N; i++) {
        fscanf(arquivo, "%d %s", &estrada->C[i].Posicao, estrada->C[i].Nome);
    }

    fclose(arquivo);
    return estrada;
}

// Função para calcular a menor vizinhança
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return -1; // Erro ao ler o arquivo
    }

    double menorVizinhanca = estrada->T; // Inicializa com o comprimento total da estrada

    // Percorre todas as cidades para calcular a vizinhança
    for (int i = 0; i < estrada->N; i++) {
        double vizinhancaAtual = estrada->C[i].Posicao;

        // Para a primeira cidade, a vizinhança é a distância até o centro da cidade mais próxima
        if (i > 0) {
            vizinhancaAtual = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        }

        // Para a última cidade, a vizinhança é a distância até o final da estrada
        if (i < estrada->N - 1) {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        }

        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
        }
    }

    free(estrada->C);
    free(estrada);

    return menorVizinhanca;
}

// Função para encontrar a cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return NULL; // Erro ao ler o arquivo
    }

    double menorVizinhanca = estrada->T;
    char *cidadeMenor = estrada->C[0].Nome;

    // Percorre todas as cidades para calcular a vizinhança
    for (int i = 0; i < estrada->N; i++) {
        double vizinhancaAtual = estrada->C[i].Posicao;

        // Para a primeira cidade, a vizinhança é a distância até o centro da cidade mais próxima
        if (i > 0) {
            vizinhancaAtual = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        }

        // Para a última cidade, a vizinhança é a distância até o final da estrada
        if (i < estrada->N - 1) {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        }

        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
            cidadeMenor = estrada->C[i].Nome;
        }
    }

    free(estrada->C);
    free(estrada);

    return cidadeMenor;
}

int main() {
    printf("Menor vizinhança: %.2f\n", calcularMenorVizinhanca("teste01.txt"));
    printf("Cidade com menor vizinhança: %s\n", cidadeMenorVizinhanca("teste01.txt"));

    return 0;
}