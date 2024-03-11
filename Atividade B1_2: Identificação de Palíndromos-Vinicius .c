/******************************************************************************
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//verificação se é palindromo
int palindromo(char *palavra) {
    int inicio = 0;
    int fim = strlen(palavra) - 1;

    while (inicio < fim) {
        if (palavra[inicio] != palavra[fim]) {
            return 0; // caracterização de não ser palindromo
        }
        inicio++;
        fim--;
    }
    return 1; // É considerado Palindromo
}

//Verificação  principal de comparar a entrada com a inversão 
int main() {
    char frase[256];
    char palavra[256];
    int i = 0, j = 0;

    printf("Digite a palavra: ");
    fgets(frase, 256, stdin);

    frase[strcspn(frase, "\n")] = 0;

    // converter os caracteres das letras para minusculo para fazer a comparação 
    for (i = 0; frase[i]; i++) {
        frase[i] = tolower(frase[i]);
    }

    // Copiar a entrada 'palavra'  para comparar
    strcpy(palavra, frase);

    // verificar se a palavra não é uma preposição ou artigo
    if (strcmp(palavra, "a") && strcmp(palavra, "e") && strcmp(palavra, "o") &&
        strcmp(palavra, "as") && strcmp(palavra, "os") && strcmp(palavra, "um") &&
        strcmp(palavra, "uns") && strcmp(palavra, "uma") && strcmp(palavra, "umas") &&
        strcmp(palavra, "do") && strcmp(palavra, "da") && strcmp(palavra, "dos") &&
        strcmp(palavra, "das") && strcmp(palavra, "de") && strcmp(palavra, "com") &&
        strcmp(palavra, "para") && strcmp(palavra, "por") && strcmp(palavra, "em") &&
        strcmp(palavra, "no") && strcmp(palavra, "na") && strcmp(palavra, "nos") &&
        strcmp(palavra, "nas")) {
        // verificar se a palavra é um palindromo
        if (palindromo(palavra)) {
            printf("Palíndromo encontrado: %s\n", palavra);
        } else {
            printf("Não é um palíndromo.\n");
        }
    } else {
        printf("A palavra é um artigo ou preposição.\n");
    }

    return 0;
}
