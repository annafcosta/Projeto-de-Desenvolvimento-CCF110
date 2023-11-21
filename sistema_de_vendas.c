#include "cadastros.h"

//Definir a quantidade máxima de produtos que serão cadastrados:
int max_produto = 1;
int max_vendas = 1;

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

        // CADASTRO DOS PRODUTOS
        if (opcao == 1)
        {
            cadastrar_produtos(produtos, max_produto, &num_produtos);
        }

            // VISUALIZAÇÃO DE PRODUTOS
        else if (opcao == 2)
        {
            visualizar_produtos(produtos, num_produtos);
        }

            // CADASTRO DE VENDAS:
            //else if (opcao == 3) {cadastrar_venda(&produtos, &vendas, num_produtos, max_produto, num_vendas);}

            // VISUALIZAR VENDAS
            // else if (opcao == 4){ visualizar_vendas(&vendas, num_vendas);}

        else if (opcao == 0)
        {
            printf("Saída realizada com sucesso!");
            break;
        } else
        {
            printf(" \033[31mEscolha uma opção válida!! ");
            printf("\033[0m");
        }

    } while (opcao != 0);

    return 0;
}