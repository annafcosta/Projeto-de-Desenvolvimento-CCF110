#include "produtos.h"

// MENU
void exibir_menu()
{
    printf("\033[35m");  // Text color (Rosa)
    printf("\n~~~~~~~~~~~~~~~~~~~~| DELÍCIAS DA HELLEN |~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\033[0m");   // Resetar a cor para o padrão
<<<<<<< HEAD

    printf("\n• Cadastrar novo produto no estoque \033[34m\t\t| Digite 1 ");
    printf("\033[0m");

    printf("\n\n• Visualizar produtos em estoque \033[34m\t\t| Digite 2 ");

    printf("\033[0m");

    printf("\n\n• Cadastrar nova venda \033[34m\t\t\t\t| Digite 3 ");
    printf("\033[0m");

    printf("\n\n• Listar vendas \033[34m\t\t\t\t| Digite 4 ");
    printf("\033[0m");

    printf("\n\n• Salvar vendas em um arquivo \033[34m\t\t\t| Digite 5 ");
=======
    
    printf("\n\t• Cadastrar produto no estoque de maneira manual \033[34m| Digite 1 ");
    printf("\033[0m");

    printf("\n\t• Visualizar produtos cadastrados manualmente no estoque \033[34m| Digite 2");
    printf("\033[0m");

    printf("\n\t• Cadastrar produtos por arquivo \033[34m\t| Digite 3 ");
    printf("\033[0m");

    printf("\n\t• Cadastrar nova venda \033[34m\t\t\t| Digite 4 ");
    printf("\033[0m");

    printf("\n\t• Listar vendas \033[34m\t\t\t| Digite 5 ");
    printf("\033[0m");

    printf("\n\t• Salvar vendas em um arquivo \033[34m\t\t| Digite 6 ");
>>>>>>> origin/main
    printf("\033[0m");

    printf("\n\n• Sair \033[34m\t\t\t\t\t\t| Digite 0\n");
    printf("\033[0m");
}

// CADASTRO DE PRODUTOS:
void cadastrar_produtos(Cadastro_produto *produtos, int *num_produtos, int max_produto)
{
    if (FLAG_TESTE == 0)
    {
        for (int i = 0; i < max_produto; i++)
        {
            printf("\nInforme o nome do produto %d: ", i + 1);
            getchar(); // Consumir a nova linha pendente
            fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
            produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

            do
            {
                printf("Informe o código do produto %d: ", i + 1);
                scanf("%d", &produtos[i].codigo);

                if (produtos[i].codigo < 0)
                {
                    printf("\033[0;31m\nO valor não pode ser negativo! Por favor, insira um valor válido.\033[0m\n");
                }

            } while (produtos[i].valor < 0); // Verificação para a entrada de negativos

            do
            {
                printf("Informe o valor do produto %d: ", i + 1);
                scanf("%f", &produtos[i].valor);

                if (produtos[i].valor < 0)
                {
                    printf("\033[0;31m\nO valor não pode ser negativo. Por favor, insira um valor válido.\033[0m\n");
                }
            } while (produtos[i].valor < 0);

            do
            {
                printf("Informe a quantidade em estoque do produto %d: ", i + 1);
                scanf("%d", &produtos[i].quantidade);

                if (produtos[i].quantidade < 0)
                {
                    printf("\033[0;31m\nA quantidade não pode ser negativa. Por favor, insira uma quantidade não negativa.\033[0m\n");
                }
            } while (produtos[i].quantidade < 0);

            (*num_produtos)++;
        }

        printf("\033[0;33m\nProdutos cadastrados com sucesso!\n");
        printf("\033[0m");
    }
}

// VISUALIZAR PRODUTOS
void visualizar_produtos(Cadastro_produto *produtos, int *num_produtos)
{
    printf("\n~~~~~~~~~~~~~~~ PRODUTOS CADASTRADOS ~~~~~~~~~~~~~~~\n");

    for (int i = 0; i < num_produtos; ++i)
    {
<<<<<<< HEAD
        printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
        printf("\033[35m\nNOME       \033[0m| %s\n", produtos[i].nome);
        printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
        printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
        printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
        printf("\n");
=======

        for (int i = 0; i < *num_produtos; ++i)
        {
            printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
            printf("\033[35m\nNOME       \033[0m| %s\n", produtos[i].nome);
            printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
            printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
            printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
            printf("\n");
        }
    } else
    {
        for (int i = 0; i < *num_produtos; ++i)
        {
            printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
            printf("\033[35m\nNOME       \033[0m| %s\n", produtos[i].nome);
            printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
            printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
            printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
            printf("\n");
        }
>>>>>>> origin/main
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void ler_arquivo(Cadastro_produto *produtos){
    FILE *arquivo;
    arquivo = fopen("ESTOQUE.txt", "r");

    int N;
    fscanf(arquivo, "%i", &N); // A primeira linha do arquivo contem a quantidade de produtos no arquivo

    for (int i = 0; i < N; i++){
        fscanf(arquivo, "%s %f %i %i", produtos[i].nome, &produtos[i].valor, &produtos[i].codigo, &produtos[i].quantidade);
    }

    visualizar_produtos(produtos, N);
    
    fclose(arquivo);
}
