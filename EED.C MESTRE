#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
    PROJETO FINAL: WAR ESTRUTURADO - MISSÕES ESTRATÉGICAS
    Autor: José Hoschett 
    Data: Outubro de 2025

    Objetivo:
    - Demonstrar o uso de structs, ponteiros, funções modulares e alocação dinâmica.
    - Adicionar missões estratégicas para cada jogador.
    - Integrar o sistema de ataque com verificação de vitória por missão.
*/

// ================= ESTRUTURAS =================
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

typedef struct {
    char nome[30];
    char *missao; // ponteiro para string alocada dinamicamente
} Jogador;

// ================= PROTÓTIPOS =================
Territorio* cadastrarTerritorios(int qtd);
void exibirTerritorios(Territorio* mapa, int qtd);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa, Jogador* jogadores, int qtdJogadores);

void atribuirMissao(char* destino, char* missoes[], int totalMissoes);
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* corJogador);
void exibirMissao(char* missao, char* nomeJogador);

// ================= MAIN =================
int main() {
    srand(time(NULL));

    int qtdTerritorios, qtdJogadores, atacanteIdx, defensorIdx;
    Territorio* mapa;
    Jogador* jogadores;

    // --- Cadastro inicial ---
    printf("=== SISTEMA WAR - MISSÕES ESTRATÉGICAS ===\n\n");
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &qtdTerritorios);
    getchar();

    mapa = cadastrarTerritorios(qtdTerritorios);

    printf("Quantos jogadores participarão? ");
    scanf("%d", &qtdJogadores);
    getchar();

    jogadores = (Jogador*) calloc(qtdJogadores, sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro ao alocar memória para jogadores!\n");
        free(mapa);
        exit(1);
    }

    // --- Vetor de missões ---
    char* missoes[] = {
        "Conquistar 3 territórios seguidos.",
        "Eliminar todas as tropas da cor vermelha.",
        "Controlar pelo menos 2 territórios azuis.",
        "Possuir mais de 20 tropas no total.",
        "Conquistar qualquer território amarelo."
    };
    int totalMissoes = 5;

    // --- Cadastro dos jogadores e atribuição de missão ---
    for (int i = 0; i < qtdJogadores; i++) {
        printf("\n--- Cadastro do Jogador %d ---\n", i + 1);
        printf("Nome do jogador: ");
        scanf(" %[^\n]", jogadores[i].nome);

        // Aloca espaço para a missão e atribui
        jogadores[i].missao = (char*) malloc(100 * sizeof(char));
        if (jogadores[i].missao == NULL) {
            printf("Erro ao alocar memória para missão!\n");
            liberarMemoria(mapa, jogadores, qtdJogadores);
            exit(1);
        }

        atribuirMissao(jogadores[i].missao, missoes, totalMissoes);
        exibirMissao(jogadores[i].missao, jogadores[i].nome);
    }

    // --- Exibe o mapa inicial ---
    printf("\n=== MAPA INICIAL ===\n");
    exibirTerritorios(mapa, qtdTerritorios);

    // --- Loop principal de ataque ---
    int jogoAtivo = 1;
    while (jogoAtivo) {
        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o território ATACANTE (índice 0 a %d): ", qtdTerritorios - 1);
        scanf("%d", &atacanteIdx);
        printf("Escolha o território DEFENSOR (índice 0 a %d): ", qtdTerritorios - 1);
        scanf("%d", &defensorIdx);

        if (atacanteIdx < 0 || atacanteIdx >= qtdTerritorios ||
            defensorIdx < 0 || defensorIdx >= qtdTerritorios) {
            printf("Índices inválidos! Tente novamente.\n");
            continue;
        }

        if (strcmp(mapa[atacanteIdx].cor, mapa[defensorIdx].cor) == 0) {
            printf("Não é possível atacar um território da mesma cor!\n");
            continue;
        }

        atacar(&mapa[atacanteIdx], &mapa[defensorIdx]);

        // --- Exibe o mapa após o ataque ---
        print
