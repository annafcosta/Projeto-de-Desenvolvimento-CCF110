#include <stdio.h>

int main()
{
    int max_produto;

    printf("Insira a quantidade máxima de produtos produzidos nesse mês: ");
    scanf("%d", &max_produto);

    // Declarando os vetores para armazenar as informações dos produtos:
    char nome_produto[max_produto][50];
    float valor_produto[max_produto];
    int qtd_produto[max_produto];
    int codigo_produto[max_produto];
    int num_produtos = 0;

    for (int i = 0; i < max_produto; ++i)
    {
        if (num_produtos < max_produto)
        {
            // Código do produto é automaticamente atribuído:
            int codigo = num_produtos + 1;

            printf("Informe o nome do produto: ");
            scanf("%s", nome_produto[num_produtos]);
            printf("Informe o preço do produto: ");
            scanf("%f", &valor_produto[num_produtos]);
            printf("Informe a quantidade em estoque: ");
            scanf("%d", &qtd_produto[num_produtos]);

            // Atribuir o código do produto:

            codigo_produto[num_produtos] = codigo;

            num_produtos++;
            printf("Produto adicionado com sucesso! Código do produto: %d\n", codigo);
        } else
        {
            printf("Limite de produtos atingido!\n");
        }
    }

    // REGISTRO DE VENDAS:

    int max_vendas;

    printf("Insira a quantidade máxima de produtos a serem vendidos nesse mês: ");
    scanf("%d", &max_vendas);

    // Declarando as variáveis para registrar as vendas:

    int nome_vendidos[max_vendas];
    int qtd_vendidas[max_vendas];
    float totalVenda[max_vendas];
    int num_vendas = 0;


    return  0;
}
