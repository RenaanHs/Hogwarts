#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cadastrarCliente(Cliente cl){
    printf("Cadastrando Clientes :\n");

    FILE *cli;
    cli = fopen("cliente.txt", "a");
    
        printf("Digite o seu CPF: ");
        gets(cl.cpf);

  
}