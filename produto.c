#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"

produto* cria_lista_produtos(){
    return NULL;
}

produto* cadastrar_produto(produto* head){

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

    return head;
}
