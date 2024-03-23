#include <stdio.h>

float calcularSomaCentrais(float notas[], int tamanho, float *somaCentrais) {
    float maxNota = notas[0], minNota = notas[0], soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
        if (notas[i] > maxNota) maxNota = notas[i];
        if (notas[i] < minNota) minNota = notas[i];
    }
    soma -= (maxNota + minNota); // Remove a maior e a menor nota da soma
    *somaCentrais = soma; // Armazena a soma dos valores centrais
    return soma / (tamanho - 2); // Retorna a média das notas centrais
}

int main() {
    float notasGerenciamentoProjetos[] = {5.0, 3.0, 8.0, 9.0, 7.0};
    float notasLinguagemInglesa[] = {7.0, 5.0, 5.0, 8.0};
    float notasMetodologiaAgil[] = {3.0, 4.0, 7.0, 9.0, 8.0, 10.0};
    float notasLinguagemJavaScript[] = {8.0, 4.0, 5.0, 10.0, 7.0};

    float somaCentrais;
    float media;

    media = calcularSomaCentrais(notasGerenciamentoProjetos, 5, &somaCentrais);
    printf("Gerenciamento de Projetos - Soma dos valores centrais: %.2f, Média: %.2f\n", somaCentrais, media);

    media = calcularSomaCentrais(notasLinguagemInglesa, 4, &somaCentrais);
    printf("Linguagem Inglesa - Soma dos valores centrais: %.2f, Média: %.2f\n", somaCentrais, media);

    media = calcularSomaCentrais(notasMetodologiaAgil, 6, &somaCentrais);
    printf("Metodologia Ágil - Soma dos valores centrais: %.2f, Média: %.2f\n", somaCentrais, media);

    media = calcularSomaCentrais(notasLinguagemJavaScript, 5, &somaCentrais);
    printf("Linguagem JavaScript - Soma dos valores centrais: %.2f, Média: %.2f\n", somaCentrais, media);

    return 0;
}