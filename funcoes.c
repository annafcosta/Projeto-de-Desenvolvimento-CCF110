#include "cadastros.h"

// CADASTRO DE PRODUTOS:

void cadastrar_produtos(Cadastro_produto *produtos, int max_produto, int *num_produtos) 
{
    
    for (int i = 0; i < max_produto; i++) {
        printf("\nInforme o nome do produto %d: ", i + 1);
        getchar(); // Consumir a nova linha pendente
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Informe o código do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);

        printf("Informe o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);

        printf("Informe a quantidade em estoque do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }

    *num_produtos = max_produto;

    printf("\033[0;33mProdutos cadastrados com sucesso!\n");
    printf("\033[0m");

}

// VISUALIZAR PRODUTOS

void visualizar_produtos(Cadastro_produto *produtos, int num_produtos) {
    printf("\n~~~~~~~~~~~~~~~ PRODUTOS CADASTRADOS ~~~~~~~~~~~~~~~\n");

    for (int i = 0; i < num_produtos; ++i) {
        printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
        printf("\033[35mNOME       \033[0m| %s\n", produtos[i].nome);
        printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
        printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
        printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
        printf("\n");
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}


// CADASTRO DE VENDAS:

// Verificando a validade do código do produto
int verificar_codigo_produto(int codigo, Cadastro_produto *produtos, int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return i; // Retorna o índice se o código for válido
        }
    }
    return -1; // Retorna -1 se o código não for válido
}


void atualizar_quantidade_produto(Cadastro_produto *produtos, int indice, int quantidade) {
    produtos[indice].quantidade -= quantidade;
}


void processar_venda(Cadastro_produto *produtos, Cadastro_venda *vendas,
                    int produto_encontrado, int quantidade_vendida, int *num_vendas) 
{
    atualizar_quantidade_produto(produtos, produto_encontrado, quantidade_vendida);

    vendas[*num_vendas].codigo_produto_vendido = produtos[produto_encontrado].codigo;
    vendas[*num_vendas].quantidade_vendida = quantidade_vendida;
    vendas[*num_vendas].valor_total = produtos[produto_encontrado].valor * quantidade_vendida;

    printf("\033[0;33mVenda registrada com sucesso!\n");
    printf("\033[34mValor da venda: R$ %.2f\n", vendas[*num_vendas].valor_total);

    (*num_vendas)++;
}


// Função para cadastrar uma venda
void cadastrar_venda(Cadastro_produto *produtos, int num_produtos,
                    Cadastro_venda *vendas, int max_vendas, int *num_vendas) {

    int continuar = 1;

    while (continuar) {
        int codigo_venda;
        int quantidade_vendida;

        printf("\nInforme o código do produto vendido (ou 0 para encerrar): ");
        scanf("%d", &codigo_venda);

        if (codigo_venda == 0) {
            continuar = 0;  
        } else {
            int produto_encontrado = verificar_codigo_produto(codigo_venda, produtos, num_produtos);

            if (produto_encontrado != -1) {
                printf("Informe a quantidade vendida: ");
                scanf("%d", &quantidade_vendida);

                if (quantidade_vendida <= produtos[produto_encontrado].quantidade) {
                    // Verificar se o número de vendas não ultrapassa o limite máximo
                    if (*num_vendas < max_vendas) {
                        processar_venda(produtos, vendas, produto_encontrado, quantidade_vendida, num_vendas);
                    } else {
                        printf("\033[31mLimite máximo de vendas atingido.\n");
                        printf("\033[0m");
                    }
                } else {
                    printf("\033[31mQuantidade insuficiente em estoque para realizar a venda.\n");
                    printf("\033[0m");
                }
            } else {
                printf("\033[31mProduto não encontrado. Verifique o código do produto.\n");
                printf("\033[0m");
            }
        }
    }
}


// VISUALIZAR VENDAS:

void visualizar_vendas(Cadastro_venda *vendas, int num_vendas) {
    printf("\n~~~~~~~~~~~~~~~ VENDAS REALIZADAS ~~~~~~~~~~~~~~~\n");

    for (int i = 0; i < num_vendas; ++i) {
        printf("\n\033[1;32mVENDA %d \033[0m\n", i + 1);
        printf("\033[34mCÓDIGO DO PRODUTO VENDIDO \033[0m| %d\n", vendas[i].codigo_produto_vendido);
        printf("\033[38;5;208mQUANTIDADE VENDIDA \033[0m| %d\n", vendas[i].quantidade_vendida);
        printf("\033[34mVALOR TOTAL \033[0m| R$ %.2f\n", vendas[i].valor_total);
        printf("\n");
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}