/* **************************************************************************
*   Arquivo cabeçalho com a declaração da struct CLIENTE                    *
*   e definição das funções de CRUD relacionadas ao dado CLIENTE:           *
*   CADASTRAR CLIENTE, LISTAR CLIENTES, BUSCAR CLIENTES (por CPF),          *
*   EDITAR CLIENTE, REMOVER CLIENTE.                                        *
*                                                                           *
*   O arquivo também inclui a struct ITEM DO CARRINHO e as funções          *
*   relacionadas ao carrinho de compras: ADICIONAR AO CARRINHO, LISTAR PRO- *
*   DUTOS E RESPECTIVAS QUANTIDADES, RETIRA PRODUTO.                        *
*************************************************************************** */

/* **************************************************************************
*   Como cada cliente possui um carrinho, é preciso uma lista interna pra   *
*   cada cliente = cada cliente possui um carrinho que precisa ser listado  *
*************************************************************************** */

#ifndef CLIENTE_H
#define CLIENTE_H

struct produto;

typedef struct item_carrinho
{
    int codigo_produto;
    char nome[101];
    float preco;
    int quantidade;

    struct item_carrinho* prox;
} item_carrinho;


typedef struct cliente
{
    char CPF[15];                   // vai receber apenas numeros
    char nome[101];
    char email[100];
    char telefone[20];
    char data_de_nascimento[12];    // formato esperado: dd/mm/aaaa

    item_carrinho* carrinho_do_cliente; //ponteiro p/ lista do carrinho do cliente.

    struct cliente* prox;

} cliente;

cliente* cadastrar_cliente (cliente* head);

cliente* cria_lista_clientes();

void listar_clientes(cliente* head);

cliente* buscar_clientes(cliente* head, char* cpf_desejado);

#endif