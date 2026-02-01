#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "produto.h"

cliente* cria_lista_clientes(){
    cliente *head;
    head = malloc(sizeof(cliente));

    if(head != NULL){
        head->prox = NULL;
        head->carrinho_do_cliente = NULL;
    } else {
        printf("ERRO na alocacao de memoria!\n");
        exit(1);
    }
    return head;
}

void cadastrar_cliente(cliente* head){
    cliente* novo_cliente = (cliente*) malloc(sizeof (cliente));
    int validaCPF = 0;

    if (novo_cliente == NULL){
        printf("Nao foi possível alocar memoria.\n");
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

    printf("Digite o nome (Maximo de 100 caracteres):\n");
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
        return NULL; //se está vazia desde o começo
    }
    if (strcmp(cliente_atual->CPF, cpf_desejado) == 0){
        return cliente_atual; //achou o cpf desejado
    }
    return buscar_clientes(cliente_atual->prox, cpf_desejado);
}

void deletar_items_carrinho(item_carrinho* item){

    while (item != NULL){
        item_carrinho* temporario = item;
        item = item->prox;
        free(temporario);
    }
}

void deletar_cliente(cliente* head, char* cpf_para_deletar){
    cliente* cliente_anterior;
    cliente* cliente_atual;
    cliente_anterior = head;
    cliente_atual = head->prox;

    while (cliente_atual != NULL){

        if (strcmp(cliente_atual->CPF,cpf_para_deletar) == 0){

            cliente_anterior->prox = cliente_atual -> prox;

            deletar_items_carrinho(cliente_atual->carrinho_do_cliente);

            free(cliente_atual);
            
            printf("Cliente %s e seu carrinho deletado com sucesso!\n", cpf_para_deletar);
            
            return;
        }

        cliente_anterior = cliente_atual;
        cliente_atual = cliente_atual->prox;

    }
    printf("Cliente nao encontrado.\n");
}

void editar_cliente(cliente* head, char* cpf_para_editar){
    cliente* cliente_atual = head->prox;

    while(cliente_atual != NULL){
        if (strcmp(cliente_atual->CPF, cpf_para_editar) == 0){

            int opcao;

            do{
                printf("\n === EDITANDO CLIENTE === \n");
                printf("(1)Nome: %s\n", cliente_atual->nome);
                printf("(2)Email: %s\n",cliente_atual->email);
                printf("(3)Telefone: %s\n",cliente_atual->telefone);
                printf("(4)Data de nascimento: %s\n",cliente_atual->data_de_nascimento);
                printf("(0)Salvar e sair \n");
                printf("Digite o numero da opcao referente ao campo que deseja alterar. \n");
                scanf(" %d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("Novo nome: \n");
                    scanf(" %[^\n]", cliente_atual->nome);
                    break;

                case 2:
                    printf("Novo email: \n");
                    scanf(" %[^\n]", cliente_atual->email);
                    break;

                case 3:
                    printf("Novo telefone: \n");
                    scanf(" %[^\n]", cliente_atual->telefone);
                    break;

                case 4:
                    printf("Nova data de nascimento(dd/mm/aaa): \n");
                    scanf(" %[^\n]", cliente_atual->data_de_nascimento);
                    break;
                case 0:
                    printf("Dados alterados com sucesso!\n");
                    break;

                default:
                    printf("Operacao invalida.\n");
                    break;
                }
            } while (opcao != 0);

            return;
        }

        cliente_atual= cliente_atual->prox;
    }

    printf("CPF %s nao encontrado.\n", cpf_para_editar);

}

void* free_clientes(cliente* head){
    cliente* cliente_atual = head;
    cliente* prox_cliente;
    while (cliente_atual != NULL)
    {
        prox_cliente= cliente_atual->prox;
        deletar_items_carrinho(cliente_atual->carrinho_do_cliente);
        free(cliente_atual);
        cliente_atual = prox_cliente;
    }
}

cliente* escolhe_cliente_comprador(cliente* head){
    
    char cpf_comprador[15];
    
    printf("Digite o CPF do cliente comprador: ");
    scanf(" %[^\n]", cpf_comprador);

    cliente* cliente_encontrado = buscar_clientes(head, cpf_comprador);

    if(cliente_encontrado == NULL){
        printf("\nCliente nao encontrado\n");
    }

    return cliente_encontrado;
}