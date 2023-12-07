#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// 0 para adicionar as informações manualmente e 1 para o processo automático
#define FLAG_TESTE 0

#define MAX_VENDAS 50
#define MAX_PRODUTO 50

// Definir a struct para representar um produto
typedef struct
{
    char nome[50];
    float valor;
    int codigo;
    int quantidade;
} Cadastro_produto;

//Cabeçalho das Funções
void exibir_menu();

void cadastrar_produtos(Cadastro_produto *produtos, int max_produto, int *num_produtos);

void visualizar_produtos(Cadastro_produto *produtos, int num_produtos);

#endif
