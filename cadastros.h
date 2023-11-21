// Definição das Structs

// Definir a struct para representar um produto
struct cadastro_produto {
    char nome[50];
    float valor;
    int codigo;
    int quantidade;
};

// Definir a struct para representar uma venda
struct cadastro_venda {
    int codigo_produto_vendido;
    int quantidade_vendida;
    float valor_total;
};

void cadastrar_produtos(struct cadastro_produto *produtos, int max_produto, int *num_produtos);

int verificar_codigo_produto(int codigo, struct cadastro_produto *produtos, int num_produtos);

void processar_venda(struct cadastro_produto *produtos, struct cadastro_venda *vendas,
                    int produto_encontrado, int quantidade_vendida, int *num_vendas);

void cadastrar_venda(struct cadastro_produto *produtos, int num_produtos,
                    struct cadastro_venda *vendas, int max_vendas, int *num_vendas);

void visualizar_vendas(struct cadastro_venda *vendas, int num_vendas);
