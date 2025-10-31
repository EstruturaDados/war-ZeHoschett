#include <stdio.h>
#include <string.h>

/*
    Programa: Cadastro de Territórios
    Objetivo: Demonstrar o uso de structs em C para armazenar e exibir dados de múltiplos territórios.
    Autor: José Hoschett
    Data: Outubro de 2025
*/

// Definição da estrutura que representa um território
struct Territorio {
    char nome[30];       // Nome do território
    char cor[10];        // Cor do exército associado
    int tropas;          // Quantidade de tropas
};

int main() {
    struct Territorio territorios[5]; // Vetor para armazenar 5 territórios
    int i;

    printf("=== SISTEMA DE CADASTRO DE TERRITÓRIOS ===\n\n");

    // Entrada dos dados dos 5 territórios
    for (i = 0; i < 5; i++) {
        printf("Cadastro do Território %d\n", i + 1);

        printf("Nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // lê string com espaços

        printf("Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n"); // Espaço entre cadastros
    }

    // Exibição dos dados cadastrados
    printf("\n=== DADOS DOS TERRITÓRIOS CADASTRADOS ===\n\n");

    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
        printf("--------------------------------------\n");
    }

    printf("\nCadastro concluído com sucesso!\n");

    return 0;
}
