#include <stdio.h>
#include <stdlib.h>

int main()
{
    // CADASTRO DOS PRODUTOS

    int max_produto;

    printf("Insira a quantidade de produtos produzidos esse mês: ");
    scanf("%d", &max_produto);

    // Declarando as variáveis para os produtos:

    char nome_produto[max_produto][50];
    float valor_produto[max_produto];
    int quantidade_produto[max_produto];
    int num_produtos = 0;

//    int opcao;
//
//    printf("\n\n~~~~~~~~~~~~~~~~~~~~-DELICIAS DA HELLEN-~~~~~~~~~~~~~~~~~~~~\n\n");
//    do
//    {
//        printf("\n\t1 - Cadastrar novo produto no estoque");
//        printf("\n\t2 - Visualizar produtos no estoque");
//        printf("\n\t3 - Cadastrar nova venda");
//        printf("\n\t4 - Listar vendas");
//        printf("\n\t0 - Sair");
//        printf("\n\n Digite a opcao desejada:");
//        scanf("%d", &opcao);
//
//        switch(opcao)
//        {
//            case 1: break;
//            case 2: break;
//            case 3: break;
//            case 4: break;
//            case 0: break;
//            default:
//                printf("Escolha uma opcao valida!!! ");
//        }
//    }while(opcao != 0);

    for (int i = 0; i < max_produto; ++i)
    {
        printf("Informe o nome do produto: ");
        scanf("%s", nome_produto[num_produtos]);

        // Verificação para valor do produto não ser negativo;
        do
        {
            printf("Informe o valor do produto: ");
            scanf("%f", &valor_produto[num_produtos]);

            if (valor_produto[num_produtos] < 0)
            {
                printf("O valor do produto não pode ser negativo. Tente novamente.\n");
            }

        } while (valor_produto[num_produtos] < 0);

        // Verificação para quantidade do produto não ser negativa;
        do
        {
            printf("Informe a quantidade em estoque: ");
            scanf("%d", &quantidade_produto[num_produtos]);

            if (quantidade_produto[num_produtos] < 0)
            {
                printf("A quantidade do produto não pode ser negativa. Tente novamente.\n");
            }

        } while (quantidade_produto[num_produtos] < 0);

        num_produtos++;
        printf("Produto adicionado com sucesso!\n");
    }


// REGISTRO DE VENDAS:

//    int max_vendas;
//
//    printf("Insira a quantidade máxima de produtos a serem vendidos nesse mês: ");
//    scanf("%d", &max_vendas);
//
//    // Declarando as variáveis para registrar as vendas:
//
//    int nome_vendidos[max_vendas];
//    int qtd_vendidas[max_vendas];
//    float totalVenda[max_vendas];
//    int num_vendas = 0;

    return 0;
}
