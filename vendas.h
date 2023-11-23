#ifndef VENDAS_H
#define VENDAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produtos.h"

// Definir a struct para representar uma venda
typedef struct
{
    int codigo_produto_vendido;
    int quantidade_vendida;
    float valor_total;
} Cadastro_venda;

//Cabeçalho das Funções

int verificar_codigo_produto(int codigo, Cadastro_produto *produtos, int num_produtos);

void atualizar_quantidade_produto(Cadastro_produto *produtos, int indice, int quantidade);

void processar_venda(Cadastro_produto *produtos, Cadastro_venda *vendas,
                     int produto_encontrado, int quantidade_vendida, int *num_vendas);

void cadastrar_venda(Cadastro_produto *produtos, int num_produtos,
                     Cadastro_venda *vendas, int maxvendas, int *num_vendas);

void visualizar_vendas(Cadastro_venda *vendas, int num_vendas);

#endif