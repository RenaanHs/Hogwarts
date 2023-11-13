#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int contador=0;

typedef struct {    
    char cpf[12];
    char nome[51];
    int idade;
    int dia, mes, ano;
} Cliente;

typedef struct {
    int codigo;
    char nome[51];
    int idade;
    char cor[10];
    char status[10];
} Animal;
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
  printf("----------------------------------------\n");
  printf("Cadastrando Clientes :\n");
  printf("Quantos clientes deseja cadastrar: ");
  scanf("%i", &n);

    // Alocação dinâmica
    Cliente *cl = (Cliente *)malloc(n * sizeof(Cliente)); 

    if (cl == NULL) {
        printf("Falha na alocação de memória.\n");
        return;
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
            scanf("%s",cl[i].cpf);            
            verificaCPF(cl[i].cpf);
            if (verificaCPF(cl[i].cpf)) {
                printf("CPF invalido e/ou incorreto!\n");
            } else {
                printf("CPF valido!\n");
                }   
            }
            printf("Digite o nome do Cliente: \n");      
            scanf("%s",cl[i].nome);
            printf("Digite a idade do cliente: \n");
            scanf("%d",&cl[i].idade);            
            printf("Digite sua data de nascimento: \n");
            printf("Dia: \n");
            scanf("%i", &cl[i].dia);
            printf("Mês: \n");
            scanf("%i", &cl[i].mes);
            printf("Ano: \n");
            scanf("%i", &cl[i].ano);
            fprintf(cli, "%s\n%s\n%d\n%d/%d/%d\n\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano);
        }

    fclose(cli);
    free(cl); // Libere a memória alocada dinamicamente
    void clientes();
}

