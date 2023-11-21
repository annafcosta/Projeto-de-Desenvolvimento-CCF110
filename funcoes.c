// CADASTRO DE PRODUTOS:

void cadastrar_produtos(struct cadastro_produto *produtos, int max_produto, int *num_produtos) {
    
    for (int i = 0; i < max_produto; i++) {
        printf("\nInforme o nome do produto %d: ", i + 1);
        getchar(); // Consumir a nova linha pendente
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Informe o código do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);

        printf("Informe o valor do produto %d: ", i + 1);
        scanf("%f", &produtos[i].valor);

        printf("Informe a quantidade em estoque do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }

    *num_produtos = max_produto;

    printf("\033[0;33mProdutos cadastrados com sucesso!\n");
    printf("\033[0m");

}


// CADASTRO DE VENDAS:

// Verificando a validade do código do produto
int verificar_codigo_produto(int codigo, struct cadastro_produto *produtos, int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            return i; // Retorna o índice se o código for válido
        }
    }
    return -1; // Retorna -1 se o código não for válido
}


void processar_venda(struct cadastro_produto *produtos, struct cadastro_venda *vendas,
                    int produto_encontrado, int quantidade_vendida, int *num_vendas) 
{
    atualizar_quantidade_produto(produtos, produto_encontrado, quantidade_vendida);


    vendas[*num_vendas].codigo_produto_vendido = produtos[produto_encontrado].codigo;
    vendas[*num_vendas].quantidade_vendida = quantidade_vendida;
    vendas[*num_vendas].valor_total = produtos[produto_encontrado].valor * quantidade_vendida;

    (*num_vendas)++;

    printf("\033[0;33mVenda registrada com sucesso!\n");
    printf("\033[34mValor da venda: R$ %.2f\n", vendas[*num_vendas - 1].valor_total);
    printf("\033[0m");
}


// Função para cadastrar uma venda
void cadastrar_venda(struct cadastro_produto *produtos, int num_produtos,
                    struct cadastro_venda *vendas, int max_vendas, int *num_vendas) {

    int continuar = 1;

    while (continuar) {
        int codigo_venda;
        int quantidade_vendida;

        printf("\nInforme o código do produto vendido (ou 0 para encerrar): ");
        scanf("%d", &codigo_venda);

        if (codigo_venda == 0) {
            continuar = 0;  
        } else {
            int produto_encontrado = verificar_codigo_produto(codigo_venda, produtos, num_produtos);

            if (produto_encontrado != -1) {
                printf("Informe a quantidade vendida: ");
                scanf("%d", &quantidade_vendida);

                if (quantidade_vendida <= produtos[produto_encontrado].quantidade) {
                    processar_venda(produtos, vendas, produto_encontrado, quantidade_vendida, num_vendas);
                } else {
                    printf("\033[31mQuantidade insuficiente em estoque para realizar a venda.\n");
                    printf("\033[0m");
                }
            } else {
                printf("\033[31mProduto não encontrado. Verifique o código do produto.\n");
                printf("\033[0m");
            }
        }
    }
}

// VISUALIZAR VENDAS:

void visualizar_vendas(struct cadastro_venda *vendas, int num_vendas) {
    if (num_vendas == 0) {
        printf("\033[31mNenhuma venda registrada.\n");
    } else {
        printf("\n\033[1;32mVENDAS REGISTRADAS\033[0m\n");
        for (int i = 0; i < num_vendas; ++i) {
            printf("\033[35mCÓDIGO DO PRODUTO VENDIDO\033[0m | %d\n", vendas[i].codigo_produto_vendido);
            printf("\033[34mQUANTIDADE VENDIDA\033[0m        | %d\n", vendas[i].quantidade_vendida);
            printf("\033[38;5;208mVALOR TOTAL DA VENDA\033[0m       | R$ %.2f\n", vendas[i].valor_total);
            printf("\n");
        }
    }
}






