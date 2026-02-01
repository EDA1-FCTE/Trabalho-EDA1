/*  Aquivo cabeçalho com definição da struct PRODUTO e declarações das
*   funções de CRUD relacionadas à struct produto:
*   CADASTRAR PRODUTO, BUSCAR PRODUTO, LISTAR PRODUTOS, REMOVER PRODUTOS, EDITAR PRODUTOS
*
*/

#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct produto
{
    char nome[100];
    int codigo;
    float preco;
    int quantidade;
    struct produto* prox;
} produto;

produto* cria_lista_produtos();

produto* cadastrar_produto(produto* head);

void listar_produtos(produto* head);

produto* buscar_produto(produto* head, int codigo);

//editar

//remover


#endif