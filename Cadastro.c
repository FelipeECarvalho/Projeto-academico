#include <stdio.h>
#include <stdlib.h>

typedef struct cliente {
    int id;
    char nome[100];
    char email[120];
    char dataNascimento[20];
    char telefone[20];
    char cpf[20];
    char cursoMatriculado[20];
} 
Cliente;

typedef struct funcionario {
    int id;
    char nome[100];
    char email[120];
    char dataNascimento[20];
    char telefone[20];
    char cpf[20];
    char cargo[20];
    char login[100];
    char senha[120];
} 
Funcionario;

void cadastroCliente(Cliente* clientes, int quantidadeClientes) {
    clientes[quantidadeClientes].id = quantidadeClientes + 1;
    printf("--------------+++ CADASTRO DE CLIENTE +++--------------\n\n");
    printf("Criacao de cliente de ID: %d", quantidadeClientes + 1);
    printf("Entre com o nome do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].nome);    
    printf("Entre com o cpf do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].cpf);
    printf("Entre com a data de nascimento do cliente: (dd-mm-aaaa) ");
    scanf("%s", &clientes[quantidadeClientes].dataNascimento);
    printf("Entre com o e-mail do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].email);
    printf("Entre com o telefone do cliente: ");
    scanf("%s", &clientes[quantidadeClientes].telefone);
    printf("Entre com o curso matriculado: ");
    scanf("%s", &clientes[quantidadeClientes].cursoMatriculado);
    system("cls");
    printf("Cliente cadastrado com sucesso!");
    getchar();
    getchar();
}

void consultarCliente(Cliente* clientes, int quantidadeClientes) {
    int id, achou;
    printf("--------------+++ CONSULTA CLIENTE +++--------------\n\n");
    printf("Entre com o id do cliente: ");
    scanf("%d", &id);
    while (id < 0 || id > quantidadeClientes) {
        printf("ID invalido, tente novamente: ");
        scanf("%d", &id);
    }
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id == id) {
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s", clientes[i].cursoMatriculado);
            achou = 1;
        }
    }
    if (achou == 0) {
        printf("Cliente nao encontrado");
        getchar();
        getchar();
    }
    getchar();
    getchar();

}

void excluirCliente(Cliente* clientes, int quantidadeClientes) {
    int id, achou, opcao;
    Cliente clienteNovo;
    printf("--------------+++ EXCLUSÃO CLIENTE +++--------------\n\n");
    printf("Entre com o id do cliente: ");
    scanf("%d", &id);
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id == id) {
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s\n\n", clientes[i].cursoMatriculado);
            achou = 1;
            printf("Deseja realmente excluir o cliente\n0 - Cancelar \n1 - Excluir: ");
            scanf("%d", &opcao);
            while (opcao != 1 && opcao != 0) {
                printf("opcao invalida, tente novamente: ");
                scanf("%d", &opcao);
            }
            if (opcao == 1){
                clientes[i].id = -1;
                printf("Cliente excluido com sucesso!");
                getchar();
                getchar();
            }
        }
    }
    if (achou == 0) {
        printf("Cliente nao encontrado");
        getchar();
        getchar();
    }
}

void consultarClientes(Cliente* clientes, int quantidadeClientes) {
    printf("--------------+++ CONSULTA CLIENTES +++--------------\n\n");
    for (int i = 0; i < quantidadeClientes; i ++) {
        if (clientes[i].id != -1 ) {
            printf("Id cliente: %d\n", clientes[i].id);
            printf("Nome cliente: %s\n", clientes[i].nome);
            printf("Cpf cliente: %s\n", clientes[i].cpf);
            printf("Data de nascimento cliente: %s\n", clientes[i].dataNascimento);
            printf("E-mail cliente: %s\n", clientes[i].email);
            printf("Telefone cliente: %s\n", clientes[i].telefone);
            printf("Curso matriculado: %s\n", clientes[i].cursoMatriculado);
            printf("---------------------------------------------------------\n");
        }
    }
    getchar();
    getchar();
}

void gerenciamentoClientes(Cliente* clientes, Funcionario* funcionarios, int quantidadeClientes, int quantidadeFuncionarios) {
    int opcao;
    do {
        system("cls");
        printf("--------------+++ GERENCIAMENTO DE CLIENTES +++--------------\n\n");
        printf("1 - Cadastrar um cliente\n");
        printf("2 - Consultar cliente\n");
        printf("3 - Consultar todos os clientes\n");
        printf("4 - Excluir cliente\n");
        printf("0 - Voltar ao menu\n\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);

        while (opcao > 4 || opcao < 0) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
        }
        system("cls");
        switch (opcao) {
            case 1:
                cadastroCliente(clientes, quantidadeClientes);
                quantidadeClientes ++;              
                break;
            case 2:
                consultarCliente(clientes, quantidadeClientes);
                break;
            case 3:
                consultarClientes(clientes, quantidadeClientes);
                break;
            case 4:
                excluirCliente(clientes, quantidadeClientes);
                break;
            case 0:
                return;
                break;
        }       
    } while (opcao != 0);
}

void gerenciamentoFuncionario(Cliente* clientesCadastrados, Funcionario* funcionariosCadastrados, int quantidadeCliente, int quantidadeFuncionario) {
    system("cls");
    printf("Gerenciamento Funcionarios");
}

void relatorio(Cliente* clientesCadastrados, Funcionario* funcionariosCadastrados, int quantidadeCliente, int quantidadeFuncionario) {
    printf("--------------+++ RELATORIO +++--------------\n");
    printf("Total de clientes cadastrados: %d\n", clientesCadastrados);
    printf("Total de funcionarios cadastrados: %d\n", funcionariosCadastrados);
}

void menu(Cliente* clientesCadastrados, Funcionario* funcionariosCadastrados, int quantidadeCliente, int quantidadeFuncionario) {
    int opcao;
    do {
        system("cls");
        printf("--------------+++ MENU PRINCIPAL +++--------------\n");
        printf("1 - Gerenciamento de clientes\n");
        printf("2 - Gerenciamento de funcionarios\n");
        printf("3 - Acessar relatorios\n");
        // TODO: adicionar redefinir senha
        printf("0 - Sair\n\n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opcao);
        
        while (opcao > 3 || opcao < 0) {
            printf("Opcao invalida, tente novamente: ");
            scanf("%d", &opcao);
        }

        switch (opcao) {
            case 1:
                gerenciamentoClientes(clientesCadastrados, funcionariosCadastrados, quantidadeCliente, quantidadeFuncionario);
                break;
            case 2:
                gerenciamentoFuncionario(clientesCadastrados, funcionariosCadastrados, quantidadeCliente, quantidadeFuncionario);
                break;
            case 3:
                relatorio(clientesCadastrados, funcionariosCadastrados, quantidadeCliente, quantidadeFuncionario);
                break;     
        }
    } while (opcao != 0);
    return;
}

void main() {
    Cliente clientesCadastrados[1000];
    Funcionario funcionariosCadastrados[1000];
    int quantidadeCliente = 0, quantidadeFuncionario = 0;
    menu(clientesCadastrados, funcionariosCadastrados, quantidadeCliente, quantidadeFuncionario);
}