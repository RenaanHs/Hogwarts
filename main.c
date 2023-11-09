#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador=0;


typedef struct Cliente {
    char cpf[12];
    char nome[50];
    int idade;
    int dia, mes, ano;
};

struct Animal{
    int codigo;
    char nome[50];
    int idade;
    char cor[10];
};

void cadastrarCliente(){
  int n;
    printf("Cadastrando Clientes :\n");
    printf("Quantos clientes deseja cadastrar: ");
    scanf("%i", &n);

    // Alocação dinâmica
    struct Cliente *cl = (struct Cliente *)malloc(n * sizeof(struct Cliente)); 

    if (cl == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    
    FILE *cli;
    cli=fopen("clientes.txt", "a" );
        if (cli == NULL) {
            printf("Erro na abertura do arquivo !");
            system("pause");
            exit(1);
        }
  

        for (int i = 0; i < n; i++) {
            printf("Digite o seu CPF: \n");
            fflush(stdin);
            fgets(cl[i].cpf, 12, stdin);
            printf("Digite o nome do Cliente: \n");
            fflush(stdin);
            fgets(cl[i].nome, 50, stdin);
            printf("Digite a idade do cliente: \n");
            fflush(stdin);
            scanf("%i", &cl[i].idade);
            printf("Digite sua data de nascimento: \n");
            fflush(stdin);
            scanf("%i%i%i", &cl[i].dia, &cl[i].mes, &cl[i].ano);
            fprintf(cli, "%s\n%s\n%d\n%d/%d/%d\n\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano);
        }

    fclose(cli);
    free(cl); // Libere a memória alocada dinamicamente
  
}
void listarClientes(){
    struct Cliente *cl;

    printf("Listando Clientes :\n");
  
    FILE *cli;
    cli=fopen("clientes.txt", "a" );

    
  
}
void consultarCliente(){
  printf("Consultando Clientes :\n");
  
}
void desativarCliente(){
  printf("Desativando Clientes :\n");
  
}
void excluirCliente(){
  printf("Excluindo Clientes :\n");
  
}
void cadastrarAnimal(){
    int n;
    printf("Cadastrando Animais :\n");
    printf("Quantos animais deseja cadastrar: ");
    scanf("%i", &n);

    struct Animal *an = (struct Animal *)malloc(n * sizeof(struct Animal)); // Alocação dinâmica

    if (an == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    FILE *ani;
    ani=fopen("animais.txt", "a" );
        if (ani == NULL) {
            printf("Erro na abertura do arquivo !");
            system("pause");
            exit(1);
        }

        for (int i = 0; i < n; i++) {
            an[i].codigo = contador;
            printf("Digite o nome do animal: \n");
            fflush(stdin);
            fgets(an[i].nome, 50, stdin);
            printf("Digite a idade do animal: \n");
            scanf("%i", &an[i].idade);
            printf("Digite a cor do animal: \n");
            fflush(stdin);
            fgets(an[i].cor, 10, stdin);
            contador++;
            fwrite(&an[i], sizeof(struct Animal), 1, ani);
        }

    fclose(ani);
    free(an); // Libere a memória alocada dinamicamente
}
void listarAnimais(){
  printf("Listando Animais :\n");
  
}
void desativarAnimal(){
  printf("Desativando Animais :\n");
  
}

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
                consultarCliente();
                break;
            case 4:
                desativarCliente();
                break;
            case 5:
                excluirCliente();
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
  
  
  do {
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
                listarAnimais();
                break;
            case 3:
                desativarAnimal();
                break;
            case 4:
                // Liberar memória e sair do programa
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }while ((opcao<1) || (opcao>4));
}


int main() {
int escolha;

do{
    printf("----Bem vindo----\n");
    printf("\nMenu Principal:\n");
    printf("1-Clientes\n");
    printf("2-Animais\n");
    printf("Escolha uma opção: ");
    scanf("%i", &escolha);

    if(escolha==1){
    clientes();
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
