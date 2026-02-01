/* **************************************************************************
 *
 *
 *
 *************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "produto.h"

void cria_menu_inicial()
{
    printf("\n === MENU INICIAL ===\n");
    printf("(1) Gerenciar Clientes Cadastrados\n");
    printf("(2) Gerenciar Produtos Cadastrados\n");
    printf("(3) Modo Compras\n");
    printf("0. Sair\n");
    printf("Digite o numero referente a sua opcao: \n");
}

void cria_menu_clientes()
{
    printf("\n=== MENU CLIENTES ===\n");
    printf("(1) Cadastrar Cliente\n");
    printf("(2) Listar Todos os Clientes\n");
    printf("(3) Buscar Cliente\n");
    printf("(4) Editar Cadastro de Cliente \n");
    printf("(5) Remover Cliente\n");
    printf("(0) Sair do Menu Clientes\n");
    printf("Digite o numero referente a sua opcao: \n");
}

void cria_menu_produtos()
{
    printf("\n=== MENU PRODUTOS ===\n");
    printf("(1) Cadastrar Produto\n");
    printf("(2) Listar Todos os Produtos \n");
    printf("(3) Buscar Produto \n");
    printf("(4) Editar Dados de um Produto Cadastrado\n");
    printf("(5) Remover Produto\n");
    printf("(0) Sair do Menu Produtos\n");
    printf("Digite o numero referente a sua opcao: \n");
}

void cria_menu_modo_compra()
{
    printf("\n=== MENU COMPRAS ===\n");
}

void cria_menu_carrinho(cliente *referencia)
{
    printf("\n=== CARRINHO %s ===\n", referencia->nome);
    printf("1. Adicionar Produto ao Carrinho\n");
    printf("2. Ver Carrinho\n");
    printf("3. Remover do Carrinho\n");
    printf("0. Voltar ao Menu Principal\n");
    printf("Escolha: ");
}

int main()
{

    cliente *lista_clientes = cria_lista_clientes();
    produto *lista_produtos = cria_lista_produtos();

    int opcao_principal, opcao_secundaria;

    do
    {
        cria_menu_inicial();
        scanf("%d", &opcao_principal);

        switch (opcao_principal)
        {
        case 1: // GERENCIAR CLIENTES CADASTRADOS
            do
            {
                cria_menu_clientes();
                scanf("%d", &opcao_secundaria);

                char aux[15];

                switch (opcao_secundaria)
                {
                case 1: // CADASTRAR CLIENTES
                    lista_clientes = cadastrar_cliente(lista_clientes);
                    break;

                case 2: // LISTAR TODOS OS CLIENTES
                    listar_clientes(lista_clientes);
                    // break;

                case 3: // BUSCAR CLIENTE

                default:
                    printf("Opcao invalida.\n");
                    break;
                }

            } while (opcao_secundaria != 0);

            break;

        case 2: // GERENCIAR PRODUTOS CADASTRADOS
            do
            {
                cria_menu_produtos();
                scanf("%d", &opcao_secundaria);

                switch (opcao_secundaria)
                {
                case 1: // Cadastrar produto
                    lista_produtos = cadastrar_produto(lista_produtos);
                    break;                    
                case 2: // Listar todos os produtos
                    listar_produtos(lista_produtos);
                    break;
                case 3: // Buscar produto
                    // codigo aqui
                    break;
                case 4: // Editar produto
                    // codigo aqui
                    break;
                case 5: // Remover produto
                    // codigo aqui
                    break;

                default:
                    printf("Opcao invalida.\n");
                    break;
                }
            } while (opcao_secundaria != 0);

            break;

        case 3:

            cria_menu_modo_compra();
            cliente *cliente_comprador = escolhe_cliente_comprador(lista_clientes);

            if (cliente_comprador == NULL)
            {
                break;
            }

            do
            {
                cria_menu_carrinho(cliente_comprador);
                scanf("%d", &opcao_secundaria);

                switch (opcao_secundaria)
                {
                case 1:

                    break;

                case 2:

                    break;

                case 3:

                    break;
                }

            } while (opcao_secundaria != 0);
            break;

        case 0:
            /* code */
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opcao_principal != 0);

    return 0;
}