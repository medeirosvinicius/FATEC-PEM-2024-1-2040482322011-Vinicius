#include <stdio.h>

// Gestão do Tabuleiro
void inicializarTabuleiro(char matriz[8][8][3], char coluna[8][3]) {
    // Preencher espaço vazio com x
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            matriz[i][j][0] = '-';
            matriz[i][j][1] = 'x';
            matriz[i][j][2] = '-';
        }
    }

    //  Colocando as peças Branças
    char brancas[] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    for (int j = 0; j < 8; j++) {
        matriz[7][j][0] = brancas[j];
        matriz[7][j][1] = 'B';
        matriz[7][j][2] = '0' + (j + 1);
    }

    // Colocando as peças Pretas
    char pretas[] = {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'};
    for (int j = 0; j < 8; j++) {
        matriz[0][j][0] = pretas[j];
        matriz[0][j][1] = 'p';
        matriz[0][j][2] = '0' + (j + 1);
    }

    // Colocando na Segunda Linha as peças pretas
    char peaoPreto[] = {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'};
    for (int j = 0; j < 8; j++) {
        matriz[1][j][0] = peaoPreto[j];
        matriz[1][j][1] = 'p';
        matriz[1][j][2] = '0' + (j + 1);
    }

    // Colocando as peças brancas na segunda Linha
    char peaoBranco[] = {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
    for (int j = 0; j < 8; j++) {
        matriz[6][j][0] = peaoBranco[j];
        matriz[6][j][1] = 'B';
        matriz[6][j][2] = '0' + (j + 1);
    }

    // Colocando as colunas na matriz
    char letras[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (int j = 0; j < 8; j++) {
        coluna[j][0] = '-';
        coluna[j][1] = letras[j];
        coluna[j][2] = '-';
    }
}

// Impressão do tabuleiro
void imprimirTabuleiro(char matriz[8][8][3], char coluna[8][3]) {
    // Imprimir o estado atual do tabuleiro
    printf(". ");
    for (int j = 0; j < 8; j++) {
        printf("%c%c%c ", coluna[j][0], coluna[j][1], coluna[j][2]);
    }
    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c%c%c ", matriz[i][j][0], matriz[i][j][1], matriz[i][j][2]);
        }
        printf("\n");
    }
}

// Função de Mover as peças
void moverPeca(char matriz[8][8][3], int origemL, int origemC, int destinoL, int destinoC) {
    // Função de Mover as peças de origem para destino de acordo com a localização "geoegrafica"
    matriz[destinoL][destinoC][0] = matriz[origemL][origemC][0];
    matriz[destinoL][destinoC][1] = matriz[origemL][origemC][1];
    matriz[destinoL][destinoC][2] = matriz[origemL][origemC][2];

    // Tirar  a visibilidade da matriz de origem
    matriz[origemL][origemC][0] = '.';
    matriz[origemL][origemC][1] = '.';
    matriz[origemL][origemC][2] = '.';
}

void chequePastor(char matriz[8][8][3], char coluna[8][3]) {
    // Tarefa 1:  Bispo branco de c1 para f4
    moverPeca(matriz, 7, 2, 4, 5);
    imprimirTabuleiro(matriz, coluna);

    // Tarefa 2: Peão preto de e7 para e5
    moverPeca(matriz, 1, 4, 3, 4);
    imprimirTabuleiro(matriz, coluna);

    // Tarefa 3: Peão branco de e2 para e4
    moverPeca(matriz, 6, 4, 4, 4);
    imprimirTabuleiro(matriz, coluna);

    // Tarefa 4: Cavalo preto de b8 para c6
    moverPeca(matriz, 0, 1, 2, 2);
    imprimirTabuleiro(matriz, coluna);

    // Tarefa 5: Rei preto de e8 para f7 (movimento ilegal, mas apenas para efeito de exemplo)
    moverPeca(matriz, 0, 4, 1, 5);
    imprimirTabuleiro(matriz, coluna);

    printf("\nCheque Pastor executado!\n");
}

int converterColuna(char coluna) {
    return coluna - 'a';
}

int main() {
    char matriz[8][8][3];
    char coluna[8][3];
    int jogadorAtual;
    char origemC, destinoC;
    int origemL, destinoL;
    int opcao;

    // Inicialização do tabuleiro
    inicializarTabuleiro(matriz, coluna);

    // Impressão do MENU
    printf("Escolha uma opção:\n");
    printf("1. Jogar normalmente\n");
    printf("2. Executar Cheque Pastor\n");
    scanf("%d", &opcao);

    if (opcao == 2) {
        chequePastor(matriz, coluna);
    } else {
        // Movimentação das Peças
        for (int turno = 0; turno < 7; turno++) {
            jogadorAtual = (turno % 2) + 1;
            printf("\nÉ a vez do jogador %d\n", jogadorAtual);
            printf("As colunas serão denominadas por letras (a, b, c, ... h)\n");
            printf("\n");
            printf("Digite a Origem de sua Peça (linha coluna ex: 1 c): ");
            scanf("%d %c", &origemL, &origemC);
            printf("Digite a linha e coluna do Destino de sua Peça ex: 3 d: ");
            scanf("%d %c", &destinoL, &destinoC);

            // Ajustes das coordenadas
            origemL = 8 - origemL;
            origemC = converterColuna(origemC);
            destinoL = 8 - destinoL;
            destinoC = converterColuna(destinoC);

            // Movimentação da Peça
            moverPeca(matriz, origemL, origemC, destinoL, destinoC);

            // Imprimir o estado Atual
            imprimirTabuleiro(matriz, coluna);
        }

        printf("\nXeque-Mate!\n");
    }

    return 0;
}
