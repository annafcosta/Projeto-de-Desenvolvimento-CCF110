// Definir a struct para representar um produto
typedef struct
{
    char nome[50];
    float valor;
    int codigo;
    int quantidade;
} Cadastro_produto;

// Definir a struct para representar uma venda
typedef struct
 {
    int codigo_produto_vendido;
    int quantidade_vendida;
    float valor_total;
} Cadastro_venda;

void cadastrar_produtos(Cadastro_produto *produtos, int max_produto, int *num_produtos);

void visualizar_produtos(Cadastro_produto *produtos, int num_produtos);

void atualizar_quantidade_produto(Cadastro_produto *produtos, int indice, int quantidade);

int verificar_codigo_produto(int codigo, Cadastro_produto *produtos, int num_produtos);

void processar_venda(Cadastro_produto *produtos, Cadastro_venda *vendas,
                    int produto_encontrado, int quantidade_vendida, int *num_vendas);

void cadastrar_venda(Cadastro_produto *produtos, int num_produtos,
                    Cadastro_venda *vendas, int max_vendas, int *num_vendas);

void visualizar_vendas(Cadastro_venda *vendas, int num_vendas);
