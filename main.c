#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int contador=0;


struct Cliente {
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
bool verificaCPF(char cpf[]) {
    // Verifica se o CPF tem 11 dígitos
    if (strlen(cpf) != 11) {
        return true;
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return true;
        }
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int digito1 = 11 - (soma % 11);
    if (digito1 > 9) {
        digito1 = 0;
    }

    // Verifica o primeiro dígito verificador
    if (digito1 != cpf[9] - '0') {
        return true;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int digito2 = 11 - (soma % 11);
    if (digito2 > 9) {
        digito2 = 0;
    }

    // Verifica o segundo dígito verificador
    if (digito2 != cpf[10] - '0') {
        return true;
    }

    // Se passou por todas as verificações, o CPF é válido
    return false;
}
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
            while (verificaCPF(cl[i].cpf))
            {
                printf("Digite o seu CPF: \n");
            fflush(stdin);
            fgets(cl[i].cpf, 12, stdin);
            verificaCPF(cl[i].cpf);
            if (verificaCPF(cl[i].cpf)) {
                printf("CPF invalido e/ou incorreto!\n");
            } else {
                printf("CPF valido!\n");
                }   
            } 
            
            
            printf("Digite o nome do Cliente: \n");
            fflush(stdin);
            fgets(cl[i].nome, 50, stdin);
            printf("Digite a idade do cliente: \n");
            fflush(stdin);
            scanf("%i", &cl[i].idade);
            printf("Digite sua data de nascimento: \n");
            fflush(stdin);
            scanf("%i%i%i", &cl[i].dia, &cl[i].mes, &cl[i].ano);
            fprintf(cli, "%s, %s, %d, %d/%d/%d\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano);
        }

    fclose(cli);
    free(cl); // Libere a memória alocada dinamicamente
  
}
void listarClientes(){
    int n;
    printf("Quantos clientes deseja listar: ");
    scanf("%i", &n);
    struct Cliente *cl = (struct Cliente *)malloc(n * sizeof(struct Cliente)); 
    FILE *cli;

    cli = fopen("clientes.txt", "r" );

        for (int i = 0; i < n; i++)
        {
            fgets(cl[i].cpf, 12, cli);
            fgets(cl[i].nome, 50, cli);    
            fgets(cl[i].idade, 0, cli);

            printf("Digite sua data de nascimento");
            printf("\nDia :");
            scanf("%d", &cl[i].dia);
            printf("Mês :");
            scanf("%d", &cl[i].mes);
            printf("Ano :");
            scanf("%d", &cl[i].ano);

            fscanf("%s-%s-%d-%d/%d/%d\n", &cl[i].cpf, &cl[i].nome, &cl[i].idade, &cl[i].dia, &cl[i].mes, &cl[i].ano);
            printf("%s-%s-%d-%d/%d/%d\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano, toupper(cl[i].nome));
        }
        
    fclose (cli);
    free(cl);
}
void consultarCliente(){
    struct Cliente cl;
    char cpfC[12];
    char c;
    FILE *cli;
    cli = fopen("Clientes.txt", "r");
    printf("Digite o CPF da pessoa que deseja consultar: \n");
    fflush(stdin);
    fgets(&cpfC, 12, stdin);
    printf("Consultando Clientes:\n");
    while ((c == fgetc(cli)) != EOF)    
    {
        if (c == cpfC)
        {
            for (int i = 0; i < strlen(cpfC); i++)
            {
                c = fgetc(cli);
                if (c == EOF)
                {
                    break;
                }
                if (*(cpfC + 1) != c)
                {
                    break;
                }
            if (i == strlen(cpfC))
            {
                fscanf("%s %s %i %i%i%i", &cl.cpf, &cl.nome, &cl.idade, &cl.dia, &cl.mes, &cl.ano);
                printf("CPF: %s\nNome: %s Idade: %i Data Nascimento: %i/%i/%i", cl.cpf, cl.nome, cl.idade, cl.dia, cl.mes, cl.ano);
            }
            
                
            }
            
        }
        
    }
    
    

  
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
        printf("Falha na alocação de memoria.\n");
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
        printf("Escolha uma opcao: ");
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
                printf("Opcao invalida. Tente novamente.\n");
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
                printf("Opcao invalida. Tente novamente.\n");
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
