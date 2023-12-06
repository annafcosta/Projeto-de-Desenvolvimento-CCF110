#include "vendas.h"

int main()
{
    int opcao;

    Cadastro_produto produtos[MAX_PRODUTO];
    Cadastro_venda vendas[MAX_VENDAS];

    int num_produtos = 0;
    int num_vendas = 0;

    do
    {
        exibir_menu();
        printf("\n\n => Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // Cadastrar produtos:
                cadastrar_produtos(produtos, MAX_PRODUTO, &num_produtos);
                break;

            case 2: // Visualizar produtos:
                visualizar_produtos(produtos, num_produtos);
                break;

            case 3: // Cadastrar vendas:
                cadastrar_venda(produtos, MAX_PRODUTO, vendas, MAX_VENDAS, &num_vendas);
                break;

            case 4: // Visualizar vendas:
                visualizar_vendas(produtos, num_produtos, vendas, num_vendas);
                break;

            case 5: // Salvar vendas em um arquivo:
                salvar_vendas_em_arquivo(vendas, num_vendas, produtos, num_produtos);
                break;

            case 0:
                printf("\nSaída realizada com sucesso!\n");
                break;

            default: // Quebra para entradas inválidas
                printf(" \033[31mEscolha uma opção válida!! ");
                printf("\033[0m");
        }
    } while (opcao != 0);


    return 0;
}