#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cpf[12];
    char nome[50];
    int idade;
    char data_nascimento[10];
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    char cor[10];
} Animal;


void clientes(){
int opcao;
        while (1) {
         printf("-Escolha uma das opcoes abaixos-\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Consultar Cliente\n");
        printf("4. Desativar Cliente\n");
        printf("5. Excluir Cliente\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                consultarCliente(clientes);
                break;
            case 4:
                desativarCliente(clientes);
                break;
            case 5:
                excluirCliente(&clientes);
                break;
            case 6:
                // Liberar memória e sair do programa
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void animais(){
int opcao;
        while (1) {
         printf("-Escolha uma das opcoes abaixos-\n");
        printf("1. Cadastrar Animal\n");
        printf("2. Listar Animais\n");
        printf("3. Desativar animal\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAnimal();
                break;
            case 2:
                listarAnimais(animal);
                break;
            case 3:
                desativarAnimais(animal);
                break;
            case 4:
                // Liberar memória e sair do programa
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void cadastrarCliente(Cliente *cl){

}
void listarClientes(Cliente *cl, int numClientes){

}
void consultarCliente(Cliente *clientes){

}
void desativarCliente(Cliente *clientes){

}
void excluirCliente(Cliente *clientes){

}
void cadastrarAnimal(){

}
void listarAnimais(){

}
void desativarAnimal(){

}

int main() {
int  escolha;

FILE *cli;
cli=fopen("clientes.txt", "w" );
struct Cliente*cl;

cl=(struct cliente*)malloc(100 * sizeof(struct cliente));

do{
    printf("----Bem vindo----\n");
    printf("\nMenu Principal:\n");
    printf("1-Clientes\n");
    printf("2-Animais");
    scanf("%i", &escolha);

    if(escolha==1){
    clientes(cl);
    }
    else if(escolha==2){
    animais();
    }
    else{
    printf("Opcao invalida, tente novamente");
    }
}while(escolha < 1 || escolha > 2);

    return 0;
}
