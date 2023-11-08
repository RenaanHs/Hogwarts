#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contador=0;

struct Cliente {
    char cpf[12];
    char nome[50];
    int idade;
    char data_nascimento[10];
};

struct Animal{
    int codigo;
    char nome[50];
    int idade;
    char cor[10];
};

void cadastrarCliente(Cliente *cl){
  printf("Cadastrando Clientes :\n");
  
}
void listarClientes(Cliente *cl){
  printf("Listando Clientes :\n");
  
}
void consultarCliente(Cliente *cl){
  printf("Consultando Clientes :\n");
  
}
void desativarCliente(Cliente *cl){
  printf("Desativando Clientes :\n");
  
}
void excluirCliente(Cliente *cl){
  printf("Excluindo Clientes :\n");
  
}
void cadastrarAnimal(Animal *an){
    int n;
    printf("Cadastrando Animais :\n");
    printf("Quantos animais deseja cadastrar: ");
    scanf("%i", &n);

    struct animal *ani = (struct animal *)malloc(n * sizeof(struct animal)); // Alocação dinâmica

    if (ani == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    FILE *an;
    an = fopen("animais.txt", "a");

    for (int i = 0; i < n; i++) {
        ani[i].codigo = contador;
        printf("Digite o nome do animal: \n");
        fflush(stdin);
        fgets(ani[i].nome, 50, stdin);
        printf("Digite a idade do animal: \n");
        scanf("%i", &ani[i].idade);
        printf("Digite a cor do animal: \n");
        fflush(stdin);
        fgets(ani[i].cor, 10, stdin);
        contador++;
        fwrite(&ani[i], sizeof(struct animal), 1, an);
    }

    fclose(an);
    free(ani); // Libere a memória alocada dinamicamente
}
void listarAnimais(Animal *an){
  printf("Listando Animais :\n");
  
}
void desativarAnimal(Animal *an){
  printf("Desativando Animais :\n");
  
}

void clientes(){
int opcao;
        
  FILE *cli;
  cli=fopen("clientes.txt", "a" );
  if (cli == NULL) {
     printf("Erro na abertura do arquivo !");
     system("pause");
     exit(1);
  }
  fclose (cli);
  Cliente cl;
  
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
                cadastrarCliente(&cl);
                break;
            case 2:
                listarClientes(&cl);
                break;
            case 3:
                consultarCliente(&cl);
                break;
            case 4:
                desativarCliente(&cl);
                break;
            case 5:
                excluirCliente(&cl);
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
Animal *an;

an=(struct animal*)malloc(100*sizeof(struct animal));
  FILE *ani;
  ani=fopen("animais.txt", "a" );
  if (ani == NULL) {
     printf("Erro na abertura do arquivo !");
     system("pause");
     exit(1);
  }
  fclose(ani);

  Animal an;
  
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
                cadastrarAnimal(&an);
                break;
            case 2:
                listarAnimais(&an);
                break;
            case 3:
                desativarAnimal(&an);
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
