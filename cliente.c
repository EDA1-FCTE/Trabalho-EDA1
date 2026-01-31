#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "produto.h"

cliente* cria_lista_clientes(){
    return NULL;
}

cliente* cadastrar_cliente(cliente* head){
    cliente* novo_cliente = (cliente*) malloc(sizeof (cliente));
    int validaCPF = 0;

    if (novo_cliente == NULL){
        printf("Não foi possível alocar memória.\n");
        return head;
    }

    printf("\n=== Cadastro Novo ===\n");

    while(!validaCPF){
    printf("Digite o CPF (Apenas numeros):\n");
    scanf(" %[^\n]", novo_cliente->CPF);

    if (strlen (novo_cliente->CPF) != 11){
        printf("O CPF deve conter apenas 11 digitos!\n");

    }

    else {

        int somente_numeros = 1;

        for (int i =0; i < 11; i++){
            if (!isdigit(novo_cliente -> CPF[i])){
                somente_numeros = 0;
                break;
            }
        }

        if (somente_numeros) {
            validaCPF = 1;
        }
        else{
            printf("O CPF deve conter apenas numeros, sem pontos ou tracos.\n");
        }
    }
    }

    printf("Digite o nome (Máximo de 100 caracteres):\n");
    scanf(" %[^\n]", novo_cliente->nome);

    printf("Digite o e-mail:\n");
    scanf(" %[^\n]", novo_cliente->email);

    printf("Digite o telefone:\n");
    scanf(" %[^\n]", novo_cliente->telefone);

    printf("Digite a data de nascimento (dd/mm/aaaa):\n");
    scanf(" %[^\n]", novo_cliente->data_de_nascimento);

    novo_cliente->prox = head;

    printf("Cadastro finalizado!\n");

    return novo_cliente;
}

void listar_clientes(cliente* head){
    cliente* cliente_atual = head;

    if(cliente_atual != NULL){
        printf("Nome: %s | CPF: %s \n", cliente_atual->nome, cliente_atual->CPF);
        listar_clientes(cliente_atual->prox);
    }

}

cliente* buscar_clientes(cliente* head, char* cpf_desejado){
    cliente* cliente_atual = head;
    
    if (cliente_atual == NULL){
        return NULL; //se está vazia desde o começo
    }
    if (strcmp(cliente_atual->CPF, cpf_desejado) == 0){
        return cliente_atual; //achou o cpf desejado
    }
    return buscar_clientes(cliente_atual->prox, cpf_desejado);
}


cliente* escolhe_cliente_comprador(cliente* listar_clientes){
    
    char cpf_comprador[15];
    
    printf("Digite o CPF do cliente comprador: ");
    scanf(" %[^\n]", cpf_comprador);

    cliente* cliente_encontrado = buscar_clientes(listar_clientes, cpf_comprador);

    if(cliente_encontrado == NULL){
        printf("\nCliente nao encontrado\n");
    }

    return cliente_encontrado;
}