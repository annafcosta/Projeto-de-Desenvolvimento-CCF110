#include "produtos.h"

void ler_arquivo_produtos(Cadastro_produto *produtos)
{
    FILE *arquivo_produto = fopen("../estoque.txt", "r");

    if (arquivo_produto == NULL)
    {
        printf("Erro ao abrir o arquivo 'estoque'!\n");
        return;
    }

    int N;
    fscanf(arquivo_produto, "%d", &N);


    for (int i = 0; i < N; i++)
    {
        if (!fscanf(arquivo_produto, "%s %f %d %d", produtos[i].nome, &produtos[i].valor, &produtos[i].codigo,
                    &produtos[i].quantidade))
        {
            printf("Deu erro");
        }
    }

    fclose(arquivo_produto);
}