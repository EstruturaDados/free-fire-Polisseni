#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    char tipo[30];
    int prioridade;
} Item;

Item mochila[MAX];
int total = 0;

// ================= FUNÇÕES =================

void adicionarItem() {
    if (total >= MAX) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nNome do item: ");
    scanf(" %[^\n]", mochila[total].nome);

    printf("Tipo do item: ");
    scanf(" %[^\n]", mochila[total].tipo);

    printf("Prioridade (1 a 10): ");
    scanf("%d", &mochila[total].prioridade);

    total++;
    printf("\nItem adicionado com sucesso!\n");
}

void listarItens() {
    if (total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    for (int i = 0; i < total; i++) {
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Prioridade: %d\n", mochila[i].prioridade);
    }
}

void removerItem() {
    if (total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    int pos;
    listarItens();

    printf("\nInforme o número do item para remover: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > total) {
        printf("\nPosição inválida!\n");
        return;
    }

    for (int i = pos - 1; i < total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    total--;
    printf("\nItem removido com sucesso!\n");
}

// ================ ORDENAÇÃO =================

void ordenarPorNome() {
    Item aux;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(mochila[i].nome, mochila[j].nome) > 0) {
                aux = mochila[i];
                mochila[i] = mochila[j];
                mochila[j] = aux;
            }
        }
    }
}

void ordenarPorTipo() {
    Item aux;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(mochila[i].tipo, mochila[j].tipo) > 0) {
                aux = mochila[i];
                mochila[i] = mochila[j];
                mochila[j] = aux;
            }
        }
    }
}

void ordenarPorPrioridade() {
    Item aux;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (mochila[i].prioridade < mochila[j].prioridade) {
                aux = mochila[i];
                mochila[i] = mochila[j];
                mochila[j] = aux;
            }
        }
    }
}

void ordenarItens() {
    int op;

    printf("\nOrdenar por:\n");
    printf("1 - Nome\n");
    printf("2 - Tipo\n");
    printf("3 - Prioridade\n");
    printf("Escolha: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            ordenarPorNome();
            printf("\nItens ordenados por NOME.\n");
            break;

        case 2:
            ordenarPorTipo();
            printf("\nItens ordenados por TIPO.\n");
            break;

        case 3:
            ordenarPorPrioridade();
            printf("\nItens ordenados por PRIORIDADE.\n");
            break;

        default:
            printf("\nOpção inválida!\n");
    }
}

// ================= BUSCA BINÁRIA =================

int buscaBinaria(char nome[]) {
    int inicio = 0;
    int fim = total - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        int r = strcmp(nome, mochila[meio].nome);

        if (r == 0)
            return meio;
        else if (r < 0)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }

    return -1;
}

void buscarPorNome() {
    if (total == 0) {
        printf("\nMochila vazia!\n");
        return;
    }

    ordenarPorNome(); // Necessário para busca binária

    char nome[50];

    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", nome);

    int pos = buscaBinaria(nome);

    if (pos != -1) {
        printf("\nItem encontrado!\n");
        printf("Nome: %s\n", mochila[pos].nome);
        printf("Tipo: %s\n", mochila[pos].tipo);
        printf("Prioridade: %d\n", mochila[pos].prioridade);
    } else {
        printf("\nItem não encontrado.\n");
    }
}

// =================== MAIN ===================

int main() {
    int opcao;

    do {
        printf("\n====== MENU DA MOCHILA ======\n");
        printf("1. Adicionar um item\n");
        printf("2. Remover um item\n");
        printf("3. Listar todos os itens\n");
        printf("4. Ordenar os itens\n");
        printf("5. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 4:
                ordenarItens();
                break;

            case 5:
                buscarPorNome();
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}


    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    


// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
