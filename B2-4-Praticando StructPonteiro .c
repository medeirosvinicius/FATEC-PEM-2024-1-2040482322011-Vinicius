#include <stdio.h>
#include <string.h>

// Introdução das variáveis relacionadas a questão do produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    double precoUnitario;
    int quantidadeEstoque;
} Produto;

// Processo de Inserir do produto
void incluirProduto(Produto *produtos, int *numProdutos) {
    if (*numProdutos < 50) {
        printf("Inserir ID do produto: ");
        scanf("%d", &produtos[*numProdutos].id);
        while (getchar() != '\n'); 

        printf("Inserir nome do produto: ");
        scanf(" %[^\n]s", produtos[*numProdutos].nome);
        while (getchar() != '\n'); 

        printf("Inserir descrição do produto: ");
        scanf(" %[^\n]s", produtos[*numProdutos].descricao);
        while (getchar() != '\n'); 

        printf("Inserir preço unitário do produto: ");
        scanf("%lf", &produtos[*numProdutos].precoUnitario);
        while (getchar() != '\n'); 

        printf("Inserir quantidade em estoque do produto: ");
        scanf("%d", &produtos[*numProdutos].quantidadeEstoque);
        while (getchar() != '\n'); 

        printf("Produto inserido com sucesso!\n");
        (*numProdutos)++;
    } else {
        printf("Limite de produtos atingido.\n");
    }
}
// Função para listar produtos
void listarProdutos(Produto *produtos, int numProdutos) {
    if (numProdutos == 0) {
        printf("Não há produtos cadastrados.\n");
        return;
    }
    // Ordenação de dos produtos
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = i + 1; j < numProdutos; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    printf("Lista de produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Preço Unitário: %.2lf\n", produtos[i].precoUnitario);
        printf("Quantidade em estoque: %d\n\n", produtos[i].quantidadeEstoque);
    }
}

//  Simulação da Compra
void simularCompra(Produto *produtos, int numProdutos) {
    int codigoProduto;
    int quantidadeComprada;

    printf("Inserir código do produto: ");
    scanf("%d", &codigoProduto);

    int encontrado = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == codigoProduto) {
            encontrado = 1;
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Preço Unitário: %.2lf\n", produtos[i].precoUnitario);
            printf("Quantidade em estoque: %d\n", produtos[i].quantidadeEstoque);

            printf("Inserir quantidade de produtos a comprar: ");
            scanf("%d", &quantidadeComprada);

            if (quantidadeComprada > produtos[i].quantidadeEstoque) {
                printf("Quantidade insuficiente em estoque.\n");
            } else {
                produtos[i].quantidadeEstoque -= quantidadeComprada;
                printf("Compra realizada com sucesso!\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Produto inexistente.\n");
    }
}

//  Introdução do Menu 
void exibirMenu() {
    printf("===== Menu =====\n");
    printf("1. Incluir produto\n");
    printf("2. Listar produtos\n");
    printf("3. Simular compra\n");
    printf("4. Sair\n");
    printf("Digite a opção desejada: ");
}
int main() {
    Produto produtos[50];
    int numProdutos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &numProdutos);
                break;
            case 2:
                listarProdutos(produtos, numProdutos);
                break;
            case 3:
                simularCompra(produtos, numProdutos);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}