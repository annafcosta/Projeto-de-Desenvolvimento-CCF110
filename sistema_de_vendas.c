#include <stdio.h>
#include <string.h>

//Definir a quantidade máxima de produtos que serão cadastrados:
int max_produto = 1;

int main()
{
    int opcao;

    // Declarando as variáveis para os produtos fora do loop:
    char nome_produto[max_produto][50];
    float valor_produto[max_produto];
    int codigo_produto[max_produto];
    int quantidade_produto[max_produto];
    int num_produtos = 0;

    do
    {
        printf("\033[35m");  // Text color (Rosa)
        printf("\n~~~~~~~~~~~~~~~~~~~~| DELÍCIAS DA HELLEN |~~~~~~~~~~~~~~~~~~~~\n");
        printf("\033[0m");   // Resetar a cor para o padrão

        printf("\n\t• Cadastrar novo produto no estoque \033[34m| Digite 1: "); // Código de escape ANSI para cor azul
        printf("\033[0m");

        printf("\n\t• Visualizar produtos no estoque \033[34m\t| Digite 2: ");
        printf("\033[0m");

        printf("\n\t• Cadastrar nova venda \033[34m\t\t\t\t| Digite 3: ");
        printf("\033[0m");

        printf("\n\t• Listar vendas \033[34m\t\t\t\t\t| Digite 4: ");
        printf("\033[0m");

        printf("\n\t• Sair \033[34m\t\t\t\t\t\t\t\t| Digite 0: ");
        printf("\033[0m");

        printf("\n\n => Digite a opção desejada: ");
        scanf("%d", &opcao);

        // CADASTRO DOS PRODUTOS
        if (opcao == 1)
        {
            // NOME DO PRODUTO:
            for (int i = 0; i < max_produto; i++)
            {
                printf("\nInforme o nome do produto %d: ", i + 1);
                getchar(); // Consumir a nova linha pendente
                fgets(nome_produto[i], sizeof(nome_produto[i]) + 1, stdin);
                nome_produto[i][strcspn(nome_produto[i], "\n")] = '\0';
            }

            // CÓDIGO DO PRODUTO:
            do
            {
                for (int i = 0; i < max_produto; i++)
                {
                    printf("Informe o código do produto %d: ", i + 1);
                    scanf("%d", &codigo_produto[i]);

                    if (codigo_produto[i] < 0) // Verificação para números negativos;
                    {
                        printf("O código do produto não pode ser negativo. Tente novamente.\n");
                    }
                }

            } while (codigo_produto[num_produtos] < 0);

            // VALOR DO PRODUTO:
            do
            {
                for (int i = 0; i < max_produto; i++)
                {
                    printf("Informe o valor do produto %d: ", i + 1);
                    scanf("%f", &valor_produto[i]);

                    if (valor_produto[i] < 0)
                    {
                        printf("O valor do produto não pode ser negativo. Tente novamente.\n");
                    }
                }
            } while (valor_produto[num_produtos] < 0);

            // QUANTIDADE DE PRODUTOS
            do
            {
                for (int i = 0; i < max_produto; i++)
                {
                    printf("Informe a quantidade em estoque do produto %d: ", i + 1);
                    scanf("%d", &quantidade_produto[i]);

                    if (quantidade_produto[i] < 0)
                    {
                        printf("A quantidade do produto não pode ser negativa. Tente novamente.\n");
                    }
                }

            } while (quantidade_produto[num_produtos] < 0);
            num_produtos++;

            printf("\033[0;33mProduto adicionado com sucesso!\n");
            printf("\033[0m");

        }

            // VISUALIZAÇÃO DE PRODUTOS
        else if (opcao == 2)
        {
            for (int i = 0; i < max_produto; ++i)
            {
                printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
                printf("\033[35mNOME       \033[0m| %s\n", nome_produto[i]);
                printf("\033[34mCÓDIGO     \033[0m| %d\n", codigo_produto[i]);
                printf("\033[31mVALOR      \033[0m| R$ %.2f\n", valor_produto[i]);
                printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", quantidade_produto[i]);
                printf("\n");
            }
        }

            // CADASTRO DE VENDAS:
        else if (opcao == 3)
        {
            int codigo_venda;
            int quantidade_vendida;

            printf("\nInforme o código do produto vendido: ");
            scanf("%d", &codigo_venda);

            // Procurar o código do produto no array
            int produto_encontrado = -1;
            for (int i = 0; i < num_produtos; i++)
            {
                if (codigo_produto[i] == codigo_venda)
                {
                    produto_encontrado = i;
                    break;
                }
            }

            if (produto_encontrado != -1)
            {
                printf("Informe a quantidade vendida: ");
                scanf("%d", &quantidade_vendida);

                // Verificar se há quantidade suficiente em estoque
                if (quantidade_vendida <= quantidade_produto[produto_encontrado])
                {
                    // Atualizar a quantidade em estoque
                    quantidade_produto[produto_encontrado] -= quantidade_vendida;

                    // Calcular o valor total da venda
                    float valor_total_venda = valor_produto[produto_encontrado] * quantidade_vendida;

                    // Imprimir o valor total da venda
                    printf("\033[0;33mVenda registrada com sucesso!\n");
                    printf("\033[34mValor da venda: R$ %.2f\n", valor_total_venda);
                    printf("\033[0m");
                } else
                {
                    printf("\033[31mQuantidade insuficiente em estoque para realizar a venda.\n");
                    printf("\033[0m");
                }
            } else
            {
                printf("\033[31mProduto não encontrado. Verifique o código do produto.\n");
                printf("\033[0m");
            }
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