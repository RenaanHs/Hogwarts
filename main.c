#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
    char cor[11];
    char status[11];
     char adotanteCPF[12];
} Animal;

bool verificaExistenciaCPF(char cpf[]) {
    FILE *cli;
    cli = fopen("clientes.txt", "r");

    if (cli == NULL) {
        printf("Erro na abertura do arquivo de clientes!\n");
        system("pause");
        exit(1);
    }

    Cliente aux;



while (fscanf(cli, "%s%s%d%d/%d/%d", aux.cpf, aux.nome, &aux.idade, &aux.dia, &aux.mes, &aux.ano) != EOF) {
        if (strcmp(aux.cpf, cpf) == 0) {
            fclose(cli);

         return true;  // O CPF foi encontrado
        }
    }

    fclose(cli);
    return false;  // O CPF não foi encontrado
}


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
            printf("\nDigite o seu CPF: ");
            scanf("%s",cl[i].cpf);            
            verificaCPF(cl[i].cpf);
            if (verificaCPF(cl[i].cpf)) {
                printf("CPF invalido e/ou incorreto!\n");
            } else {
                printf("CPF valido!\n");
                }   
            }
            printf("Digite o nome do Cliente: ");      
            scanf("%s",cl[i].nome);
            printf("Digite a idade do cliente: ");
            scanf("%d",&cl[i].idade);            
            printf("Digite sua data de nascimento: \n");
            printf("Dia: ");
            scanf("%i", &cl[i].dia);
            printf("Mes: ");
            scanf("%i", &cl[i].mes);
            printf("Ano: ");
            scanf("%i", &cl[i].ano);
            fprintf(cli, "\n%s\n%s\n%d\n%d/%d/%d\n", cl[i].cpf, cl[i].nome, cl[i].idade, cl[i].dia, cl[i].mes, cl[i].ano);
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

  int i, k;

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
  scanf("%s", cpfDesativar);

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
            printf("%s\n%s\n%d\n%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);         
        printf("Cliente desativado com sucesso!\n");   
        } else {            
          fprintf(temp, "%s\n%s\n%d\n%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
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
  scanf("%s", cpfExcluir);  

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
      if (strcmp(aux.cpf, cpfExcluir) == 0) {
          printf("%s\n%s\n%d\n%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
        printf("Cliente excluido com sucesso!\n");
      } else {            
        fprintf(temp, "%s\n%s\n%d\n%d/%d/%d\n", aux.cpf, aux.nome, aux.idade, aux.dia, aux.mes, aux.ano);
      }
  }

  fclose(cli);
  fclose(temp);

  remove("clientes.txt");
  rename("temp.txt", "clientes.txt");
   
  void clientes();
}
void cadastrarAnimal(){
  int opcao;

  printf("----------------------------------------\n");
  printf("Cadastrando Animais :\n");
  Animal an;

    FILE *ani;
    ani=fopen("animais.txt", "a" );
        if (ani == NULL) {
            printf("Erro na abertura do arquivo !");
            system("pause");
            exit(1);
        }           

      do {
            printf("\n");            
            printf("Digite o codigo animal: ");
            scanf("%i", &an.codigo);
            printf("Digite o nome do animal: ");
            scanf("%s",an.nome);            
            printf("Digite a idade do animal: ");
            scanf("%i", &an.idade);
            printf("Digite a cor do animal: ");          
            scanf("%s",an.cor);                        
            strcpy(an.status, "Ativo");            
            fprintf(ani, "%i\n%s\n%i\n%s\n%s\n", an.codigo,an.nome, an.idade, an.cor, an.status);
            printf("Deseja cadastrar mais um animal?\n1-Sim\n2-Nao\nEscolha: ");
            scanf("%i", &opcao);
        }while(opcao != 2);
        fclose(ani);        
    void animais();
}

int compararPorCodigo(const void *a, const void *b) {
    const Animal *animalA = (const Animal *)a;
    const Animal *animalB = (const Animal *)b;
    return animalA->codigo - animalB->codigo;
}


void listarAnimais() {
    FILE *ani;
    ani = fopen("animais.txt", "r");

    if (ani == NULL) {
        printf("Erro na abertura do arquivo de animais!\n");
        system("pause");
        exit(1);
    }
    Animal aux;
    Animal animais[100];
    int numAnimais = 0;

    
    while (fscanf(ani, "%d%s%d%s%s%s", &aux.codigo, aux.nome, &aux.idade, aux.cor, aux.status, aux.adotanteCPF) != EOF) {
        animais[numAnimais++] = aux;
    }

    
    qsort(animais, numAnimais, sizeof(Animal), compararPorCodigo);

    printf("Listar Animais Ordenados por Código:\n");
    for (int i = 0; i < numAnimais; i++) {
        printf("Codigo: %d\n", animais[i].codigo);
        printf("Nome: %s\n", animais[i].nome);
        printf("Idade: %d\n", animais[i].idade);
        printf("Cor: %s\n", animais[i].cor);
        printf("Status: %s\n", animais[i].status);
        printf("Adotante CPF: %s\n",animais[i].adotanteCPF);
        printf("\n");
    }

    fclose(ani);
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

  while (fscanf(ani, "%d%s%d%s%s", &aux.codigo, aux.nome, &aux.idade, aux.cor, aux.status) != EOF) {
      if (aux.codigo != codigo) {
        fprintf(temp, "%i\n%s\n%i\n%s\n%s\n", aux.codigo,aux.nome, aux.idade, aux.cor, aux.status);
      }
  }
    fclose(ani);
    fclose(temp);

    remove("animais.txt");
    rename("temp.txt", "animais.txt");

    printf("Animal desativado com sucesso!\n");
    void animais();
}
void adotarAnimal() {
  int codigo;
  char cpfAdotante[12];
  
 
  printf("----------------------------------------\n");
  printf("Digite o codigo do animal a ser adotado: ");
  scanf("%d", &codigo);
  printf("Digite o CPF do adotante: ");
  scanf("%s", cpfAdotante);
  verificaCPF(cpfAdotante);
  if (!verificaExistenciaCPF(cpfAdotante)) {
      printf("CPF do adotante não encontrado no cadastro de clientes.\n");
    printf("Redirecionando para o cadastro de clientes...\n");
    cadastrarCliente();
    adotarAnimal();
      return ;
  } else {
      printf("CPF valido!\n");
  }
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

  while (fscanf(ani, "%d%s%d%s%s", &aux.codigo, aux.nome, &aux.idade, aux.cor, aux.status) != EOF) {
      if (aux.codigo == codigo && strcmp(aux.status, "Ativo") == 0) {
          strcpy(aux.status, "Adotado");
          strcpy(aux.adotanteCPF, cpfAdotante);
      }
      fprintf(temp, "%d\n%s\n%d\n%s\n%s\n%s\n", aux.codigo, aux.nome, aux.idade, aux.cor, aux.status, aux.adotanteCPF);
  }
    fclose(ani);
    fclose(temp);

    remove("animais.txt");
    rename("temp.txt", "animais.txt");
    printf("Animal adotado com sucesso!\n");
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
        printf("6. Retornar ao Menu principal\n");
        printf("7. Sair\n");
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
                 main();
                break;
            case 7:
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
        printf("\n-Escolha uma das opcoes abaixos-\n");
        printf("1. Cadastrar Animal\n");
        printf("2. Listar Animais\n");
        printf("3. Desativar animal\n");
        printf("4. Adotar Animal\n"); 
        printf("5. Retornar ao Menu principal\n");
        printf("6. Sair\n");
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
                 main();
                break;
            case 6:
                // Liberar memória e sair do programa
                exit(0);
            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    }while ((opcao<1) || (opcao>6));
}


int main() {
int escolha;

do{
    printf("\n----Bem vindo----\n");
    printf("\nMenu Principal:\n");
    printf("1-Clientes\n");
    printf("2-Animais\n");
    printf("3-Adocao de Animais\n");
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
