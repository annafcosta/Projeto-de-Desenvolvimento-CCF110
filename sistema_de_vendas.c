#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int opcao;

    printf("\n\n~~~~~~~~~~~~~~~~~~~~-DELICIAS DA HELLEN-~~~~~~~~~~~~~~~~~~~~\n\n");
    do
    {
        printf("\n\t1 - Cadastrar novo produto no estoque");
        printf("\n\t2 - Visualizar produtos no estoque");
        printf("\n\t3 - Cadastrar nova venda");
        printf("\n\t4 - Listar vendas");
        printf("\n\t0 - Sair");
        printf("\n\n Digite a opcao desejada:");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: break;
            default:
                printf("Escolha uma opcao valida!!! ");
        }
    }while(opcao != 0);


    return  0;
}
