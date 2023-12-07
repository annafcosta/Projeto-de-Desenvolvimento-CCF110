#include "vendas.h"
#include "produtos.h"
#include "arquivos.h"

int main()
{
    int opcao;

    Cadastro_produto produtos[MAX_PRODUTO];
    Cadastro_venda vendas[MAX_VENDAS];

    int num_vendas = 0;
    int numero_de_produtos;

    do
    {
        printf("Digite a quantidade de produtos que serão cadastrados no sistema: ");
        scanf("%d", &numero_de_produtos);

        if (numero_de_produtos < 0)
        {
            printf("\033[0;31m\nA quantidade não pode ser negativa. Por favor, insira uma quantidade válida.\033[0m\n");
        }

    } while (numero_de_produtos < 0);

    do
    {
        exibir_menu();
        printf("\n\n => Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // Cadastrar produtos:
                cadastrar_produtos(produtos, MAX_PRODUTO, &numero_de_produtos);
                break;

            case 2: // Salvar vendas em um arquivo:
                ler_arquivo_produtos(produtos);
                break;

            case 3: // Visualizar produtos:
                visualizar_produtos(produtos, numero_de_produtos);
                break;

            case 4: // Cadastrar vendas:
                cadastrar_venda(produtos, MAX_PRODUTO, vendas, MAX_VENDAS, &num_vendas);
                break;

            case 5: // Visualizar vendas:
                visualizar_vendas(produtos, numero_de_produtos, vendas, num_vendas);
                break;

            case 6: // Salvar vendas em um arquivo:
                salvar_vendas_em_arquivo(vendas, num_vendas, produtos, numero_de_produtos);
                break;

            case 0:
                printf("\nSaída realizada com sucesso!\n");
                break;

            default: // Quebra para entradas inválidas
                printf(" \033[31mEscolha uma opção válida!! ");
                printf("\033[0m");
                break;
        }
    } while (opcao != 0);


    return 0;
}