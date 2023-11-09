#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cpf[12];
    char nome[50];
    int idade;
    int dia, mes, ano;  
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    char cor[10];
    char raça[50];
} Animal;

void cadastrarClientes(){
  char cpf[12];
  char nome[50];
  int idade;
  int dia, mes, ano;  
  FILE *cli;
  cli=fopen("clientes.txt", "a" );
  if (cli == NULL) {
     printf("Erro na abertura do arquivo !");
     system("pause");
     exit(1);
  }
  
  printf("Cadastrando Clientes :\n");

  printf("Digite o seu CPF: ");
  scanf("%s", &cpf);

  printf("Digite seu nome:");
  scanf("%s", &nome);

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  printf("Digite sua data de nascimento");
  printf("\nDia :");
  scanf("%d", &dia);
  printf("Mês :");
  scanf("%d", &mes);
  printf("Ano :");
  scanf("%d", &ano);

  fprintf(cli, "%s-%s-%d-%d/%d/%d\n", &cpf, &nome, idade, dia, mes, ano);
  fclose (cli);
}

void listarClientes(){
    char cpf[12];
    char nome[50];
    int idade;
    int dia, mes, ano;  
    FILE *cli;
    cli=fopen("clientes.txt", "a" );
    if (cli == NULL) {
       printf("Erro na abertura do arquivo !");
       system("pause");
       exit(1);
    }

    printf("Listar Clientes :\n");
    fgets(cpf, 12, cli);
    fgets(nome, 50, cli);    
    fgets(idade, 0, cli);

    printf("Digite sua data de nascimento");
    printf("\nDia :");
    scanf("%d", &dia);
    printf("Mês :");
    scanf("%d", &mes);
    printf("Ano :");
    scanf("%d", &ano);

    printf("%s-%s-%d-%d/%d/%d\n", &cpf, &nome, idade, dia, mes, ano);
    fclose (cli);
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
void listarAnimais(){
  printf("Listando Animais :\n");

}
void desativarAnimal(){
  printf("Desativando Animais :\n");

}

void clientes(){
int opcao;
  while (1) { 
       printf("\n\n");
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
                cadastrarClientes();
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
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void animais(){
int opcao;

  FILE *ani;
  ani=fopen("animais.txt", "a" );
  if (ani == NULL) {
     printf("Erro na abertura do arquivo !");
     system("pause");
     exit(1);
  }
  
  Animal an;

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
                fclose(ani);
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
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
