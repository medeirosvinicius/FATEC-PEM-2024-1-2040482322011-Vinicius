
#include <stdio.h>
#define TAMANHO_TABULEIRO 8

int main(void) {
    char peca[] = "TCBDRBP"; // representação das peças pelas letras
    char cor[] = "PPPPPPPP"; // representação com as cores pretas
    
    printf("\n");
    
    for(int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        int n = 0;   // inserção de numeração nas letras
        
        for(int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("|"); // Inicia cada célula do tabuleiro com um |
            
            // Impressão de peças  e também de espaços vazios
            if ((linha % 7 == 0) && (coluna % 7 == 0)) {
                printf("B%c%d", peca[coluna], ++n);    // linha 1 das peças brancas
            } 
            else if ((linha % 7 == 0) && (coluna % 7 == 1 || coluna % 7 == 6)) {
                printf("B%c%d", peca[coluna], ++n);  //segunda e penultima linha de peças brancas
            }
            else if ((linha % 7 == 0) && (coluna % 7 >= 2 && coluna % 7 <= 5)) {
                printf("B%c%d", peca[coluna], ++n);//demais  linhas  peças brancas
            }
            else if ((linha % 7 == 1) && (coluna % 7 >= 0 && coluna % 7 <= 7)) {
                printf("PP%d", coluna + 1); // enumeração da primeira linha de peões pretos
            } 
            else if ((linha % 7 == 6) && (coluna % 7 >= 0 && coluna % 7 <= 7)) {
                printf("pp%d", coluna + 1); // impressão das ultimas linhas de peoes pretos
            }
            else if ((linha % 7 > 1 && linha % 7 < 6) && (coluna % 7 >= 0 && coluna % 7 <= 7)) {
                printf("X"); // impressão dos espaços vazios da linha do meio  com o X
            }
            
            if (coluna == TAMANHO_TABULEIRO - 1) {
                printf("|"); 
            }
        }
        printf("\n");
    }
    return 0;
}
