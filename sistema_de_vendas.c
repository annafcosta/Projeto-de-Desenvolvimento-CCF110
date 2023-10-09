#include <stdio.h>

int main()
{
    int opcao;

    // Declarando as variáveis para os produtos fora do loop:
    int max_produto;
    char nome_produto[max_produto][50];
    float valor_produto[max_produto];
    int quantidade_produto[max_produto];
    int num_produtos = 0;

    do
    {
        printf("\033[35m");  // Text color (Rosa)
        printf("\n~~~~~~~~~~~~~~~~~~~~| DELÍCIAS DA HELLEN |~~~~~~~~~~~~~~~~~~~~\n");
        printf("\033[0m");   // Resetar a cor para o padrão

        printf("\n\t• Cadastrar novo produto no estoque \033[34m| Digite 1: "); // Código de escape ANSI para cor azul
        printf("\033[0m");

        printf("\n\t• Visualizar produtos no estoque \033[34m| Digite 2: ");
        printf("\033[0m");

        printf("\n\t• Cadastrar nova venda \033[34m| Digite 3: ");
        printf("\033[0m");

        printf("\n\t• Listar vendas \033[34m| Digite 5: ");
        printf("\033[0m");

        printf("\n\t• Sair \033[34m| Digite 0: ");
        printf("\033[0m");

        printf("\n\n Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // CADASTRO DOS PRODUTOS

                do
                {
                    printf("Insira a quantidade de produtos produzidos esse mês: ");
                    scanf("%d", &max_produto);

                    // Verificação para números negativos
                    if (max_produto < 0)
                    {
                        printf("Por favor, insira um número não negativo.\n");
                    }
                } while (max_produto < 0);

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

                    printf("\033[0;33mProduto adicionado com sucesso!\n");
                    printf("\033[0m");
                }

                break;

            case 2: // Adicionar a lógica, futuramente:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                break;

            default:
                printf(" \033[31mEscolha uma opção válida!! ");
                printf("\033[0m");
        }

    } while (opcao != 0);

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