void listarClientes(){    
    FILE *cli;  
    char c, string1[12], string2[12];
    int linhas = 0;
    cli = fopen("clientes.txt", "r");

    if (cli == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    while (fread(&c, sizeof(char), 1, cli)) {
        if (c == '\n') {
            linhas++;
        }
    }

  int i, j, k;

  linhas = linhas / 5;

  Cliente aux;
  char ordenado[linhas][12];
  char troca[12];

  printf("----------------------------------------\n");
  printf("Lista de Clientes Ordenada por CPF :\n");
  printf("----------------------------------------\n");

  rewind(cli);     

  i = 0;

  while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {               
     for(int j =0; j < 12; j++)
     {       
       ordenado[i][j] = aux.cpf[j];
     }    
     i++;
  }  
  for(int i = 0; i < linhas; i++)
  {
      int menor = i;
      for(int j =i+1; j < linhas; j++)
      {
          string1[0] = ordenado[j][0];          
          string1[1] = ordenado[j][1];          
          string1[2] = ordenado[j][2];          
          string1[3] = ordenado[j][3];          
          string1[4] = ordenado[j][4];          
          string1[5] = ordenado[j][5];          
          string1[6] = ordenado[j][6];          
          string1[7] = ordenado[j][7];          
          string1[8] = ordenado[j][8];          
          string1[9] = ordenado[j][9];          
          string1[10] = ordenado[j][10];          
          string1[11] = ordenado[j][11];          

          string2[0] = ordenado[menor][0];
          string2[1] = ordenado[menor][1];
          string2[2] = ordenado[menor][2];
          string2[3] = ordenado[menor][3];
          string2[4] = ordenado[menor][4];
          string2[5] = ordenado[menor][5];
          string2[6] = ordenado[menor][6];
          string2[7] = ordenado[menor][7];
          string2[8] = ordenado[menor][8];
          string2[9] = ordenado[menor][9];
          string2[10] = ordenado[menor][10];
          string2[11] = ordenado[menor][11];

          if (string1[0] < string2[0])
            menor = j;             
      }              
      if (menor != i)
      {           
           for(int j =0; j < 12; j++)
           {          
              troca[j] = ordenado[i][j];
           }
           for(int j =0; j < 12; j++)
           {          
              ordenado[i][j] = ordenado[menor][j];
           }        
           for(int j =0; j < 12; j++)
           {          
              ordenado[menor][j] = troca[j];
           }
      }
  }
  for(k = 0; k < linhas; k++)
  {
    printf("CPF %d:%s\n",k+1,ordenado[k]);    
  }
  printf("----------------------------------------\n");
  fclose (cli);      
  void clientes();
}
void consultarCliente(){
  char cpfConsulta[12];
  printf("----------------------------------------\n");
  printf("Digite o CPF do cliente a consultar: ");

    scanf("%s", cpfConsulta);

    FILE *cli;
    cli = fopen("clientes.txt", "r");

    if (cli == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfConsulta) == 0) {
            printf("CPF: %s\n", aux.cpf);
            printf("Nome: %s\n", aux.nome);
            printf("Idade: %d\n", aux.idade);
            printf("Data de Nascimento: %d/%d/%d\n", aux.dia, aux.mes, aux.ano);
            fclose(cli);
            return;
        }
    }

    printf("Cliente não encontrado!\n");
    fclose(cli);
    void clientes();
}
void desativarCliente(){
  char cpfDesativar[12];
  printf("----------------------------------------\n");
  printf("Digite o CPF do cliente para desativar: ");
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

    Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfDesativar) == 0) {
            printf("%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
            printf("Cliente desativado com sucesso!\n");
        } else {
            fprintf(temp, "%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
        }
    }

    fclose(cli);
    fclose(temp);

    remove("clientes.txt");
    rename("temp.txt", "clientes.txt");
    void clientes();
}
void excluirCliente(){
  char cpfExcluir[12];
  printf("----------------------------------------\n");
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

    Cliente aux;

    while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpfExcluir) != 0) {
            fprintf(temp, "%s%s%d%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
        }
    }

    fclose(cli);
    fclose(temp);

    remove("clientes.txt");
    rename("temp.txt", "clientes.txt");

    printf("Cliente excluido com sucesso!\n");
    void clientes();
}
void cadastrarAnimal(){
  int n;
  printf("----------------------------------------\n");
  printf("Cadastrando Animais :\n");
  printf("Quantos animais deseja cadastrar: ");
  scanf("%i", &n);

  Animal *an = (Animal *)malloc(n * sizeof(Animal));

    if (an == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return;
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
            strcpy(an[i].status, "Ativo");
            contador++;
            fwrite(&an[i], sizeof(Animal), 1, ani);
        }

    fclose(ani);
    free(an); // Libere a memória alocada dinamicamente
    void animais();
}
void listarAnimais(){
  int n;
  printf("----------------------------------------\n");
  printf("Quantos animais deseja listar: ");
  scanf("%i", &n);

  Animal *an = (Animal *)malloc(n * sizeof(Animal));

    FILE *ani;
    ani = fopen("animais.txt", "r");
    if (ani == NULL) {
        printf("Erro na abertura do arquivo!\n");
        system("pause");
        exit(1);
    }

    printf("Listar Animais:\n");
    for (int i = 0; i < n; i++) {
        fread(&an[i], sizeof(Animal), 1, ani);
        printf("Código: %d\n", an[i].codigo);
        printf("Nome: %s", an[i].nome);
        printf("Idade: %d\n", an[i].idade);
        printf("Cor: %s", an[i].cor);
        printf("\n");
    }

    fclose(ani);
    free(an);
    void animais();
}
void desativarAnimal(){
  int codigo;
  printf("----------------------------------------\n");
  printf("Digite o codigo do animal a ser desativado: ");
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

    Animal aux;

    while (fread(&aux, sizeof(Animal), 1, ani)) {
        if (aux.codigo != codigo) {
            fwrite(&aux, sizeof(Animal), 1, temp);
        }
    }

    fclose(ani);
    fclose(temp);

    remove("animais.txt");
    rename("temp.txt", "animais.txt");

    printf("Animal desativado com sucesso!\n");
    void animais();
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

void adotarAnimal() {
  int codigo;
  printf("----------------------------------------\n");
  printf("Digite o codigo do animal a ser adotado: ");
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

    Animal aux;

    while (fread(&aux, sizeof(Animal), 1, ani)) {
        if (aux.codigo != codigo) {
            fwrite(&aux, sizeof(Animal), 1, temp);
        } else {
            printf("Animal adotado com sucesso!\n");
        }
    }

    fclose(ani);
    fclose(temp);

    remove("animais.txt");
    rename("temp.txt", "animais.txt");
    void animais();
}


void animais(){
int opcao;
  do {
        printf("-Escolha uma das opcoes abaixos-\n");
        printf("1. Cadastrar Animal\n");
        printf("2. Listar Animais\n");
        printf("3. Desativar animal\n");
        printf("4. Adotar Animal\n"); 
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
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
          adotarAnimal(); 
          break;
            case 5:
                // Liberar memória e sair do programa
                exit(0);
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    }while ((opcao<1) || (opcao>5));
}


int main() {
int escolha;

do{
    printf("----Bem vindo----\n");
    printf("\nMenu Principal:\n");
    printf("1-Clientes\n");
    printf("2-Animais\n");
    printf("3-Adoção de Animais\n");
    printf("Escolha uma opcao: ");
    scanf("%i", &escolha);

    if(escolha==1){
    clientes();
    }
    else if(escolha==2){
    animais();
    }else if(escolha==3){
    adotarAnimal();
    }
    else{
    printf("Opcao invalida, tente novamente");
    }
}while(escolha < 1 || escolha > 3);

    return 0;
}
