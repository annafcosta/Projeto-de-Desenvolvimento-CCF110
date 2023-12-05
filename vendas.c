#include "produtos.h"
#include "vendas.h"

// CADASTRO DE VENDAS:
// Verificando a validade do código do produto
int verificar_codigo_produto(int codigo, Cadastro_produto *produtos, int num_produtos)
{
    if (FLAG_TESTE == 1)
    {
        if (codigo == 1001)
        {
            return 0; // Retorna o índice 0 se o código for válido
        } else
        {
            return -1; // Retorna -1 para código inválido
        }
    } else
    {
        for (int i = 0; i < num_produtos; i++)
        {
            if (produtos[i].codigo == codigo)
            {
                return i;
            }
        }
        return -1;
    }
}


void atualizar_quantidade_produto(Cadastro_produto *produtos, int indice, int quantidade)
{
    if (FLAG_TESTE == 1)
    {

        produtos[indice].quantidade -= quantidade;

        printf("\033[0;33mQuantidade atualizada!\n");
        printf("\033[0m");
    } else
    {
        produtos[indice].quantidade -= quantidade;
    }
}

// Função para processar as vendas:
void processar_venda(Cadastro_produto *produtos, Cadastro_venda *vendas,
                     int produto_encontrado, int quantidade_vendida, int *num_vendas)
{
    if (FLAG_TESTE == 1)
    {

        produtos[produto_encontrado].quantidade -= quantidade_vendida;

        vendas[*num_vendas].codigo_produto_vendido = produtos[produto_encontrado].codigo;
        vendas[*num_vendas].quantidade_vendida = quantidade_vendida;
        vendas[*num_vendas].valor_total = produtos[produto_encontrado].valor * quantidade_vendida;

        printf("\033[0;33mVenda registrada com sucesso!\n");
        printf("\033[34mValor da venda: R$ %.2f\n", vendas[*num_vendas].valor_total);
    } 
    
    else
    { // Caso FLAG_TESTE == 0
        atualizar_quantidade_produto(produtos, produto_encontrado, quantidade_vendida);

        vendas[*num_vendas].codigo_produto_vendido = produtos[produto_encontrado].codigo;
        vendas[*num_vendas].quantidade_vendida = quantidade_vendida;
        vendas[*num_vendas].valor_total = produtos[produto_encontrado].valor * quantidade_vendida;

        printf("\033[0;33mVenda registrada com sucesso!\n");
        printf("\033[34mValor da venda: R$ %.2f\n", vendas[*num_vendas].valor_total);
    }

    (*num_vendas)++;
}

// Função para cadastrar uma venda
void cadastrar_venda(Cadastro_produto *produtos, int num_produtos,
                     Cadastro_venda *vendas, int maxvendas, int *num_vendas)
{
    int continuar = 1;

    while (continuar)
    {
        int codigo_venda;
        int quantidade_vendida;

        printf("\nInforme o código do produto vendido (ou 0 para encerrar): ");
        scanf("%d", &codigo_venda);

        if (codigo_venda == 0)
        {
            continuar = 0;
        }
        else
        {
            int produto_encontrado = verificar_codigo_produto(codigo_venda, produtos, num_produtos);

            if (produto_encontrado != -1)
            {
                printf("Informe a quantidade vendida: ");
                scanf("%d", &quantidade_vendida);

                // Armazena a quantidade em estoque antes da venda
                int quantidade_antes = produtos[produto_encontrado].quantidade;

                if (FLAG_TESTE == 1)
                {
                    printf("\033[0;33m\nProcessando venda...\n");
                    printf("\033[0m");

                    produtos[produto_encontrado].quantidade -= quantidade_vendida;

                    vendas[*num_vendas].codigo_produto_vendido = produtos[produto_encontrado].codigo;
                    vendas[*num_vendas].quantidade_vendida = quantidade_vendida;
                    vendas[*num_vendas].valor_total = produtos[produto_encontrado].valor * quantidade_vendida;

                    printf("\033[0;33m\nVenda registrada com sucesso!\n");
                    printf("\033[34mValor da venda: R$ %.2f\n", vendas[*num_vendas].valor_total);

                    printf("\033[34m\nQuantidade em estoque antes da venda: %d\n", quantidade_antes);
                    printf("\033[34mQuantidade em estoque após a venda: %d\n", produtos[produto_encontrado].quantidade);
                }
                else
                {
                    if (quantidade_vendida <= produtos[produto_encontrado].quantidade)
                    {
                        // Verificar se o número de vendas não ultrapassa o limite máximo
                        if (*num_vendas < MAX_VENDAS)
                        {
                            processar_venda(produtos, vendas, produto_encontrado, quantidade_vendida, num_vendas);
                        }
                        else
                        {
                            printf("\033[31m\nLimite máximo de vendas atingido.\n");
                            printf("\033[0m");
                        }
                    }
                    else
                    {
                        printf("\033[31m\nQuantidade insuficiente em estoque para realizar a venda.\n");
                        printf("\033[0m");
                    }

                    // Exibe a quantidade em estoque após a venda
                    printf("\033[34m\nQuantidade em estoque após a venda: %d\n", produtos[produto_encontrado].quantidade);
                }
            }
            else
            {
                printf("\033[31mProduto não encontrado. Verifique o código do produto.\n");
                printf("\033[0m");
            }
        }
    }
}



// VISUALIZAR VENDAS:
void visualizar_vendas(Cadastro_venda *vendas, int num_vendas)
{
    printf("\n~~~~~~~~~~~~~~~ VENDAS REALIZADAS ~~~~~~~~~~~~~~~\n");

    if (FLAG_TESTE == 1)
    {
        for (int i = 0; i < num_vendas; ++i)
        {
            printf("\n\033[1;32mVENDA %d \033[0m\n", i + 1);
            printf("\033[34mCÓDIGO DO PRODUTO VENDIDO \033[0m| %d\n", vendas[i].codigo_produto_vendido);
            printf("\033[38;5;208mQUANTIDADE VENDIDA \033[0m| %d\n", vendas[i].quantidade_vendida);
            printf("\033[34mVALOR TOTAL \033[0m| R$ %.2f\n", vendas[i].valor_total);
            printf("\n");
        }
    } else
    {

        for (int i = 0; i < num_vendas; ++i)
        {
            printf("\n\033[1;32mVENDA %d \033[0m\n", i + 1);
            printf("\033[34mCÓDIGO DO PRODUTO VENDIDO \033[0m| %d\n", vendas[i].codigo_produto_vendido);
            printf("\033[38;5;208mQUANTIDADE VENDIDA \033[0m| %d\n", vendas[i].quantidade_vendida);
            printf("\033[34mVALOR TOTAL \033[0m| R$ %.2f\n", vendas[i].valor_total);
            printf("\n");
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}