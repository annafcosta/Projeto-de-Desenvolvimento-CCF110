#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cadastros.h"

//Definir a quantidade máxima de produtos que serão cadastrados:
int max_produto = 3;
int max_vendas = 3;

int main()
{
    int opcao;

    struct cadastro_produto produtos[max_produto];
    struct cadastro_venda vendas[max_vendas];
    int num_produtos = 0;
    int num_vendas = 0;

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
        if (opcao == 1) {
            cadastrar_produtos(&produtos, max_produto, &num_produtos);
        }

    // VISUALIZAÇÃO DE PRODUTOS
       //else if (opcao == 2){}

        
    // CADASTRO DE VENDAS:
        else if (opcao == 3) {
            cadastrar_venda(&produtos, &vendas, num_produtos, max_produto, num_vendas);

        } 
    
    // VISUALIZAR VENDAS
        else if (opcao == 4)
        {
            visualizar_vendas(&vendas, num_vendas);
        } 
        
        else if (opcao == 0)
        {
           
        } 
        
        else
        {
            printf(" \033[31mEscolha uma opção válida!! ");
            printf("\033[0m");
        }

    } while (opcao != 0);

    return 0;
}