#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    Programa: WAR Estruturado – Interatividade e Ataque entre Territórios
    Objetivo: Demonstrar o uso de structs, ponteiros e alocação dinâmica
              simulando ataques entre territórios de um jogo estilo WAR.
    Autor: José Hoschett 
    Data: Outubro de 2025
*/

// Definição da estrutura do território
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército (representa o dono)
    int tropas;      // Número de tropas no território
} Territorio;

// ======== Protótipos das funções ==========
Territorio* cadastrarTerritorios(int qtd);
void exibirTerritorios(Territorio* mapa, int qtd);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa);

// ==========================================

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int qtd, atacanteIdx, defensorIdx;
    Territorio* mapa = NULL;

    printf("=== SISTEMA DE GUERRA - MÓDULO DE ATAQUE ===\n\n");

    // --- Alocação dinâmica dos territórios ---
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &qtd);
    getchar(); // Limpa o buffer do teclado

    mapa = cadastrarTerritorios(qtd);

    printf("\n=== TERRITÓRIOS CADASTRADOS ===\n");
    exibirTerritorios(mapa, qtd);

    // --- Escolha de ataque ---
    printf("\n--- Fase de Ataque ---\n");
    printf("Escolha o território ATACANTE (índice 0 a %d): ", qtd - 1);
    scanf("%d", &atacanteIdx);
    printf("Escolha o território DEFENSOR (índice 0 a %d): ", qtd - 1);
    scanf("%d", &defensorIdx);

    // Validação básica
    if (atacanteIdx < 0 || atacanteIdx >= qtd || defensorIdx < 0 || defensorIdx >= qtd) {
        printf("Índices inválidos. Encerrando programa.\n");
        liberarMemoria(mapa);
        return 1;
    }

    if (strcmp(mapa[atacanteIdx].cor, mapa[defensorIdx].cor) == 0) {
        printf("Erro: você não pode atacar um território da mesma cor!\n");
        liberarMemoria(mapa);
        return 1;
    }

    // --- Executa o ataque ---
    atacar(&mapa[atacanteIdx], &mapa[defensorIdx]);

    // --- Exibe resultados atualizados ---
    printf("\n=== RESULTADO PÓS-ATAQUE ===\n");
    exibirTerritorios(mapa, qtd);

    // --- Libera a memória ---
    liberarMemoria(mapa);

    printf("\nMemória liberada. Programa encerrado.\n");
    return 0;
}

// ==========================================
// Função: cadastrarTerritorios
// Descrição: Aloca dinamicamente um vetor de Território e preenche os dados.
Territorio* cadastrarTerritorios(int qtd) {
    Territorio* mapa = (Territorio*) calloc(qtd, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i);
        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);
        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);
        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    return mapa;
}

// ==========================================
// Função: exibirTerritorios
// Descrição: Exibe todos os territórios cadastrados.
void exibirTerritorios(Territorio* mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n[%d] Nome: %s\n", i, mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("---------------------------\n");
    }
}

// ==========================================
// Função: atacar
// Descrição: Simula o ataque entre dois territórios usando rolagem de dados.
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n=== ATAQUE INICIADO ===\n");
    printf("%s (%s) ATACA %s (%s)\n", atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    int dadoAtacante = (
