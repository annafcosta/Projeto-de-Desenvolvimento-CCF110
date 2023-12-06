#include "produtos.h"

// MENU
void exibir_menu()
{
    printf("\033[35m");  // Text color (Rosa)
    printf("\n~~~~~~~~~~~~~~~~~~~~| DELÍCIAS DA HELLEN |~~~~~~~~~~~~~~~~~~~~\n");
    printf("\033[0m");   // Resetar a cor para o padrão

    printf("\n\t• Cadastrar novo produto no estoque \033[34m\t| Digite 1 ");
    printf("\033[0m");

    printf("\n\t• Visualizar produtos no estoque \033[34m\t| Digite 2 ");
    printf("\033[0m");

    printf("\n\t• Cadastrar nova venda \033[34m\t\t\t| Digite 3 ");
    printf("\033[0m");

    printf("\n\t• Listar vendas \033[34m\t\t\t| Digite 4 ");
    printf("\033[0m");

    printf("\n\t• Sair \033[34m\t\t\t\t\t| Digite 0\n");
    printf("\033[0m");
}

// CADASTRO DE PRODUTOS:
void cadastrar_produtos(Cadastro_produto *produtos, int max_produto, int *num_produtos)
{

    int quantidade_desejada;

    do {
        printf("\nInforme a quantidade de produtos que deseja cadastrar: ");
        scanf("%d", &quantidade_desejada);

        if (quantidade_desejada < 0) {
        printf("\033[0;31m\nA quantidade não pode ser negativa. Por favor, insira uma quantidade válida.\033[0m\n");
        }

    } while (quantidade_desejada < 0);

    // Verificação para garantir que qunatidade desejada seja menor que MAX_PRODUTO
    if (quantidade_desejada > max_produto) {
        printf("\033[0;31m\nA quantidade desejada é maior do que o máximo permitido.\033[0m\n");
        quantidade_desejada = max_produto;
    }

    if (FLAG_TESTE == 0)
    {
        for (int i = 0; i < quantidade_desejada; i++)
        {
            printf("\nInforme o nome do produto %d: ", i + 1);
            getchar(); // Consumir a nova linha pendente
            fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
            produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';


            do
            {
                printf("Informe o código do produto %d: ", i + 1);
                scanf("%d", &produtos[i].codigo);

                if (produtos[i].codigo < 0){
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
        }

        *num_produtos = quantidade_desejada;

        printf("\033[0;33m\nProdutos cadastrados com sucesso!\n");
        printf("\033[0m");
    }
    
    else
    {
        // Se FLAG_TESTE for 1, os valores serão automaticamente definidos
        for (int i = 0; i < quantidade_desejada; i++)
        {
            sprintf(produtos[i].nome, "Produto %d", i + 1);
            produtos[i].codigo = i + 1001;
            produtos[i].valor = 10.0 + i;
            produtos[i].quantidade = 10 + i;
        }

        *num_produtos = quantidade_desejada;

        printf("\033[0;33m\nProdutos cadastrados com sucesso!\n");
        printf("\033[0m");
    }
}

// VISUALIZAR PRODUTOS
void visualizar_produtos(Cadastro_produto *produtos, int num_produtos)
{
    printf("\n~~~~~~~~~~~~~~~ PRODUTOS CADASTRADOS ~~~~~~~~~~~~~~~\n");

    if (FLAG_TESTE == 1)
    {

        for (int i = 0; i < num_produtos; ++i)
        {
            printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
            printf("\033[35mNOME       \033[0m| %s\n", produtos[i].nome);
            printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
            printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
            printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
            printf("\n");
        }
    } else
    {
        for (int i = 0; i < num_produtos; ++i)
        {
            printf("\n\033[1;32mPRODUTO %d \033[0m\n", i + 1);
            printf("\033[35mNOME       \033[0m| %s\n", produtos[i].nome);
            printf("\033[34mCÓDIGO     \033[0m| %d\n", produtos[i].codigo);
            printf("\033[31mVALOR      \033[0m| R$ %.2f\n", produtos[i].valor);
            printf("\033[38;5;208mQUANTIDADE \033[0m| %d\n", produtos[i].quantidade);
            printf("\n");
        }
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
