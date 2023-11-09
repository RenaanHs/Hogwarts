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
            fprintf(cli, "%s\n%s\n%d\n%d/%d/%d\n\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano);
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

    cli=fopen("clientes.txt", "a" );

        printf("Listar Clientes :\n");
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
        }
        
    fclose (cli);
    free(cl);
}
void consultarCliente(){
  char cpfConsulta[12];
    printf("Digite o CPF do cliente que deseja consultar: ");
    fflush(stdin);
    fgets(cpfConsulta, 12, stdin);

    FILE *cli;
    cli = fopen("clientes.txt", "r");

    if (cli == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    struct Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfConsulta) == 0) {
            printf("CPF: %s\n", aux.cpf);
            printf("Nome: %s", aux.nome);
            printf("Idade: %d\n", aux.idade);
            printf("Data de Nascimento: %d/%d/%d\n", aux.dia, aux.mes, aux.ano);
            fclose(cli);
            return;
        }
    }

    printf("Cliente não encontrado!\n");
    fclose(cli);
  
}
void desativarCliente(){
  char cpfDesativar[12];
    printf("Digite o CPF do cliente que deseja desativar: ");
    fflush(stdin);
    fgets(cpfDesativar, 12, stdin);

    FILE *cli;
    FILE *temp;
    cli = fopen("clientes.txt", "r");
    temp = fopen("temp.txt", "w");

    if (cli == NULL || temp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    struct Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfDesativar) == 0) {
            fprintf(temp, "%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
            printf("Cliente desativado com sucesso!\n");
        } else {
            fprintf(temp, "%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
        }
    }

    fclose(cli);
    fclose(temp);

    remove("clientes.txt");
    rename("temp.txt", "clientes.txt");
  
}
void excluirCliente(){
  char cpfExcluir[12];
    printf("Digite o CPF do cliente que deseja excluir: ");
    fflush(stdin);
    fgets(cpfExcluir, 12, stdin);

    FILE *cli;
    FILE *temp;
    cli = fopen("clientes.txt", "r");
    temp = fopen("temp.txt", "w");

    if (cli == NULL || temp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    struct Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfExcluir) != 0) {
            fprintf(temp, "%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
        }
    }

    fclose(cli);
    fclose(temp);

    remove("clientes.txt");
    rename("temp.txt", "clientes.txt");

    printf("Cliente excluído com sucesso!\n");
  
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
  int n;
    printf("Quantos animais deseja listar: ");
    scanf("%i", &n);

    struct Animal *an = (struct Animal *)malloc(n * sizeof(struct Animal));

    FILE *ani;
    ani = fopen("animais.txt", "r");
    if (ani == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    printf("Listar Animais:\n");
    for (int i = 0; i < n; i++) {
        fread(&an[i], sizeof(struct Animal), 1, ani);
        printf("Código: %d\n", an[i].codigo);
        printf("Nome: %s", an[i].nome);
        printf("Idade: %d\n", an[i].idade);
        printf("Cor: %s", an[i].cor);
        printf("\n");
    }

    fclose(ani);
    free(an);
  
}
void desativarAnimal(){
  int codigo;
    printf("Digite o código do animal a ser desativado: ");
    scanf("%d", &codigo);

    FILE *ani;
    FILE *temp;
    ani = fopen("animais.txt", "r");
    temp = fopen("temp.txt", "w");

    if (ani == NULL || temp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    struct Animal aux;

    while (fread(&aux, sizeof(struct Animal), 1, ani)) {
        if (aux.codigo != codigo) {
            fwrite(&aux, sizeof(struct Animal), 1, temp);
        }
    }

    fclose(ani);
    fclose(temp);

    remove("animais.txt");
    rename("temp.txt", "animais.txt");

    printf("Animal desativado com sucesso!\n");

  
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