#include "vendas.h"
#include "produtos.h"
#include "arquivos.h"

int main()
{
    int opcao;

    Cadastro_produto produtos[MAX_PRODUTO];
    Cadastro_venda vendas[MAX_VENDAS];

    int num_vendas = 0;
    int primeiro_opcao = 0;

    do
    {
        printf("Escolha arquivo ou cadastro manual:");
        printf("\nCadastro manual (1) | Arquivo (2)\n");
        printf("=> Digite a opção desejada: ");
        scanf("%d", &primeiro_opcao);

        if (primeiro_opcao < 0)
        {
            printf("\033[0;31m\nA quantidade não pode ser negativa. Por favor, insira uma quantidade válida.\033[0m\n");
        } else if (primeiro_opcao > 2)
        {
            printf("\033[0;31m\nOpção inválida. Por favor, escolha 1 para cadastro manual ou 2 para arquivo.\033[0m\n");
        }

    } while (primeiro_opcao < 0 || primeiro_opcao > 2);

    int qtd_atual_produtos = 0;
    int qtd_produtos_para_cadastrar = 0;

    if (primeiro_opcao == 1)
    {
        do
        {
            printf("Digite a quantidade de produtos que serão cadastrados no sistema: ");
            scanf("%d", &qtd_produtos_para_cadastrar);

            if (qtd_produtos_para_cadastrar < 0)
            {
                printf("\033[0;31m\nA quantidade não pode ser negativa. Por favor, insira uma quantidade válida.\033[0m\n");
            }

        } while (qtd_produtos_para_cadastrar < 0);

    } else if (primeiro_opcao == 2)
    {
        ler_arquivo_produtos(produtos, &qtd_atual_produtos);
    }

    do
    {
        exibir_menu();
        printf("\n\n => Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // Cadastrar produtos:
                cadastrar_produtos(produtos, &qtd_atual_produtos, qtd_produtos_para_cadastrar);
                break;

            case 3: // Visualizar produtos:
                visualizar_produtos(produtos, qtd_atual_produtos);
                break;

            case 4: // Cadastrar vendas:
                cadastrar_venda(produtos, MAX_PRODUTO, vendas, MAX_VENDAS, &num_vendas);
                break;

            case 5: // Visualizar vendas:
                visualizar_vendas(produtos, qtd_atual_produtos, vendas, num_vendas);
                break;

            case 6: // Salvar vendas em um arquivo:
                salvar_vendas_em_arquivo(vendas, num_vendas, produtos, qtd_atual_produtos);
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