#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"

produto* cria_lista_produtos(){
    return NULL;
}

produto* cadastrar_produto(produto* head){
    int codigo;
    produto* novo_produto = (produto*) malloc(sizeof (produto));
    
    // Verifica se o produto já existe
    if (buscar_produto(head, codigo) != NULL) 
    {
        printf("Erro: Ja existe um produto com este codigo.\n");
        return head;
    }
    produto* novo_produto = (produto*) malloc(sizeof (produto));
    
    if(novo_produto == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        return head;
    }

    printf("\n=== Cadastro de Novo Produto ===\n");

    printf("Digite o codigo do produto(Apenas numeros):\n");
    scanf("%d", &novo_produto->codigo);

    printf("Digite o nome do produto: \n");
    scanf(" %[^\n]", novo_produto->nome);

    printf("Digite o preco do produto: \n");
    scanf(" %.2f", &novo_produto->preco);

    printf("Digite a quantidade: \n");
    scanf("%d", &novo_produto->quantidade);

    novo_produto -> prox = head;

    printf("Cadastro finalizado!\n");

    return novo_produto;
}

void listar_produtos(produto* head){
    produto* produto_atual = head;

    if (produto_atual != NULL){
        printf("Nome: %s | Codigo: %d | Preco: R$: %.2f \n", produto_atual->nome, produto_atual->codigo, produto_atual->preco);
        listar_produtos(produto_atual-> prox);
    }
}

produto* buscar_produto(produto* head, int codigo){
    produto* produto_atual = head;
    while (produto_atual != NULL)
    {
        if(produto_atual->codigo == codigo){
            return produto_atual;
        }
        else produto_atual= produto_atual->prox;
    }
    return NULL;
}
