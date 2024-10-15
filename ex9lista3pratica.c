#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 10


void imprimeTabuleiro(int tabuleiro[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int contarVizinhosVivos(int tabuleiro[M][N], int i, int j) {
    int contagem = 0;


    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue;
            int novoI = i + x;
            int novoJ = j + y;

            if (novoI >= 0 && novoI < M && novoJ >= 0 && novoJ < N) {
                contagem += tabuleiro[novoI][novoJ];
            }
        }
    }

    return contagem;
}


void aplicaRegras(int tabuleiro[M][N], int novaMatriz[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int vizinhos = contarVizinhosVivos(tabuleiro, i, j);


            if (tabuleiro[i][j] == 1) {
                if (vizinhos < 2 || vizinhos > 3) {
                    novaMatriz[i][j] = 0;
                } else {
                    novaMatriz[i][j] = 1;
                }
            } else {
                if (vizinhos == 3) {
                    novaMatriz[i][j] = 1;
                } else {
                    novaMatriz[i][j] = 0;
                }
            }
        }
    }
}


void copiaMatriz(int destino[M][N], int origem[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}


void preencheAleatoriamente(int tabuleiro[M][N]) {
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = rand() % 2;
        }
    }
}

int main() {
    int tabuleiro[M][N], novaMatriz[M][N];


    preencheAleatoriamente(tabuleiro);

    printf("Tabuleiro inicial:\n");
    imprimeTabuleiro(tabuleiro);


    for (int i = 0; i < 5; i++) {
        aplicaRegras(tabuleiro, novaMatriz);
        copiaMatriz(tabuleiro, novaMatriz);
        printf("Iteracao %d:\n", i + 1);
        imprimeTabuleiro(tabuleiro);
    }

    return 0;
}

