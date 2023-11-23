#include "vendas.h"

//Definir a quantidade máxima de produtos que serão cadastrados:
int max_produto = 1;

int main()
{
    int opcao;

    Cadastro_produto produtos[max_produto];
    Cadastro_venda vendas[max_vendas];

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
                cadastrar_produtos(produtos, max_produto, &num_produtos);
                break;

            case 2: // Visualizar produtos:
                visualizar_produtos(produtos, num_produtos);
                break;

            case 3: // Cadastrar vendas:
                cadastrar_venda(produtos, max_produto, vendas, max_vendas, &num_vendas);
                break;

            case 4: // Visualizar vendas:
                visualizar_vendas(vendas, num_vendas);
                break;

            case 0:
                printf("\nSaída realizada com sucesso!");
                break;

            default:
                printf(" \033[31mEscolha uma opção válida!! ");
                printf("\033[0m");
        }
    } while (opcao != 0);


    return 0;
}