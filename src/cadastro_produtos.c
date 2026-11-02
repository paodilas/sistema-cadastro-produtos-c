#include <stdio.h>
#include <string.h>

#define MAX 100

// Define a estrutura do produto
typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    int lote;
    int data; // Representa a validade
} Produto;

int main() {
    Produto produtos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- SISTEMA DE CADASTRO DE PRODUTOS ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Remover produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total < MAX) {
                printf("\nCodigo do produto: ");
                scanf("%d", &produtos[total].codigo);
                
                printf("Nome do produto: ");
                scanf(" %[^\n]s", produtos[total].nome); // Leitura de string com espaços

                printf("Lote do produto: ");
                scanf("%d", &produtos[total].lote);

                printf("Validade do produto (ex: AAAAMMDD): ");
                scanf("%d", &produtos[total].data);
                
                printf("Quantidade em estoque: ");
                scanf("%d", &produtos[total].quantidade);

                printf("Preco (R$): ");
                scanf("%f", &produtos[total].preco);
                
                total++;
                printf("\nProduto cadastrado com sucesso!\n");
            } else {
                printf("\nLimite de produtos atingido!\n");
            }
        } else if (opcao == 2) {
            if (total == 0) {
                printf("\nNenhum produto cadastrado.\n");
            } else {
                printf("\n--- LISTA DE PRODUTOS ---\n");
                for (int i = 0; i < total; i++) {
                    printf("Codigo: %d\n", produtos[i].codigo);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Lote: %d\n", produtos[i].lote);
                    printf("Validade: %d\n", produtos[i].data);
                    printf("Preco: R$ %.2f\n", produtos[i].preco);
                    printf("Quantidade: %d\n", produtos[i].quantidade);
                    printf("--------------------------\n");
                }
            }
        } else if (opcao == 3) {
            int codigo;
            int encontrado = 0;

            printf("\nDigite o codigo do produto que deseja remover: ");
            scanf("%d", &codigo);

            for (int i = 0; i < total; i++) {
                if (produtos[i].codigo == codigo) {
                    encontrado = 1;

                    for (int j = i; j < total - 1; j++) {
                        produtos[j] = produtos[j + 1];
                    }

                    total--;

                    printf("\nProduto removido com sucesso!\n");
                    break;
                }
            }

            if (!encontrado) {
                printf("\nProduto nao encontrado.\n");
            }
        }
    } while (opcao != 0);

    printf("\nSistema encerrado.\n");
    return 0;
}