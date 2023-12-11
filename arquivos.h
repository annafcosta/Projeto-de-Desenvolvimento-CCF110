#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "produtos.h"
#include "vendas.h"

void ler_arquivo_produtos(Cadastro_produto *produtos, int *numero_de_produtos);

void salvar_vendas_em_arquivo(Cadastro_venda *vendas, int num_vendas, Cadastro_produto *produtos, 
                                int num_produtos);

#endif