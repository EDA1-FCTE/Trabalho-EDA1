#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "produto.h"

cliente* cria_lista_clientes(){
    cliente *head;
    head = malloc(sizeof(cliente));
    head->prox = NULL;
    return head;
}

void cadastrar_cliente(cliente* head){
    cliente* novo_cliente = (cliente*) malloc(sizeof (cliente));
    int validaCPF = 0;

    if (novo_cliente == NULL){
        printf("Não foi possível alocar memória.\n");
        return;
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

    novo_cliente->carrinho_do_cliente = NULL;

    novo_cliente->prox = head->prox;

    head->prox = novo_cliente; //Sempre coloca o novo cliente no inicio da lista.

    printf("Cadastro finalizado!\n");

}

void listar_clientes(cliente* head){
    cliente* cliente_atual = head->prox;

    printf("\n=== LISTA DE CLIENTES ===\n");

    while (cliente_atual != NULL){

        printf("Nome: %s | CPF: %s \n", cliente_atual->nome, cliente_atual->CPF);
        
        cliente_atual= cliente_atual->prox;
    }
    printf("========================\n");

}

cliente* buscar_clientes(cliente* head, char* cpf_desejado){
    cliente* cliente_atual = head;
    
    if (cliente_atual == NULL){
        return NULL;
    }
    if (strcmp(cliente_atual->CPF, cpf_desejado) == 0){
        return cliente_atual;
    }
    return buscar_clientes(cliente_atual->prox, cpf_desejado);
}


/* int main(){
    
} */