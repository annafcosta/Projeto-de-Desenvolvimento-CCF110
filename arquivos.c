#include <stdio.h>
#include <string.h>

#include "produtos.h"
#include "vendas.h"

void ler_arquivo_produtos(Cadastro_produto *produtos, int *numero_de_produtos)
{
    FILE *arquivo_produto = fopen("estoque.txt", "r");

    if (arquivo_produto == NULL)
    {
        printf("Erro ao abrir o arquivo 'estoque'!\n");
        return;
    }

    if (!fscanf(arquivo_produto, "%d", numero_de_produtos))
    {
        printf("Deu erro!");
    }

    for (int i = 0; i < *numero_de_produtos; i++)
    {
        if (!fscanf(arquivo_produto, "%s %f %d %d", produtos[i].nome, &produtos[i].valor, &produtos[i].codigo,
                    &produtos[i].quantidade))
        {
            printf("Erro ao imprimir as informações do arquivo.");
        }
    }

    fclose(arquivo_produto);
}

// SALVAR AS VENDAS EM UM ARQUIVO TXT:
void salvar_vendas_em_arquivo(Cadastro_venda *vendas, int num_vendas, Cadastro_produto *produtos, int num_produtos)
{
    FILE *arquivo = fopen("vendas.txt", "a");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo 'vendas' para escrita!\n");
        return;
    }

    int dia_da_venda, mes_da_venda;

    do
    {
        printf("\nInforme o dia da venda: ");
        scanf("%d", &dia_da_venda);

        if (dia_da_venda < 0)
        {
            printf("Por favor, informe um valor não negativo para o dia.\n");
        } else if (dia_da_venda > 31)
        {
            printf("\033[0;31m\nOpção inválida. Digite um dia válido, por favor.\033[0m\n");
        }
    } while (dia_da_venda < 0 || dia_da_venda > 31);

    do
    {
        printf("\nInforme o mês da venda: ");
        scanf("%d", &mes_da_venda);

        if (mes_da_venda < 0)
        {
            printf("Por favor, informe um valor não negativo para o mês.\n");
        } else if (mes_da_venda > 12)
        {
            printf("\033[0;31m\nOpção inválida. Digite um mês válido, por favor.\033[0m\n");
        }
    } while (mes_da_venda < 0 || mes_da_venda > 12);

    for (int i = 0; i < num_vendas; ++i)
    {

        int quantidade_restante = calcular_quantidade_restante(produtos, num_produtos, vendas[i]);

        fprintf(arquivo, "\n=> VENDA DO DIA: %d/%d\n", dia_da_venda, mes_da_venda);
        fprintf(arquivo, "\n- VENDA - %d\n", i + 1);
        fprintf(arquivo, "CÓDIGO DO PRODUTO VENDIDO | %d\n", vendas[i].codigo_produto_vendido);
        fprintf(arquivo, "QUANTIDADE VENDIDA | %d\n", vendas[i].quantidade_vendida);
        fprintf(arquivo, "VALOR TOTAL | R$ %.2f\n", vendas[i].valor_total);
        fprintf(arquivo, "QUANTIDADE EM ESTOQUE APÓS VENDA | %d\n", quantidade_restante);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);  // Fecha o arquivo

    printf("\nInformações salvas em 'vendas.txt'!\n");
}