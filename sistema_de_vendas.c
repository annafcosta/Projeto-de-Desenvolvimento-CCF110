#include <stdio.h>
#include <string.h>

int main()
{
    int opcao;

    // Declarando as variáveis para os produtos fora do loop:
    int max_produto = 1;
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

        printf("\n\t• Listar vendas \033[34m| Digite 4: ");
        printf("\033[0m");

        printf("\n\t• Sair \033[34m| Digite 0: ");
        printf("\033[0m");

        printf("\n\n Digite a opção desejada: ");
        scanf("%d", &opcao);


        // CADASTRO DOS PRODUTOS
        if (opcao == 1)
        {
            // NOME DO PRODUTO:
            for (int i = 0; i < max_produto; i++)
            {
                printf("\nInforme o nome do produto: ");
                getchar(); // Consumir a nova linha pendente
                fgets(nome_produto[num_produtos], sizeof(nome_produto[i]), stdin);
                nome_produto[num_produtos][strcspn(nome_produto[i], "\n")] = '\0';
            }

            // VALOR DO PRODUTO:
            do
            {
                for (int i = 0; i < max_produto; i++)
                {

                    printf("Informe o valor do produto: ");
                    scanf("%f", &valor_produto[i]);

                    if (valor_produto[i] < 0) // Verificação para números negativos;
                    {
                        printf("O valor do produto não pode ser negativo. Tente novamente.\n");
                    }


                }

            } while (valor_produto[num_produtos] < 0);

            do // QUANTIDADE DE PRODUTOS
            {
                for (int i = 0; i < max_produto; i++)
                {
                    printf("Informe a quantidade em estoque: ");
                    scanf("%d", &quantidade_produto[i]);

                    if (quantidade_produto[i] < 0) // Verificação para números negativos;
                    {
                        printf("A quantidade do produto não pode ser negativa. Tente novamente.\n");
                    }
                }

            } while (quantidade_produto[num_produtos] < 0);
            num_produtos++;

            printf("\033[0;33mProduto adicionado com sucesso!\n");
            printf("\033[0m");

        } else if (opcao == 2) // VISUALIZAÇÃO DE PRODUTOS
        {
            for (int i = 0; i < num_produtos; ++i)
            {
                printf("\n\033[1;32mPRODUTO %d\033[0m:\n", i + 1);
                printf("\033[35mNOME: %s\033[0m\n", nome_produto[i]);
                printf("\033[34mVALOR: R$%.2f\033[0m\n", valor_produto[i]);
                printf("\033[38;5;208mQUANTIDADE: %d\033[0m\n", quantidade_produto[i]);
                printf("\n");
            }
        } else if (opcao == 3)
        {
            // ... código para o caso 3 ...
        } else if (opcao == 4)
        {
            // ... código para o caso 4 ...
        } else if (opcao == 0)
        {
            // ... código para o caso 0 ...
        } else
        {
            printf(" \033[31mEscolha uma opção válida!! ");
            printf("\033[0m");
        }

    } while (opcao != 0);

    return 0;
}